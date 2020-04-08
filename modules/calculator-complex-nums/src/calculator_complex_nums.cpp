// Copyright 2020 Dobrohotov Vitaly

#include <include/calculator_complex_nums.h>

#include <string>

CalculatorComplexNums::CalculatorComplexNums() : pattern("") {}

CalculatorComplexNums::CalculatorComplexNums(std::string _pattern) :
    pattern(_pattern) {}

std::string CalculatorComplexNums::GetPattern() {
    return pattern;
}
