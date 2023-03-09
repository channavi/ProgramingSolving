#include <iostream>
#include <string>

std::string toRomanNumeral(int number) {
    const int arabic[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    const std::string roman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    std::string result;
    for (int i = 0; number > 0; ++i) {
        while (number >= arabic[i]) {
            number -= arabic[i];
            result += roman[i];
        }
    }
    return result;
}

int main() {
    std::string input;
    int number;
    char choice;
    do {
        std::cout << "Enter a number between 1 and 3999, or 'x' to exit: ";
        std::cin >> input;
        if (input == "x") {
            std::cout << "Exiting program." << std::endl;
            break;
        }
        try {
            number = std::stoi(input);
            if (number > 0 && number <= 3999) {
                std::cout << toRomanNumeral(number) << std::endl;
            }
            else {
                std::cout << "Number must be between 1 and 3999. Please try again." << std::endl;
            }
        }
        catch (std::invalid_argument const& e) {
            std::cout << "Invalid input. Please enter a valid number or 'x' to exit." << std::endl;
        }
    } while (true);
    return 0;
}