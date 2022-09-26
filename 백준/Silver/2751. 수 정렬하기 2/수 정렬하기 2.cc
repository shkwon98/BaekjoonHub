#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[10000001];

void quickSort(int* data, int start, int end)
{
    if(start >= end) return;
    
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;
    while(i <= j)
    {
        while(data[i] <= data[key])
            i++;
        while(data[j] >= data[key] && j > start)
            j--;
        if(i > j)
        {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else
        {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
    }
    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];

    random_shuffle(arr, arr + N);
    quickSort(arr, 0, N - 1);

    for(int i = 0; i < N; ++i)
        cout << arr[i] << "\n";

    return 0;
}