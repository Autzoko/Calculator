#ifndef _CAL_H_
#define _CAL_H_
#include "base.h"

using namespace std;

class Calculator
{
private:
    string current_input;
    string current_result;
    vector<string> input_format;
    int state;
    vector<char> operators = {'+', '-', '*', '/'};

    stack<string> operator_stack;
    stack<string> output_stack;
    vector<string> reverse_polish;
    stack<string> calStack;
    double tmp_result;

    void read_expression();
    void print_result();
    int define_input();
    void print_help();
    void calculate();

    void infix2suffix();
    bool isOperator(char c);
    bool isDigit(char c);
    bool isNumber(string s);
    void format_input();
    bool isPrime(string in, string top);

    bool isAuthorGenius();
public:
    //Init
    Calculator();
};

#endif