#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int getSum(vector<vector<int>> &v, int rbeg, int cbeg, int size)
{
    int result = 0;
    for (int r = rbeg, rend = rbeg + size; r < rend; ++r)
    {
        for (int c = cbeg, cend = cbeg + size; c < cend; ++c)
        {
            result += v[r][c];
        }
    }
    return result;
}

int largestSubgrid(vector<vector<int>> grid, int maxSum)
{
    int srow = grid.size();
    int scol = grid[0].size();
    int size = srow;
    if (srow == 0 || srow != scol)
        return 0;

    vector<vector<vector<int>>> med_v;
    for (int i = 0; i < srow; ++i)
    {
        vector<vector<int>> row;
        // cout << "[\n";
        for (int j = 0; j < scol; ++j)
        {
            int row_sum = 0;
            vector<int> tmp;
            // cout << "    row " << i << " col " << j << ": ";
            for (int k = j; k < scol; ++k)
            {
                row_sum += grid[i][k];
                tmp.push_back(row_sum);
                // cout << "med_v[" << i << "][" << j << "][" << k - j << "] = "<< row_sum << ", ";
            }
            row.push_back(tmp);
            // cout << endl;
        }
        // cout << "]" << endl;
        med_v.push_back(row);
    }

    // int new_sum = 0;
    // int pre_sum = -1;
    // int pre_row_sum = 0;
    // int new_row_sum = 0;
    // cout << __LINE__ << endl;
    while (size > 0)
    {
    // cout << __LINE__ << endl;
        int rbeg = 0, rend = srow - size;
        int cbeg = 0, cend = scol - size;
        bool ifMaxGrid = true;
        for (int r = rbeg; r <= rend; ++r)
        {
    // cout << __LINE__ << endl;
            for (int c = cbeg; c <= cend; ++c)
            {
    // cout << __LINE__ << endl;
                cout << "r = " << r << ", c = " << c << ", size = " << size << endl;
                int sum = 0;
                for (int i = r, iend = r + size; i < iend; ++i)
                {
                    // cout << "get i = " << i << ", c = " << c << ", med[" << i << "][" << c << "][" << size << "] = " << med_v[i][c][size - 1] << endl;
                    sum += med_v[i][c][size - 1];
                }
                // cout << sum << endl;
                if (sum > maxSum)
                {
                    ifMaxGrid = false;
                    break;
                }
            }
        }
        if (ifMaxGrid)
            return size;
        else
            --size;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int r = 0, c = 0;
    cin >> r >> c;
    vector<vector<int>> v;
    for (int i = 0; i < r; ++i)
    {
        vector<int> tmp;
        for (int j = 0; j < c; ++j)
        {
            int n = 0;
            cin >> n;
            // cout << n << endl;
            tmp.push_back(n);
        }
        v.push_back(tmp);
    }
    int maxSum = 0;
    cin >> maxSum;
    cout << largestSubgrid(v, maxSum) << endl;
    return 0;
}
