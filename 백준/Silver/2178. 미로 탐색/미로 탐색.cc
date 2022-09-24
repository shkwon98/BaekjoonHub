#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct
{
    int row;
    int col;
    int dist;
}POINT;

#define MAX 100
int N, M;
int map[MAX][MAX] = {};
bool visited[MAX][MAX] = {};
int direction[4][2] = { {-1,  0},
                        { 1,  0},
                        { 0, -1},
                        { 0,  1} };

int bfs()
{
    visited[0][0] = true;
    queue<POINT> q;
    q.push({0, 0, 1});
    
    while (!q.empty())
    {
        POINT curr = q.front();
        q.pop();
        if (curr.row == N - 1 && curr.col == M - 1)
            return curr.dist;
        
        for (int i = 0; i < 4; ++i)
        {
            int nr = curr.row + direction[i][0];
            int nc = curr.col + direction[i][1];
            if (nr < 0 || nr > N - 1 || nc < 0 || nc > M - 1)
                continue;
            if (!map[nr][nc] || visited[nr][nc])
                continue;
            visited[nr][nc] = true;
            q.push({nr, nc, curr.dist + 1});
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%1d", &map[i][j]);
    
    cout << bfs();
    return 0;
}
