#include <iostream>
#include <deque>
using namespace std;

int N;
deque<int> dq;

int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i)
        dq.push_back(i);
    
    for(int i = 0; i < N - 1; ++i)
    {
        dq.pop_front();
        
        int num = dq.front();
        dq.pop_front();
        dq.push_back(num);
    }
    cout << dq.front();
        
    return 0;
}