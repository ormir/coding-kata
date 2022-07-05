//
// Created by Ormir Gjurgjej on 05.07.22.
//

#include <sstream>
#include "Calculator.h"

using namespace std;

int Calculator::add(string input) {
    stringstream inputStream(input);
    int number = 0;
    int result = 0;
    char delimiter = ',';
    string longDelimiter = "";
    string exceptionMessage = "negative not allowed";
    bool hasNegatives = false;
    bool hasLongDelimiter;

    if (input.rfind("//", 0) == 0) {
        inputStream.ignore(2);
        inputStream >> delimiter;
    }

    if (delimiter == '[') {
        hasLongDelimiter = true;

        while (inputStream >> delimiter) {
            longDelimiter.push_back(delimiter);

            if (inputStream.peek() == ']') {
                inputStream.ignore();
                break;
            }
        }
    }

    while (inputStream >> number) {
        result += number;

        if (number < 0) {
            hasNegatives = true;
            exceptionMessage.append(" ");
            exceptionMessage.append(to_string(number));
        }

        if (number > 1000)
            result -= number;

        if (inputStream.peek() == delimiter && hasLongDelimiter == false)
            inputStream.ignore();

        if (hasLongDelimiter)
            inputStream.ignore(longDelimiter.size());
    }

    if (hasNegatives)
        throw invalid_argument(exceptionMessage);

    return result;
}
