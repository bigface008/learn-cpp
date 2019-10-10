#ifndef _H_UTILS
#define _H_UTILS

#include <vector>

using namespace std;

#define OUTPUT(currVal, cnt)                                                \
    {                                                                       \
        std::cout << currVal << " occurs " << cnt << " times" << std::endl; \
    }

#define VAR_OUTPUT(val)                                                                  \
    {                                                                                    \
        std::cout << typeid(val).name() << "\t" << (#val) << "\t" << (val) << std::endl; \
    }

void swap(int &a, int &b);
void printVec(const vector<int> &v);

/* Sort */
void merge_sort(vector<int> &v);
void insertion_sort(vector<int> &v);
void fast_sort(vector<int> &v);
void heap_sort(vector<int> &v);
void selection_sort(vector<int> &v);
void bubble_sort(vector<int> &v);
void shell_sort(vector<int> &v);

/* Search */
int binarySearch(const vector<int> &v, int target);

/* Other */
const vector<int> merge_vec(const vector<int> &a, const vector<int> &b);

#endif