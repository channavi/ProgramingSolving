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
		case 'f': case 'd':
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
			//'f'�� float�� 'd'�� int�� ���� �����Ѵ�.
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
	printf("����, �Ҽ�, ����, ���ڿ� ������ �Է��Ͻÿ�");
	my_scanf("%c", &c_data);
	my_scanf("%f", &f_data);
	my_scanf("%d", &i_data);
	my_scanf("%s", &s_data);

	printf("[input] : %c, %f, %d, %s\n", c_data, f_data, i_data, s_data);
	return 0;
}