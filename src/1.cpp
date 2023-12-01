/**
 * Benjamin Michael Taylor (bentaylorhk)
 * 2023
 */

#include <ctype.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> NUMBERS = {"zero",  "one",  "two", "three",
                                          "four",  "five", "six", "seven",
                                          "eight", "nine"};

int main(int argc, char *argv[]) {
    std::ifstream file(INPUT_FILENAME);
    std::string line;

    int sum = 0;

    while (std::getline(file, line)) {
        int first;
        int last;
        int firstIndex = line.size();
        int lastIndex = -1;

        // First check for words, then chars, compare indices.
        for (int i = 0; i < NUMBERS.size(); i++) {
            int foundIndex;

            foundIndex = line.find(NUMBERS[i]);
            if (foundIndex != std::string::npos && foundIndex < firstIndex) {
                firstIndex = foundIndex;
                first = i;
            }

            foundIndex = line.find(std::to_string(i));
            if (foundIndex != std::string::npos && foundIndex < firstIndex) {
                firstIndex = foundIndex;
                first = i;
            }

            foundIndex = line.rfind(NUMBERS[i]);
            if (foundIndex != std::string::npos && foundIndex > lastIndex) {
                lastIndex = foundIndex;
                last = i;
            }

            foundIndex = line.rfind(std::to_string(i));
            if (foundIndex != std::string::npos && foundIndex > lastIndex) {
                lastIndex = foundIndex;
                last = i;
            }
        }

        sum += (first * 10) + last;
    }

    printf("%d\n", sum);

    return EXIT_SUCCESS;
}