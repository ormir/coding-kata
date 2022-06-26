//
// Created by Ormir Gjurgjej on 26.06.22.
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
    bool hasNegativeNumbers = false;
    string exceptionMessage = "negatives not allowed:";

    if (input.rfind("//", 0) == 0) {
        delimiter = input.at(2);
        string substring = input.substr(4);
        inputStream = stringstream (substring);
    }

    while(inputStream >> number) {
        result += number;

        if (inputStream.peek() == delimiter) {
            inputStream.ignore();
        }

        if (number < 0) {
            hasNegativeNumbers = true;
            exceptionMessage.append(" ");
            exceptionMessage.append(to_string(number));
        }

    }

    if (hasNegativeNumbers)
        throw invalid_argument(exceptionMessage);

    return result;
}
