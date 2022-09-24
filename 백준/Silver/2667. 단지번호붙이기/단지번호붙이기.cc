#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

typedef struct
{
    int row;
    int col;
}HOUSE;

#define MAX 26
int N;
int map[MAX][MAX] = {};
bool grouped[MAX][MAX] = {};
int groupNum = 0;
int direction[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void dfs()
{
    stack<HOUSE> s;
    vector<int> v;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!map[i][j] || grouped[i][j])
                continue;
            
            grouped[i][j] = ++groupNum;
            s.push({i, j});
            v.push_back(1);
            
            while (!s.empty())
            {
                HOUSE curr = s.top();
                s.pop();
                for(int u = 0; u < 4; ++u)
                {
                    int nr = curr.row + direction[u][0];
                    int nc = curr.col + direction[u][1];
                    
                    if (nr < 0 || nr > N - 1 || nc < 0 || nc > N - 1)
                        continue;
                    if (!map[nr][nc] || grouped[nr][nc])
                        continue;
                    
                    grouped[nr][nc] = groupNum;
                    s.push({nr, nc});
                    v.back()++;
                }
            }
        }
    }
    sort(v.begin(), v.end());
    
    cout << groupNum << "\n";
    
    for(int i = 0; i < groupNum; ++i)
        cout << v[i] << "\n";
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%1d", &map[i][j]);
    dfs();
    
    return 0;
}
