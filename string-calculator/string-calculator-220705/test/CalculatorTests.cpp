//
// Created by Ormir Gjurgjej on 05.07.22.
//

#include "CalculatorTests.h"
#include "Calculator.h"
#include "gtest/gtest.h"

TEST(calculator, add_0_numbers) {
    Calculator calculator;
    int result = calculator.add("");
    ASSERT_EQ(result, 0);
}

TEST(calculator, add_1_number) {
    Calculator calculator;
    int result = calculator.add("1");
    ASSERT_EQ(result, 1);
}

TEST(calculator, add_multiple_numbers) {
    Calculator calculator;
    int result = calculator.add("1,2,3,4");
    ASSERT_EQ(result, 10);
}

TEST(calculator, add_newLine) {
    Calculator calculator;
    int result = calculator.add("1,2\n3\n4");
    ASSERT_EQ(result, 10);
}

TEST(calculator, add_delimter) {
    Calculator calculator;
    int result = calculator.add("//:\n1:2:3");
    ASSERT_EQ(result, 6);
}

TEST(calculator, add_negatives) {
    Calculator calculator;

    try {
        calculator.add("1,-2,3,-4");
        FAIL() << "exception not thrown";
    } catch (const std::invalid_argument &exception) {
        ASSERT_STREQ(exception.what(), "negative not allowed -2 -4");
    } catch (...) {
        FAIL() << "wrong exception";
    }
}

TEST(calculator, add_bigNumbers) {
    Calculator calculator;
    int result = calculator.add("1,999,1000,1001,2");
    ASSERT_EQ(result, 2002);
}

TEST(calculator, add_longDelimter) {
    Calculator calculator;
    int result = calculator.add("//[***]\n1***2***3");
    ASSERT_EQ(result, 6);
}