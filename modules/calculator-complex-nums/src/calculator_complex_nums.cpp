// Copyright 2020 Dobrohotov Vitaly

#include <include/calculator_complex_nums.h>

#include <string>
#include <iostream>

CalculatorComplexNums::CalculatorComplexNums() : pattern("") {}

CalculatorComplexNums::CalculatorComplexNums(std::string _pattern) :
    pattern(_pattern) {}

std::string CalculatorComplexNums::GetPattern() {
    return pattern;
}

void CalculatorComplexNums::Help() {
    std::string help = "";
    help = std::string(help) +
        "This is a complex number calculator application.\n" +
        "Please provide arguments in the following format:\n\n" +
        "(<z1_real>+/-<z1_imaginary>i)" + "<operation>"
        "(<z2_real>+/-<z2_imaginary>i) \n\n" +

        "Where all arguments are double-precision numbers,\n" +
        "and <operation> is one of '+', '-', '*', '/'.\n" +
		"If something not exist, write 0\n\n" +
		"Example:\n\n" + "(4.2+5i)+(5.2-3i)\n\n" + 
        "(0-5i)*(3+3.2i)\n";
    std::cout << help << std::endl;
}

void CalculatorComplexNums::SetPattern(std::string _pattern) {
    pattern = _pattern;
}

bool CalculatorComplexNums::CheckBrackets() {
    bool check = true;
    int count = 0;
    for (auto i : pattern) {
        if (i == '(') {
            count++;
        }
        else if (i == ')'){
            count--;
        }
    }
    if (count == 0) {
        int pos = 0;
        if (pattern[pos] != '(') {
            check = false;
        }
        else {
            pos = (int)pattern.find('i');
            if (pattern[pos + 1] != ')') {
                check = false;
            }
            else if (pattern[pos + 3] != '(') {
                check = false;
            }
            else if (pattern[pattern.size() - 1] != ')') {
                check = false;
            }
        }
        return check;
    }
    else {
        return false;
    }
}
