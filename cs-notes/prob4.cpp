#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <cctype>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int chart[5][5] = {
    {1, 4, 7, 11, 15},
    {2, 5, 8, 12, 19},
    {3, 6, 9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}};

int main()
{
    int target = 30;
    int row = 0, col = 4;
    int current = chart[row][col];
    while (target != current)
    {
        if (target > current)
            ++row;
        else
            --col;
        
        if (row > 4 || col < 0)
        {
            row = -1;
            col = -1;
            break;
        }
        current = chart[row][col];
    }
    cout << row << ' ' << col << endl;
    return 0;
}