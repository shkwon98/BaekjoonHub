#include <iostream>
using namespace std;

int key[8];
int chk = 0;

int main()
{
    for (int i = 0; i < 8; ++i)
    {
        cin >> key[i];
        if (i == 0) continue;
        if (key[i] > key[i - 1])
            chk++;
        else if (key[i] < key[i - 1])
            chk--;
    }
    if (chk == 7)
        cout << "ascending";
    else if (chk == -7)
        cout << "descending";
    else
        cout << "mixed";
    
    return 0;
}
