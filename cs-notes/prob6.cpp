#include <iostream>
#include <string>
#include <list>

using namespace std;

void printList(list<int> &l)
{
    for (auto i : l)
    {
        cout << i << " -> ";
    }
    cout << endl;
}

void revPrint(list<int> &l, list<int>::iterator it)
{
    if (l.end() == it)
        return;
    else
    {
        int val = *it;
        revPrint(l, ++it);
        cout << val << " -> ";
    }
}

void printListReversed(list<int> &l)
{
    revPrint(l, l.begin());
}

int main(int argc, char const *argv[])
{
    list<int> l;
    for (int i = 0; i < 10; ++i)
    {
        l.push_back(i);
    }

    printList(l);
    printListReversed(l);
    return 0;
}
