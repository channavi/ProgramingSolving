#include <iostream>
#include <map>
#include <conio.h>
#include <stdio.h>

int romanToInteger(std::string s) {
    std::map<char, int> romanMap = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        if (i > 0 && romanMap[s[i]] > romanMap[s[i - 1]]) {
            result += romanMap[s[i]] - 2 * romanMap[s[i - 1]];
        }
        else {
            result += romanMap[s[i]];
        }
    }

    return result;
}

int main() {
    std::string roman;
    std::cout << "로마 숫자를 입력하세요. Esc키를 누르면 종료됩니다." << std::endl;

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 27) {
                std::cout << "프로그램을 종료합니다." << std::endl;
                return 0;
            }
        }

        std::cin >> roman;
        int result = romanToInteger(roman);
        std::cout << "정수로 변환된 값은 " << result << "입니다." << std::endl;
    }
}