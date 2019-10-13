#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "utils.hpp"

using namespace std;

void _merge_vec(vector<int> &v, int low, int mid, int high);
const vector<int> merge_vec(const vector<int> &a, const vector<int> &b);
void _fast_sort_r(vector<int> &v, int lo, int hi);
int _fast_sort_split(vector<int> &v, int lo, int hi);
void _make_heap(vector<int> &v);
// void _sift_down(vector<int> &v, int t);
void _sift_down(vector<int> &v, int end, int t);

void merge_sort(vector<int> &v)
{
    size_t vsize = v.size();
    for (int sz = 1; sz < vsize; sz *= 2)
    {
        int lsz = vsize - sz;
        for (int lo = 0; lo < lsz; lo += 2 * sz)
        {
            int end = lo + sz * 2 - 1;
            end = end > vsize - 1 ? vsize - 1 : end;
            _merge_vec(v, lo, lo + sz - 1, end);
        }
    }
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
    _fast_sort_r(v, 0, v.size() - 1);
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

    int md = _fast_sort_split(v, lo, hi);
    _fast_sort_r(v, lo, md);
    _fast_sort_r(v, md + 1, hi);
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

    while (h >= 1)
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
        h /= 3;
    }
}

void heap_sort(vector<int> &v)
{
    _make_heap(v);
    cout << "----------------------------------" << endl;
    for (int i = v.size() - 1; i >= 1; --i)
    {
        swap(v[0], v[i]);
        _sift_down(v, i - 1, 0);
    }
}

void _merge_vec(vector<int> &v, int low, int mid, int high)
{
    int i = low, j = high;
    vector<int> tmp;
    for (size_t k = low; k <= high; ++k)
        tmp.push_back(v[k]);

    for (size_t k = low; k <= high; ++k)
    {
        if (i > mid)
            v[k] = tmp[j++ - low];
        else if (j > high)
            v[k] = tmp[i++ - low];
        else if (v[i] <= v[j])
            v[k] = tmp[i++ - low];
        else
            v[k] = tmp[j++ - low];
    }
}

int _fast_sort_split(vector<int> &v, int lo, int hi)
{
    if (lo > hi)
        return -1;

    int i = lo, j = lo + 1;
    int x = v[lo];
    for (; j < hi; ++j)
    {
        if (v[j] <= x)
        {
            ++i;
            swap(v[i], v[j]);
        }
    }
    swap(v[lo], v[i]);
    return i;
}

void _make_heap(vector<int> &v)
{
    size_t sz = v.size();
    cout << "> _make_heap: v.size() = " << v.size() << endl;
    for (int i = sz / 2; i >= 0; --i)
        _sift_down(v, sz, i);
    printVec(v);
    cout << "< _make_heap" << endl;
}

void _sift_down(vector<int> &v, int end, int t)
{
    bool done = false;
    cout << "> _sift_down: i = " << t << "; end = " << end << endl;
    cout << "    before";
    printVec(v);
    if (2 * t + 1 > end - 1)
        return;

    int i = t;
    do
    {
        // cout << "     > start loop i = " << i << endl;
        i = 2 * i + 1;
        if (i < end - 1 && v[i + 1] > v[i])
            ++i;

        // cout << "     step i = " << i << endl;
        if (v[(i - 1) / 2] < v[i])
            swap(v[i], v[(i - 1) / 2]);
        else
            done = true;
        // cout << "     < end loop" << endl;
    } while (!(2 * i > end || done));
    cout << "    after";
    printVec(v);
    cout << "< _sift_down" << endl;
}