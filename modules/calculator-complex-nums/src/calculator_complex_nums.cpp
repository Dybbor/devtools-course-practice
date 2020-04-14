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

ComplexNumber CalculatorComplexNums::GetFirst() {
    return c1;
}

ComplexNumber CalculatorComplexNums::GetSecond() {
    return c2;
}

char CalculatorComplexNums::GetOperation() {
    return operation;
}

bool CalculatorComplexNums::CheckBrackets() {
    int count = 0;
    for (auto i : pattern) {
        if (i == '(') {
            count++;
        } else if (i == ')') {
            count--;
        }
    }
    if (count == 0) {
        bool check = true;
        int pos = 0;
        if (pattern[pos] != '(') {
            check = false;
        } else {
            pos = static_cast <int> (pattern.find('i'));
            if (pattern[pos + 1] != ')') {
                check = false;
            } else if (pattern[pos + 2] != '+' && pattern[pos + 2] != '-'
                && pattern[pos + 2] != '/' && pattern[pos + 2] != '*') {
                check = false;
            } else if (pattern[pos + 3] != '(') {
                check = false;
            } else if (pattern[pattern.size() - 2] != 'i') {
                check = false;
            } else if (pattern[pattern.size() - 1] != ')') {
                check = false;
            }
        }
        return check;
    } else {
        return false;
    }
}

bool CalculatorComplexNums::CheckSymbols() {
    bool check = true;
    for (auto i : pattern) {
        int symbol_code = static_cast <int> (i);
        if (!(symbol_code > 47 && symbol_code < 58)) {
            if (i != '+' && i != '-' && i != '*' && i != '/' &&
                i != '(' && i != ')' && i != '.' && i != 'i') {
                check = false;
                break;
            }
        }
    }
    return check;
}

void CalculatorComplexNums::InitializeFromPattern() {
    char *k, *m, *n;
    c1.setRe(std::strtod(&pattern[1], &k));
    c1.setIm(std::strtod(k, NULL));
    int pos = static_cast <int> (pattern.find('i'));
    operation = pattern[pos + 2];
    m = &pattern[pos + 4];
    c2.setRe(std::strtod(m, &n));
    c2.setIm(std::strtod(n, NULL));
}

ComplexNumber CalculatorComplexNums::Calculate() {
    switch (operation) {
    case '+':
        return c1 + c2;
        break;
    case '-':
        return c1 - c2;
        break;
    case '*':
        return c1 * c2;
        break;
    case '/':
        return c1 / c2;
        break;
    default:
        throw - 2;
        break;
    }
}
