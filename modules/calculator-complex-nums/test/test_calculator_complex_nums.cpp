// Copyright 2020 Dobrohotov Vitaly

#include <gtest/gtest.h>

#include <string>

#include "include/calculator_complex_nums.h"
#include "include/complex_number.h"

TEST(CalculatorComplexNums, can_create_empty_pattern) {
    // Act
    CalculatorComplexNums c;

    // Assert
    EXPECT_EQ("", c.GetPattern());
}

TEST(CalculatorComplexNums, can_create_pattern) {
    // Arrange
    std::string str = "some";

    // Act
    CalculatorComplexNums c(str);

    // Assert
    EXPECT_EQ("some", c.GetPattern());
}

TEST(CalculatorComplexNums, check_brackets_return_true) {
    // Arrange
    std::string str = "(5+2i)+(2-0i)";
    
    // Act
    CalculatorComplexNums c(str);

    // Assert
    EXPECT_TRUE(c.CheckBrackets());
}

TEST(CalculatorComplexNums, check_brackets_1_return_false) {
    // Arrange
    std::string str = "((5+2i)+(2-0i)";

    // Act
    CalculatorComplexNums c(str);

    // Assert
    EXPECT_FALSE(c.CheckBrackets());
}

TEST(CalculatorComplexNums, check_brackets_2_return_false) {
    // Arrange
    std::string str = "(5+)2i)+(2-0i)";

    // Act
    CalculatorComplexNums c(str);

    // Assert
    EXPECT_FALSE(c.CheckBrackets());
}
