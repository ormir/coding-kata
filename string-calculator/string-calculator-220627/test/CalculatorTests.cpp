//
// Created by Ormir Gjurgjej on 27.06.22.
//

#import "gtest/gtest.h"
#import "Calculator.h"

TEST(calculator, add_0_numbers) {
    Calculator calculator;
    int result = calculator.add("");
    ASSERT_EQ(result, 0);
}

TEST(calculator, add_1_numnber) {
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

TEST(calculator, add_newLines) {
    Calculator calculator;
    int result = calculator.add("1,2\n3\n4");
    ASSERT_EQ(result, 10);
}

TEST(calculator, delimiter) {
    Calculator calculator;
    int result = calculator.add("//:\n1:2:3");
    ASSERT_EQ(result, 6);
}

TEST(calculator, add_negative) {
    Calculator calculator;

    try {
        calculator.add("-1");
        FAIL() << "exception not thrown";
    } catch (const std::invalid_argument & exception) {
        ASSERT_STREQ(exception.what(), "negatives not allowed: -1");
    } catch (...) {
        FAIL() << "wrong exception thrown";
    }
}

TEST(calculator, add_2_negative) {
    Calculator calculator;

    try {
        calculator.add("-1, -2");
        FAIL();
    } catch (const std::invalid_argument & exception) {
        ASSERT_STREQ(exception.what(), "negatives not allowed: -1 -2");
    } catch (...) {
        FAIL();
    }
}