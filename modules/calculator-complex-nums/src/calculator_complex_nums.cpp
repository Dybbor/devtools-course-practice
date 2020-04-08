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
        "<z1_real> <z1_imaginary>i" + " <operation> "
        "<z2_real> <z2_imaginary>i \n\n" +

        "Where all arguments are double-precision numbers,\n" +
        "and <operation> is one of '+', '-', '*', '/'.\n";
    std::cout << help << std::endl;
}

bool CalculatorComplexNums::CheckPattern() {
    return false;
}