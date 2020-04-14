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
    bool check = true;
    int count = 0;
    for (auto i : pattern) {
        if (i == '(') {
            count++;
        } else if (i == ')') {
            count--;
        }
    }
    if (count == 0) {
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
    if (!CheckBrackets() && !CheckSymbols()) {
        this -> Help();
    }
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
