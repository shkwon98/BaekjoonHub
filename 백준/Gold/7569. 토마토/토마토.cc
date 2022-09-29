#include <iostream>
#include <queue>
using namespace std;

#define MAX 100
int M, N, H;
int tomato[MAX][MAX][MAX];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
queue<pair<pair<int, int>, int> > q;
int dist[MAX][MAX][MAX];
int day = 0;

void bfs()
{
    while(!q.empty())
    {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 6; ++i)
        {
            int nx = cur.second + dx[i];
            int ny = cur.first.second + dy[i];
            int nz = cur.first.first + dz[i];
            if(nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
            if(dist[nz][ny][nx] >= 0) continue;
            dist[nz][ny][nx] = dist[cur.first.first][cur.first.second][cur.second] + 1;
            q.push({{nz, ny}, nx});
        }
    }
}

int main()
{
    ios::sync_with_stdio(NULL);
	cin.tie(NULL);

    cin >> M >> N >> H;
    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            for(int k = 0; k < M; ++k)
            {
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1) q.push({{i, j}, k});
                if(tomato[i][j][k] == 0) dist[i][j][k] = -1;
            }
        }
    }

    bfs();

    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            for(int k = 0; k < M; ++k)
            {
                if(dist[i][j][k] == -1)
                {
                    cout << -1;
                    return 0;
                }
                day = max(day, dist[i][j][k]);
            }
        }
    }
    cout << day;
    return 0;
}