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
    const vector<char> operators = {'+', '-', '*', '/'};

    stack<string> operator_stack;
    stack<string> output_stack;

    void read_expression();
    void print_result();
    int define_input();
    void print_help();
    void calculate();

    void infix2suffix();
    bool isOperator(char c);
    bool isDigit(char c);
    void format_input();

public:
    //Init
    Calculator();
};

#endif