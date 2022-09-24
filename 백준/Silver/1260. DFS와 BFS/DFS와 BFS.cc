#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1001
int N, M, start;
bool graph[MAX][MAX] = {};
bool visited[MAX] = {};

void dfs(int now)
{
    visited[now] = true;
    cout << now << ' ';
    
    for(int next = 1; next <= N; ++next)
    {
        if(!visited[next] && graph[now][next])
            dfs(next);
    }
}
void bfs(int now)
{
    queue<int> q;
    q.push(now);
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        if(!visited[curr])
        {
            visited[curr] = true;
            cout << curr << ' ';
            
            for(int next = 1; next <= N; ++next)
            {
                if(!visited[next] && graph[curr][next])
                q.push(next);
            }
        }
    }   
}

int main()
{
    cin >> N >> M >> start;
    for(int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph [v][u] = true;
    }
    
    dfs(start);
    cout << "\n";
    memset(visited, false, sizeof(visited));
    bfs(start);
    
    return 0;
}
