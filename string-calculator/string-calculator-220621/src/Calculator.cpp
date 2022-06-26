//
// Created by Ormir Gjurgjej on 21.06.22.
//

#include <string>
#include <sstream>
#include "Calculator.h"

using namespace std;

int Calculator::add(const string input) {
    stringstream input_stream(input);
    int number;
    int result = 0;
    char delimiter = ',';

    if (input.rfind("//", 0) == 0) {
        delimiter = input.at(2);
        string substring = input.substr(4);
        input_stream = stringstream(substring);
    }

    while (input_stream >> number) {
        result += number;

        if (input_stream.peek() == delimiter) {
            input_stream.ignore();
        }
    }

    return result;
}
