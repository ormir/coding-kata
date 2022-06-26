//
// Created by Ormir Gjurgjej on 21.06.22.
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
    int result = calculator.add("1,2");
    ASSERT_EQ(result, 3);
}

TEST(calculator, add_10_numbers) {
    Calculator calculator;
    int result = calculator.add("1,1,1,1,1,1,1,1,1,1");
    ASSERT_EQ(result, 10);
}

TEST(calculator, add_new_line) {
    Calculator calculator;
    int result = calculator.add("1,2\n3,4");
    ASSERT_EQ(result, 10);
}

TEST(calculator, add_delimiter) {
    Calculator calculator;
    int result = calculator.add("//;\n1;2;3");
    ASSERT_EQ(result, 6);
}

TEST(calculator, add_negative) {
    Calculator calculator;
    try {
        int result = calculator.add("1,2,-3,4");
    } catch (invalid_argument cont & exception)
}
