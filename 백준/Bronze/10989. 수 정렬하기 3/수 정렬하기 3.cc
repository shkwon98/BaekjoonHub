#include <iostream>
using namespace std;

int N, num;
int arr[10000] = {};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> num;
        arr[num - 1]++;
    }
    for(int i = 0; i < 10000; ++i)
    {
        while(arr[i] > 0)
        {
            cout << i + 1 << "\n";
            arr[i]--;
        }
    }
    
    return 0;
}