#include <algorithm>
#include "backpack.hpp"

int backpack(int C[], int W[], int N, int V)
{
    vector<int> F(0, N);
    for (int i = 0; i < N; ++i)
    {
        for (int v = V; v >= C[i]; --v)
        {
            F[v] = max(F[v], F[v - C[i]] + W[i]);
        }
    }
    return F[V];
}