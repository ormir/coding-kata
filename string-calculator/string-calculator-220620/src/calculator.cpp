//
// Created by Ormir Gjurgjej on 20.06.22.
//

#include <sstream>
#include <vector>
#include "calculator.h"

int add(std::string input) {
    std::stringstream input_stream(input);
    char delimiter = ',';
    int number, result = 0;
    bool contain_negative_numbers = false;
    std::string exception_string = "negatives not allowed";

    if (input.rfind("//", 0) == 0) {
        delimiter = input.at(2);
        std::string substring = input.substr(4);
        input_stream = std::stringstream(substring);
    }

    while (input_stream >> number) {
        if (number < 0) {
            contain_negative_numbers = true;

            exception_string.append(" ");
            exception_string.append(std::to_string(number));
        }

        result += number;

        if (input_stream.peek() == delimiter)
            input_stream.ignore();
    }

    if (contain_negative_numbers) {
        throw std::invalid_argument(exception_string);
    }

    return result;
}
