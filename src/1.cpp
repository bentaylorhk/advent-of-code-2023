/**
 * Benjamin Michael Taylor (bentaylorhk)
 * 2023
 */

#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    std::ifstream file(INPUT_FILENAME);
    std::string line;

    int sum = 0;

    while (std::getline(file, line)) {
        int first = -1;
        int last;
        for (char c : line) {
            if (!isdigit(c)) {
                continue;
            }
            last = c - '0';
            if (first == -1) {
                first = last;
            }
        }
        sum += (first * 10) + last;
    }

    printf("%d\n", sum);

    return EXIT_SUCCESS;
}