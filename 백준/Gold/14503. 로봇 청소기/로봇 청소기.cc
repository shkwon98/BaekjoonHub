#include <iostream>
#include <queue>
using namespace std;

typedef struct
{
    int row, col, dir;
}STATE;

#define MAX 50
int N, M;
int r, c, d;
int room[MAX][MAX];
bool isCleaned[MAX][MAX];
int delta[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int bfs(int row, int col, int dir)
{
    queue<STATE> q;
    q.push({ row, col, dir });
    isCleaned[row][col] = true;
    int cnt = 1;
    while (!q.empty())
    {
        STATE curr = q.front();
        q.pop();
        bool flag = false;
        for (int i = 0; i < 4; ++i)
        {
            int nd = curr.dir - 1;
            if (curr.dir == 0) nd = 3;
            int nr = curr.row + delta[nd][0];
            int nc = curr.col + delta[nd][1];
            if (room[nr][nc] == 1 || isCleaned[nr][nc])
            {
                curr.dir = nd;
                continue;
            }
            if (!isCleaned[nr][nc])
            {
                q.push({ nr, nc, nd });
                isCleaned[nr][nc] = true;
                cnt++;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            int nr = curr.row - delta[curr.dir][0];
            int nc = curr.col - delta[curr.dir][1];
            if (room[nr][nc] != 1)
                q.push({ nr, nc, curr.dir });
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> room[i][j];

    cout << bfs(r, c, d);

    return 0;
}