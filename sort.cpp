#include <iostream>
#include <string>
#include <vector>
#include "utils.hpp"

using namespace std;

void _fast_sort_r(vector<int> &v, int lo, int hi);

void merge_sort(vector<int> &v)
{
}

void insertion_sort(vector<int> &v)
{
    // size_t vsize = v.size();
    // for (int i = 1; i < vsize; ++i)
    // {
    //     int x = v[i];
    //     int j = i - 1;
    //     while (j >= 0 && v[j] > x)
    //     {
    //         v[j + 1] = v[j];
    //         --j;
    //     }
    //     v[j + 1] = x;
    // }
    size_t vsize = v.size();
    for (size_t i = 1; i < vsize; i++)
    {
        for (size_t j = i; j > 0 && v[j - 1] > v[j]; --j)
        {
            int tmp = v[j - 1];
            v[j - 1] = v[j];
            v[j] = tmp;
        }
    }
}

void fast_sort(vector<int> &v)
{
}

void selection_sort(vector<int> &v)
{
    size_t vsize = v.size();
    for (int i = 0; i < vsize; ++i)
    {
        int k = i;
        for (int j = i + 1; j < vsize; ++j)
        {
            if (v[j] < v[k])
                k = j;
        }
        if (k != i)
            swap(v[i], v[k]);
    }
}

void _fast_sort_r(vector<int> &v, int lo, int hi)
{
    if (hi <= lo)
        return;

    int i = lo, j = hi + 1;
}

void bubble_sort(vector<int> &v)
{
    size_t vsize = v.size();
    for (int i = 0; i < vsize; ++i)
    {
        for (size_t j = 1; j < vsize - i; j++)
        {
            if (v[j] < v[j - 1])
            {
                int tmp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = tmp;
            }
        }
    }
}

void shell_sort(vector<int> &v)
{
    size_t vsize = v.size();
    int h = 1;
    while (h < vsize / 3)
    {
        h = 3 * h + 1;
    }

    while (h > 1)
    {
        for (size_t i = 1; i < vsize; i++)
        {
            for (size_t j = i; j > 0 && v[j - 1] > v[j]; --j)
            {
                int tmp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = tmp;
            }
        }
    }
}