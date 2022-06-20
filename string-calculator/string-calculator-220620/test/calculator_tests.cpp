//
// Created by Ormir Gjurgjej on 20.06.22.
//

#include "gtest/gtest.h"
#include "calculator.h"

TEST(string_calculator, add_one_number) {
    const int result = add("123");

    ASSERT_EQ(result, 123);
}

TEST(string_calculator, add_two_numbers) {
    const int result = add("1,1");

    ASSERT_EQ(result, 2);
}

TEST(string_calculator, add_no_numberes) {
    const int result = add("");

    ASSERT_EQ(result, 0);
}

TEST(string_calculator, add_10_numberes) {
    const int result = add("1,1,1,1,1,1,1,1,1,1");

    ASSERT_EQ(result, 10);
}

TEST(string_calculator, add_newline) {
    const int result = add("1\n2,3");

    ASSERT_EQ(result, 6);
}

TEST(string_calculator, add_newline_2) {
    const int result = add("1,2\n3\n10");

    ASSERT_EQ(result, 16);
}

TEST(string_calculator, add_delimiter) {
    const int result = add("//;\n1;2");

    ASSERT_EQ(result, 3);
}

TEST(string_calculator, add_negative) {
    try {
        const int result = add("-1, 2, 3");
        FAIL() << "exception not thrown";
    } catch (std::invalid_argument const & err) {
        ASSERT_STREQ(err.what(), "negatives not allowed -1");
    } catch (...) {
        FAIL() << "wrong exception thrown";
    }
}

TEST(string_calculator, add_multiple_negatives) {
    try {
        const int result = add("1,-2,3,4,-6,7,8");
        FAIL() << "exception not thrown";
    } catch (std::invalid_argument const & err) {
        ASSERT_STREQ(err.what(), "negatives not allowed -2 -6");
    } catch (...) {
        FAIL() << "wrong exception thrown";
    }
}