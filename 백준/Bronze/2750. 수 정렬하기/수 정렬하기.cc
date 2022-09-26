#include <iostream>
using namespace std;

int N;
int arr[1001];

void select_sort()
{
    int temp, index;
    for(int i = 0; i < N; ++i)
    {
        int min = 1001;
        for(int j = i; j < N; ++j)
        {
            if(min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    
    select_sort();
    
    for(int i = 0; i < N; ++i)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}
