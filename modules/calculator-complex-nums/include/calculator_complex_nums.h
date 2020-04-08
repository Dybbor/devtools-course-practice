// Copyright 2020 Dobrohotov Vitaly

#ifndef MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS_H_
#define MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS_H_

#include <string>

class CalculatorComplexNums {
 private:
    std::string pattern;
 public:
    CalculatorComplexNums();
    CalculatorComplexNums(const std::string _pattern);
    std::string GetPattern();
};

#endif  // MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS_H_
