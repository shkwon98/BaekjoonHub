#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000
int M, N;
int tomato[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int> > q;
int dist[MAX][MAX];
int day = 0;

void bfs()
{
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int nr = cur.first + dx[i];
            int nc = cur.second + dy[i];
            
            if(nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
            if(dist[nr][nc] >= 0) continue;
            
            dist[nr][nc] = dist[cur.first][cur.second] + 1;
            q.push({nr, nc});
        }
    }
}

int main()
{
    ios::sync_with_stdio(NULL);
	cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
             cin >> tomato[i][j];
             if(tomato[i][j] == 1) q.push({i, j});
             if(tomato[i][j] == 0) dist[i][j] = -1;
        }
    }

    bfs();

    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(dist[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            day = max(day, dist[i][j]);
        }
    }
    cout << day;
    return 0;
}