#include <iostream>

using namespace std;

int N;
int num[101];
int sum = 0;

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        scanf("%1d", &num[i]);
        sum += num[i];
    }
    cout << sum;
    return 0;
}
