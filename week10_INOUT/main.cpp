#include <stdio.h>
#include <ctype.h>

int main() {
    FILE* file;
    char filename[] = "test.txt";
    char c;
    int charCount = 0;
    int intCount = 0;
    int stringCount = 0;
    int inWord = 0;

    // 파일 열기
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 파일 내용 분석
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            charCount++;
            if (!inWord) {
                inWord = 1;
                stringCount++;
            }
        }
        else if (isdigit(c)) {
            intCount++;
            if (!inWord) {
                inWord = 1;
                stringCount++;
            }
        }
        else {
            inWord = 0;
        }
    }

    // 파일 닫기
    fclose(file);

    // 결과 출력
    printf("파일 내용:\n");
    printf("char 형태: %d\n", charCount);
    printf("int 형태: %d\n", intCount);
    printf("string 형태: %d\n", stringCount);

    return 0;
}
