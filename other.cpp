#include <vector>
#include "utils.hpp"

using namespace std;

const vector<int> merge_vec(const vector<int> &a, const vector<int> &b)
{
    vector<int> r;
    size_t rmax = a.size() + b.size();
    auto ait = a.begin(), bit = b.begin();
    while (r.size() < rmax)
    {
        if (ait == a.end())
        {
            for (auto it = bit; it != b.end(); ++it)
                r.push_back(*it);
            break;
        }
        else if (bit == b.end())
        {
            for (auto it = ait; it != a.end(); ++it)
                r.push_back(*it);
            break;
        }
        else if (*ait < *bit)
        {
            r.push_back(*ait);
            ++ait;
        }
        else
        {
            r.push_back(*bit);
            ++bit;
        }
    }
    return r;
}