#include <iostream>

using namespace std;

unsigned complementation(unsigned a, unsigned b)
{
    /* 找出第一次超过a的bd值。 */
    unsigned bd = b;
    unsigned times; /* bd / b */
    while (a > bd)
        bd *= 2;

    if (a == bd)
        return 0;

    /* 利用2分法使结果逼近a。 */
    times = bd / b;
    unsigned i = times / 2, j = times;
    unsigned mid = (i + j) / 2;
    while (j - i != 1)
    {
        if (a == mid * b)
            return 0;
        else if (a < mid * b)
            j = mid;
        else
            i = mid;
        mid = (i + j) / 2;
    }
    return a - i * b;
}

int main(int argc, char const *argv[])
{
    cout << complementation(180, 7) << endl;
    cout << 180, 7
    return 0;
}
