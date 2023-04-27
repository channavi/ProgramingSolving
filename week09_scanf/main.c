#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_scanf(const char* ap_format, void* ap_data)
{
	int temp_char, num = 0, flag;

	//%���ڸ� ã�� %�� ���� ��� ���
	while (*ap_format != '%' && *ap_format) ap_format++;
	if (*ap_format++ == '%') {//%�� �ִ� ���, ����ڰ� �Է½ÿ� ���� �Ǵ� ����Ű�� ���� ����� ��� �����Ѵ�
		do {
			temp_char = getc(stdin);
		} while (temp_char == ' ' || temp_char == '\n');
		// %�ڿ� ����� ���� ���� �Է��� ó���Ѵ�.
		switch (*ap_format) {
		case 'c':
			*(char*)ap_data = temp_char; //�Է��� ���ڿ� ����
			break;
		case 'h': case 'd':
			if (temp_char == '-') { //�������� Ȯ��
				flag = -1;
				temp_char = '0';
			}
			else {
				//�߸��Է��� �� ����
				if (!(temp_char >= '0' && temp_char <= '9')) return 0;
				flag = 1;
			}
			//������ ��� ���ڸ� ����ȭ ��Ų��.
			while (temp_char >= '0' && temp_char <= '9') {
				num = num * 10 + temp_char - '0';
				temp_char = getc(stdin);
			}
			//'h'�� short�� 'd'�� int�� ���� �����Ѵ�.
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