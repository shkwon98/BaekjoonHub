#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[10000001];

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(arr, arr + N);

    for (int i = 0; i < N; ++i)
        printf("%d\n", arr[i]);

    return 0;
}