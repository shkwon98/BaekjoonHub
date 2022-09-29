#include <iostream>
using namespace std;

int T, N;
int arr[41] = {0, 1, };

int fibonacci(int n)
{
    if(n == 0 || n == 1) return arr[n];
    else if (arr[n] == 0) arr[n] = fibonacci(n - 2) + fibonacci(n - 1);
    return arr[n];
}
int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        cin >> N;
        if(N == 0) cout << "1 0\n";
        else cout << fibonacci(N - 1) << " " << fibonacci(N) << "\n";
    }

    return 0;
}
