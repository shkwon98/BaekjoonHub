#include <iostream>
#include <queue>
using namespace std;

int T, M, N, K;
bool map[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int cx, int cy)
{
    queue<pair<int, int> > qPos;
    map[cx][cy] = false;
    qPos.push({cx, cy});
    
    while(!qPos.empty())
    {
        pair<int, int> curr = qPos.front();
        qPos.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            
            if(map[nx][ny])
            {
                map[nx][ny] = false;
                qPos.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        cin >> M >> N >> K;
        for(int j = 0; j < K; ++j)
        {
            int x, y;
            cin >> x >> y;
            map[x][y] = true;
        }
        
        int ret = 0;
        for(int x = 0; x < M; ++x)
        {
            for(int y = 0; y < N; ++y)
            {
                if(map[x][y])
                {
                    bfs(x, y);
                    ret++;
                }
            }
        }
        cout << ret << "\n";
    }
}