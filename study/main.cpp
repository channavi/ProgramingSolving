#include <iostream>
#include <conio.h>

int main() {
    std::cout << "프로그램을 실행합니다. Esc키를 누르면 종료됩니다." << std::endl;

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 27) {
                std::cout << "프로그램을 종료합니다." << std::endl;
                break;
            }
        }
    }

    return 0;
}