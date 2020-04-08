#include <include/calculator_complex_nums.h>

CalculatorComplexNums::CalculatorComplexNums(std::string _pattern) {
	pattern = _pattern;
}

std::string CalculatorComplexNums::GetPattern() {
	return pattern;
}