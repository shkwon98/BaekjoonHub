#include <iostream>
using namespace std;

int arr[4];

void select_sort()
{
    int temp, index;
    for(int i = 0; i < 3; ++i)
    {
        int min = 1000001;
        for(int j = i; j < 3; ++j)
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
    for(int i = 0; i < 3; ++i)
    {
        cin >> arr[i];
    }
    
    select_sort();
    
    for(int i = 0; i < 3; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
