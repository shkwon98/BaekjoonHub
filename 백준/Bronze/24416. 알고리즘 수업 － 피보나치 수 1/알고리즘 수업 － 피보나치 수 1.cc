#include <iostream>
#define SIZE 41
using namespace std;

int f[SIZE];
int cnt[2] = {0,};
int num;

int fib(int n)
{    
    if ( n == 1 || n == 2 )
    {
        cnt[0]++;
        return 1;
    }
    else
        return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n)
{    
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        cnt[1]++;
    }    
    return f[n];
}

int main()
{
    cin >> num;
    fib(num);
    fibonacci(num);
    cout << cnt[0] << " " << cnt[1];
    return 0;
}