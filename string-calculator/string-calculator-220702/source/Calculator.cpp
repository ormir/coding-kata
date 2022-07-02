//
// Created by Ormir Gjurgjej on 02.07.22.
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

    string exceptionMessage = "negatives not allowed:";
    bool hasNegatives = false;

    if (input.rfind("//", 0) == 0) {
        inputStream.ignore(2);
        inputStream >> delimiter;
        inputStream.ignore(1);
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

        if (inputStream.peek() == delimiter)
            inputStream.ignore();
    }

    if (hasNegatives)
        throw invalid_argument(exceptionMessage);

    return result;
}
