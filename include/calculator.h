#ifndef _CAL_H_
#define _CAL_H_
#include "base.h"

using namespace std;

class Calculator
{
private:
    string current_input;
    string current_result;
    int state;
    const vector<char> operators = {'+', '-', '*', '/'};

    void read_expression();
    void print_result();
    int define_input();
    void print_help();
    void calculate();

public:
    //Init
    Calculator();

    //
};

#endif