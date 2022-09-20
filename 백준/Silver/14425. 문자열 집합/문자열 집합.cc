#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, M, cnt;
int low, high, mid;
bool isFound;

void init()
{
    cin >> N;
    cin >> M;
    cnt = 0;
}
int main()
{
    init();
    
    string ref[N], temp;
    
    for(int i = 0; i < N; i++)
    {
        cin >> ref[i];
    }
    sort(ref, ref + N);
    
    for(int j = 0; j < M; j++)
    {
        cin >> temp;
        
        low = 0;
        high = N - 1;
        isFound = false;
        while((low <= high) && !isFound)
        {
            mid = (low  + high) / 2;
            if(temp == ref[mid])
            {
                cnt++;
                isFound = true;
            }
            else if(temp > ref[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    
    cout << cnt;
    return 0;
}