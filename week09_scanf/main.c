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
		case 'h': case 'd':
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
			//'h'면 short로 'd'면 int로 값을 대입한다.
			if (*ap_format == 'h') *(short*)ap_data = num * flag;
			else *(int*)ap_data = num * flag;
			break;
		}

	}
	return 1;
}

int main()
{
	char c_data;
	short h_data;
	int i_data;

	my_scanf("%c", &c_data);
	my_scanf("%h", &h_data);
	my_scanf("%d", &i_data);

	printf("[input] : %c, %h, %d\n", c_data, h_data, i_data);
	return 0;
}