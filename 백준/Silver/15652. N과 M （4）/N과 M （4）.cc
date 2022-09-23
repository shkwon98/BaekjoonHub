#include <iostream>
#include <vector>
#define SIZE 8
using namespace std;

int n, m;
vector<int> num(SIZE);

void dfs(int cnt, int start)
{
    if(cnt == m)
    {
        for(int i = 0; i < cnt; i++)
        {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = start; i <= n; i++)
    {
        num[cnt] = i;
        dfs(cnt + 1, i);
    }
}

int main()
{
    cin >> n >> m;
    dfs(0, 1); // 인덱스, 시작탐색값
    
    return 0;
}