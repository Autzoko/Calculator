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
    printf("print result\n");
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
    printf("--rp\t\t\tUse reverse Polish notation.\n");
    printf("--s{file name}\t\tSave calculation expression and result.\n");
    printf("--t\t\t\tTransmit current result to next expression.\n");
    printf("--r{register name}\tSave\\Rename current result as register name.\n");
    printf("\n");
    printf("Need more help or advice visit...\n");
    printf("*****************************************\n");
}

void Calculator::calculate()
{
    printf("calculate\n");
}
