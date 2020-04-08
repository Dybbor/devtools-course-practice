// Copyright 2020 Dobrohotov Vitaly

#ifndef MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS_H_
#define MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS_H_

#include <string>

#include "include/complex_number.h"

class CalculatorComplexNums {
 private:
    std::string pattern;
    ComplexNumber c1;
    ComplexNumber c2;
 public:
    CalculatorComplexNums();
    explicit CalculatorComplexNums(const std::string _pattern);

    void Help();
    std::string GetPattern();
    void SetPattern(std::string _pattern);
    bool CheckBrackets();
};

#endif  // MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS_H_
