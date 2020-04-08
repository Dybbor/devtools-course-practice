// Copyright 2020 Dobrohotov Vitaly

#ifndef MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS
#define MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS

#include <string>

class CalculatorComplexNums {
 private:
	 std::string pattern;
 public:
	 CalculatorComplexNums(std::string _pattern = "");
	 std::string GetPattern();
};

#endif MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS