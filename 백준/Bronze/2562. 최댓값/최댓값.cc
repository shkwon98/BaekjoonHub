#include <iostream>

using namespace std;

int temp;
int num = 0;
int idx;

int main()
{
    for(int i = 0; i < 9; ++i)
    {
        cin >> temp;
        if(temp > num)
        {
            num = temp;
            idx = i + 1;
        }
    }
    
    cout << num << "\n"
         << idx;

    return 0;
}