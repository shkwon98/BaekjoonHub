#include <iostream>

using namespace std;

int num, idx;
int cnt = 0;
bool arr[43] = {};

int main()
{
    for(int i = 0; i < 10; ++i)
    {
        cin >> num;
        idx = num % 42;
        if(!arr[idx])
        {
            arr[idx] = true;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
