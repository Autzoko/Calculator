#include "../include/calculator.h"

using namespace std;

Calculator::Calculator()
{
    printf("****************AUTZOKO-CALCULATOR****************\n");
    printf("Input expression to calculate.\n");
    printf("Input \"--exit\" to exit.\n");
    printf("Input \"--h\", \"--H\" or \"--help\" to get help.\n");
    printf("\n");
    while(true)
    {
        printf("\n>>");
        read_expression();

        int state = define_input();

        if(state == -1) break;
        else if(state == 1) print_help();
        else
        {
            printf("\n>>");
            calculate();
            print_result();
        }
    }
}

void Calculator::read_expression()
{
    string tmp;
    cin >> tmp;
    current_input = tmp;
}

void Calculator::print_result()
{
    cout << current_result;

    input_format.clear();
    current_input.clear();
    current_result.clear();
    while(!operator_stack.empty()) operator_stack.pop();
    while(!output_stack.empty()) output_stack.pop();
    while(!calStack.empty()) calStack.pop();
    reverse_polish.clear();
}

int Calculator::define_input()
{
    if(current_input == "--h" || current_input == "--H" || current_input == "--help")
        return 1;
    else if(current_input == "--exit")
        return -1;
    else
        return 0;
}

void Calculator::print_help()
{
    printf("****************HELP LIST****************\n");
    printf("\nDirect instruction:\n");
    printf("--h --H --help\t\tShow this help list.\n");
    printf("--exit\t\t\tExit calculator.\n");
    printf("\nSuffix instruction:\n");
    printf("--v\t\t\tVerbose calculation process.\n");
    printf("--s{file name}\t\tSave calculation expression and result.\n");
    printf("--t\t\t\tTransmit current result to next expression.\n");
    printf("--r{register name}\tSave\\Rename current result as register name.\n");
    printf("\n");
    printf("Need more help or advice visit...\n");
    printf("*****************************************\n");
}

void Calculator::calculate()
{
    format_input();
    infix2suffix();
    reverse(reverse_polish.begin(), reverse_polish.end());
    double tmp_res = 0;
    for(vector<string>::iterator i = reverse_polish.begin(); i != reverse_polish.end(); i++)
    {
        if(isNumber(*i))
        {
            calStack.push(*i);
        }
        else
        {
            if(*i == "+")
            {
                double tmp1 = stod(calStack.top());
                calStack.pop();
                tmp_res = stod(calStack.top());
                calStack.pop();
                tmp_res += tmp1;
                calStack.push(to_string(tmp_res));
            }
            else if(*i == "-")
            {
                double tmp1 = stod(calStack.top());
                calStack.pop();
                tmp_res = stod(calStack.top());
                calStack.pop();
                tmp_res -= tmp1;
                calStack.push(to_string(tmp_res));
            }
            else if(*i == "*")
            {
                double tmp1 = stod(calStack.top());
                calStack.pop();
                tmp_res = stod(calStack.top());
                calStack.pop();
                tmp_res *= tmp1;
                calStack.push(to_string(tmp_res));
            }
            else if(*i == "/")
            {
                double tmp1 = stod(calStack.top());
                calStack.pop();
                tmp_res = stod(calStack.top());
                calStack.pop();
                tmp_res /= tmp1;
                calStack.push(to_string(tmp_res));
            }
            else
            {
                printf("Invalid input.");
            }
        }
    }
    current_result = calStack.top();
}

void Calculator::infix2suffix()
{
    for(vector<string>::iterator i = input_format.begin(); i != input_format.end(); i++)
    {
        if(isNumber(*i))
        {
            output_stack.push(*i);
        }
        else
        {
            while(true)
            {
                if(operator_stack.empty())
                {
                    operator_stack.push(*i);
                    break;
                }
                else
                {
                    string os_top = operator_stack.top();
                    if(isPrime(*i, os_top))
                    {
                        operator_stack.push(*i);
                        break;
                    }
                    else
                    {
                        operator_stack.pop();
                        output_stack.push(os_top);
                        continue;
                    }
                }
            }
        }
    }
    while(!operator_stack.empty())
    {
        output_stack.push(operator_stack.top());
        operator_stack.pop();
    }
    while(!output_stack.empty())
    {
        reverse_polish.push_back(output_stack.top());
        output_stack.pop();
    }
}

bool Calculator::isOperator(char c)
{
    for(vector<char>::iterator i = operators.begin(); i != operators.end(); i++)
        if(*i == c)
            return true;
    return false;
}

bool Calculator::isDigit(char c)
{
    if(c <= '9' && c >= '0')
        return true;
    return false;
}

bool Calculator::isNumber(string s)
{
    for(string::iterator i = s.begin(); i != s.end(); i++)
        if(!isDigit(*i))
            return false;
    return true;
}

void Calculator::format_input()
{
    string tmp;
    for(string::iterator i = current_input.begin(); i != current_input.end(); i++)
    {
        if(isDigit(*i))
        {
            tmp.push_back(*i);
            continue;
        }
        if(isOperator(*i))
        {
            input_format.push_back(tmp);
            tmp.clear();
            tmp.push_back(*i);
            input_format.push_back(tmp);
            tmp.clear();
            continue;
        }
    }
    input_format.push_back(tmp);
}

bool Calculator::isPrime(string in, string top)
{
    if(in == "+" || in == "-")
    {
        if(top == "+" || top == "-")
            return true;
        else
            return false;
    }
    else
    {
        if(top == "+" || top == "-")
            return true;
        else
            return true;
    }
}
