#include <iostream>
#include <vector>
#include "utils.hpp"

using namespace std;

int binarySearch(const vector<int> &v, int target)
{
    auto beg = v.cbegin(), end = v.cend();
    auto mid = v.cbegin() + v.size() / 2;
    while (beg != end)
    {
        if (target == *mid)
            return mid - v.cbegin(); /* Target found. */
        else if (target < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }
    return -1; /* Target not found. */
}

void showResult(const vector<int> v, int index)
{
    if (index == -1)
    {
        cout << "Target not found.\n";
        return;
    }

    for (int i = 0, end = v.size(); i < end; i++)
    {
        if (i == index)
            cout << "[" << v[i] << "] ";
        else
            cout << v[i] << ' ';
    }
    cout << '\n';
}
