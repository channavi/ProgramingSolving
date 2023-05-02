#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_scanf(const char* ap_format, void* ap_data)
{
	int temp_char, num = 0, flag;

	//%문자를 찾고 %가 없는 경우 대비
	while (*ap_format != '%' && *ap_format) ap_format++;
	if (*ap_format++ == '%') {//%가 있는 경우, 사용자가 입력시에 공백 또는 엔터키를 많이 사용한 경우 제거한다
		do {
			temp_char = getc(stdin);
		} while (temp_char == ' ' || temp_char == '\n');
		// %뒤에 사용한 형식 별로 입력을 처리한다.
		switch (*ap_format) {
		case 'c':
			*(char*)ap_data = temp_char; //입력한 문자열 저장
			break;
		case 'f': case 'd':
			if (temp_char == '-') { //음수인지 확인
				flag = -1;
				temp_char = '0';
			}
			else {
				//잘못입력한 수 예외
				if (!(temp_char >= '0' && temp_char <= '9')) return 0;
				flag = 1;
			}
			//숫자인 경우 문자를 정수화 시킨다.
			while (temp_char >= '0' && temp_char <= '9') {
				num = num * 10 + temp_char - '0';
				temp_char = getc(stdin);
			}
			//'f'면 float로 'd'면 int로 값을 대입한다.
			if (*ap_format == 'f') *(float*)ap_data = num * flag;
			else *(int*)ap_data = num * flag;
			break;
		case 's':
			*(char*)ap_data = temp_char;
			break;
		}

	}
	return 1;
}

int main()
{
	char c_data;
	float f_data;
	int i_data;
	char s_data[1024];
	printf("문자, 소수, 정수, 문자열 순으로 입력하시오");
	my_scanf("%c", &c_data);
	my_scanf("%f", &f_data);
	my_scanf("%d", &i_data);
	my_scanf("%s", &s_data);

	printf("[input] : %c, %f, %d, %s\n", c_data, f_data, i_data, s_data);
	return 0;
}