#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <cctype>
#include <cstring>
#include <vector>
#include <algorithm>

#include "utils.hpp"
#include "Sales_item.hpp"
#include "problems/backpack.hpp"

using namespace std;

int main()
{
    // const vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cout << binarySearch(v, 11) << endl;
    // const vector<int> a{1, 3, 5, 7, 9, 22, 33};
    // const vector<int> b{-1, 0, 2, 4, 6, 8, 10};
    // printVec(merge_vec(a, b));
    vector<int> v{17, 3, 4, 2, 88, -12, -2, -4, 21, 11, 9};
    printVec(v);
    // vector<int> v;
    // selection_sort(v);
    // insertion_sort(v);
    // bubble_sort(v);
    // shell_sort(v);
    // merge_sort(v);
    // fast_sort(v);
    heap_sort(v);
    printVec(v);
    // int i = 0;
    // cout << ++i << endl;
    // cout << i++ << endl;
    return 0;
}
