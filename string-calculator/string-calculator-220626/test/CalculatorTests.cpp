//
// Created by Ormir Gjurgjej on 26.06.22.
//

#include "gtest/gtest.h"
#include "Calculator.h"

TEST(calculator, add_1_number) {
    Calculator calculator;
    int result = calculator.add("1");
    ASSERT_EQ(result, 1);
}

TEST(calculator, add_2_numbers) {
    Calculator calculator;
    int result = calculator.add("1,1");
    ASSERT_EQ(result, 2);
}

TEST(calculator, add_no_numbers) {
    Calculator calculator;
    int result = calculator.add("");
    ASSERT_EQ(result, 0);
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
    int result = calculator.add("//;\n1;2;3;4");
    ASSERT_EQ(result, 10);
}

TEST(calculator, add_negative) {
    Calculator calculator;

    try {
        int result = calculator.add("1,2,3,-4");
        FAIL() << "exception not thrown";
    } catch (const std::invalid_argument & exception) {
        SUCCEED();
    } catch (...) {
        FAIL() << "wrong exception thrown";
    }
}

TEST(calculator, add_1_negative) {
    Calculator calculator;

    try {
        int result = calculator.add("-1");
        FAIL() << "exception not thrown";
    } catch (const std::invalid_argument& exception) {
        ASSERT_STREQ(exception.what(), "negatives not allowed: -1");
    } catch (...) {
        FAIL() << "wrong exception thrown";
    }
}

TEST(calculator, add_2_negative) {
    Calculator calculator;

    try {
        int result = calculator.add("-1, -2");
        FAIL() << "exception not thrown";
    } catch (const std::invalid_argument & exception) {
        ASSERT_STREQ(exception.what(), "negatives not allowed: -1 -2");
    } catch (...) {
        FAIL() << "wrong exception thrown";
    }
}
