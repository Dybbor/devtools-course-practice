// Copyright 2020 Dobrohotov Vitaly

#include <gtest/gtest.h>

#include <string>

#include "include/calculator_complex_nums.h"

TEST(CalculatorComplexNums, can_create_empty_pattern) {
    // Act
    CalculatorComplexNums c;

    // Assert
    EXPECT_EQ("", c.GetPattern());
}

TEST(CalculatorComplexNums, can_create_pattern) {
    // Act
    CalculatorComplexNums c("some");
    
    // Assert
    EXPECT_EQ("some", c.GetPattern());
}
