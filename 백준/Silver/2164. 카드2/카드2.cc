#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i)
        q.push(i);
    
    while(q.size() != 1)
    {
        q.pop();
        
        int num = q.front();
        q.pop();
        q.push(num);
    }
    cout << q.front();
        
    return 0;
}