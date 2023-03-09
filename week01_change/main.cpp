#include <iostream>

using namespace std;

int main()
{
    unsigned short n;
    unsigned short r = 0;
    cout << "정수를 입력해주세요 : ";
    cin >> n;
    if (n > 63573)
    {
        cout << "63573을 넘지 않는 수로 해주세요";
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
