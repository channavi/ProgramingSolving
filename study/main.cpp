#include <iostream>
#include <conio.h>

int main() {
    std::cout << "���α׷��� �����մϴ�. EscŰ�� ������ ����˴ϴ�." << std::endl;

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 27) {
                std::cout << "���α׷��� �����մϴ�." << std::endl;
                break;
            }
        }
    }

    return 0;
}