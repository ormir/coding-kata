//
// Created by Ormir Gjurgjej on 27.06.22.
//

#include <string>
#include <sstream>
#include "Calculator.h"

using namespace std;

int Calculator::add(string input) {
    stringstream inputStream(input);
    int number = 0;
    int result = 0;
    char delimiter = ',';
    string exceptionMessage("negatives not allowed:");
    bool hasNegative = false;

    if (input.rfind("//", 0) == 0) {
        delimiter = input.at(2);
        inputStream.ignore(4);
    }

    while (inputStream >> number) {
        result += number;

        if (inputStream.peek() == delimiter) {
            inputStream.ignore();
        }

        if (number < 0) {
            hasNegative = true;
            exceptionMessage.append(" ");
            exceptionMessage.append(to_string(number));
        }
    }

    if (hasNegative)
        throw invalid_argument(exceptionMessage);

    return result;
}
