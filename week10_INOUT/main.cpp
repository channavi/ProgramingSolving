#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("C:/Users/tuop/test.txt"); // 읽어올 파일의 경로와 이름을 지정합니다.

    if (file.is_open()) {
        int intCount = 0;
        int charCount = 0;
        int stringCount = 0;

        std::string word;
        while (file >> word) { // 파일에서 한 단어씩 읽어옵니다.
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

        file.close(); // 파일을 닫습니다.

        std::cout << "Int 개수: " << intCount << std::endl;
        std::cout << "Char 개수: " << charCount << std::endl;
        std::cout << "String 개수: " << stringCount << std::endl;
    }
    else {
        std::cout << "파일을 열 수 없습니다." << std::endl;
    }

    return 0;
}
