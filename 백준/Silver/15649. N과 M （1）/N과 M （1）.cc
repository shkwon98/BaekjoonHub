#include <iostream>
#include <vector>
#define SIZE 8
using namespace std;

int n, m;
vector<int> num(SIZE);
vector<bool> chk(SIZE);

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
        if(!chk[i])
        {
            chk[i] = true;
            num[cnt] = i;
            dfs(cnt + 1, 1);
            chk[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    dfs(0, 1); // 인덱스, 시작탐색값
    
    return 0;
}