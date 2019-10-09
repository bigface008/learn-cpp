#include <iostream>
#include <vector>
#include "utils.hpp"

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void printVec(const vector<int> &v)
{
    // for (auto i : v)
    // {
    //     cout << i << ", ";
    // }
    // cout << endl;
    cout << '[';
    for (int i = 0, iend = v.size() * 2 - 1; i < iend; ++i)
    {
        if (i % 2 == 0)
            cout << v[i / 2];
        else
            cout << ", ";
    }
    cout << ']' << endl;
}
