//
// Created by Ormir Gjurgjej on 03.07.22.
//

#include "CalculatorTest.h"
#include "gtest/gtest.h"
#include "Calculator.h"

TEST(calculator, add_0_numbers) {
    Calculator calculator;
    int result = calculator.add("0");
    ASSERT_EQ(result, 0);
}

TEST(calculator, add_1_number) {
    Calculator calculator;
    int result = calculator.add("1");
    ASSERT_EQ(result, 1);
}

TEST(calculator, add_2_numbers) {
    Calculator calculator;
    int result = calculator.add("1,2");
    ASSERT_EQ(result, 3);
}

TEST(calculator, add_10_numbers) {
    Calculator calculator;
    int result = calculator.add("1,1,1,1,1,1,1,1,1,1");
    ASSERT_EQ(result, 10);
}

TEST(calculator, add_newLine) {
    Calculator calculator;
    int result = calculator.add("1,2\n3\n4");
    ASSERT_EQ(result, 10);
}

TEST(calculator, add_delimiter) {
    Calculator calculator;
    int result = calculator.add("//:\n1:2:3");
    ASSERT_EQ(result, 6);
}

TEST(calculator, add_negative) {
    Calculator calculator;

    try {
        calculator.add("1,-2,3,-4");
        FAIL() << "exception not thrown";
    } catch (const std::invalid_argument &exception) {
        ASSERT_STREQ(exception.what(), "negatives not allowed: -2 -4");
    } catch (...) {
        FAIL() << "wrong exception thrown";
    }
}

TEST(calculator, add_ignoreBigNumbers) {
    Calculator calculator;
    int result = calculator.add("1,999,1000,1001,2");
    ASSERT_EQ(result, 2002);
}

TEST(calculator, add_delimiterAnyLength) {
    Calculator calculator;
    int result = calculator.add("//[***]\n1***2***3");
    ASSERT_EQ(result, 6);
}
