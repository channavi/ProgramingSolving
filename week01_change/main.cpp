#include <iostream>

using namespace std;

int main()
{
    unsigned short n;
    unsigned short r = 0;
    cout << "������ �Է����ּ��� : ";
    cin >> n;
    if (n > 63573)
    {
        cout << "63573�� ���� �ʴ� ���� ���ּ���";
    }
    else {
        while (n != 0)
        {
            r *= 10;
            r += n % 10;
            n /= 10;
        }
    }

    return 0;
}
