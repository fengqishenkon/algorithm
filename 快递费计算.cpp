#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;



//快递分段计费，在一千克以内的按照20元起步计算，超过一千克的部分每一千克1元，不足一千克的按照一千克计算，需要加急需要另外加5元
//现在需要输入两个变量：1、快递重量a。2、是否选择加急b（y表示选择加急，n表示不加急）。

int main() {
    float a=0;
    char b=0;
   
    while (cin >> a >> b)
    { // 注意 while 处理多个 case
        float c = a - 1;
        if (a > 0 && a <= 1)
        {
            if (b == 'n')
            {
                cout << 20 << endl;
            }
            if (b == 'y')
            {
                cout << 20 + 5 << endl;
            }
        }

        if (a > 1)
        {
            
            int d = (int)a - 1;
            if (c > d)
            {
                if (b == 'n')
                {
                    cout << 20 + d + 1 << endl;
                }
                if (b == 'y')
                {
                    cout << 20 + 5 + d + 1 << endl;
                }

            }

            if (c == d)
            {
                if (b == 'n')
                {
                    cout << 20 + c << endl;
                }
                if (b == 'y')
                {
                    cout << 20 + 5 + c << endl;
                }
            }
        }
    }
}