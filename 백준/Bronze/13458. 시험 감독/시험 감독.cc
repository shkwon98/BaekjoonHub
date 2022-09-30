#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000001
int N;
int A[MAX], B, C;
long long sum = 0;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    cin >> B >> C;

    for(int i = 0; i < N; ++i)
    {
        A[i] -= B;
        sum++;
        if(A[i] > 0)
        {
            if(A[i] % C == 0) sum = sum + (A[i] / C);
            else sum = sum + (A[i] / C) + 1;
        }
    }

    cout << sum;

    return 0;
}