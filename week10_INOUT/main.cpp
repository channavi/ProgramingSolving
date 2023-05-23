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

    // ���� ����
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    // ���� ���� �м�
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

    // ���� �ݱ�
    fclose(file);

    // ��� ���
    printf("���� ����:\n");
    printf("char ����: %d\n", charCount);
    printf("int ����: %d\n", intCount);
    printf("string ����: %d\n", stringCount);

    return 0;
}
