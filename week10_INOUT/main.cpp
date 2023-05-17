#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("C:/Users/tuop/test.txt"); // �о�� ������ ��ο� �̸��� �����մϴ�.

    if (file.is_open()) {
        int intCount = 0;
        int charCount = 0;
        int stringCount = 0;

        std::string word;
        while (file >> word) { // ���Ͽ��� �� �ܾ �о�ɴϴ�.
            if (isdigit(word[100])) {
                intCount++;
            }
            else if (isalpha(word[100])) {
                if (word.size() == 1)
                    charCount++;
                else
                    stringCount++;
            }
        }

        file.close(); // ������ �ݽ��ϴ�.

        std::cout << "Int ����: " << intCount << std::endl;
        std::cout << "Char ����: " << charCount << std::endl;
        std::cout << "String ����: " << stringCount << std::endl;
    }
    else {
        std::cout << "������ �� �� �����ϴ�." << std::endl;
    }

    return 0;
}
