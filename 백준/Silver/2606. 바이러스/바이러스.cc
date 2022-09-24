#include <iostream>
#include <queue>
using namespace std;

#define MAX 101
int N, M;
bool network[MAX][MAX] = {};
bool infected[MAX] = {};
int cnt = 0;

int bfs(int node)
{
    infected[node] = true;
    queue<int> q;
    q.push(node);
    
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        for (int next = 1; next <= N; ++next)
        {
            if (!infected[next] && network[curr][next])
            {
                infected[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        network[u][v] = network[v][u] = true;
    }
    
    cout << bfs(1);
    return 0;
}
