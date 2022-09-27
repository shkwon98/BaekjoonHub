#include <iostream>
using namespace std;

int N, num;
bool arr[2000001] = {};

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> num;
        arr[num + 1000000] = true;
    }
    for(int i = 0; i <= 2000000; ++i)
        if(arr[i]) cout << i - 1000000 << "\n";

    return 0;
}