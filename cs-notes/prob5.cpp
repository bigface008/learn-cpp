#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string input = "A BCAD    ADF";
    int len = 0;
    vector<int> pos_v(input.size(), 0);
    for (int i = 0, iend = input.size(); i < iend; ++i)
    {
        pos_v[i] = len;
        if (input[i] == ' ')
            len += 3;
        else
            ++len;
    }

    string output(len, 0);
    for (int i = 0, iend = input.size(); i < iend; ++i)
    {
        int start_pos = pos_v[i];
        if (input[i] == ' ')
        {
            output[start_pos] = '%';
            output[start_pos + 1] = '2';
            output[start_pos + 2] = '0';
        }
        else
            output[start_pos] = input[i];
    }
    cout << output << endl;
    return 0;
}
