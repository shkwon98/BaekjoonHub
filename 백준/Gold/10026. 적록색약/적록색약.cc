#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
vector<string> color;
bool isChecked[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y, char c)
{
    queue<pair<int, int> > qPos;
    isChecked[x][y] = true;
    qPos.push({x, y});
    while(!qPos.empty())
    {
        int cx = qPos.front().first;
        int cy = qPos.front().second;
        qPos.pop();
        for(int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(isChecked[nx][ny]) continue;
            if(color[nx][ny] != c) continue;

            isChecked[nx][ny] = true;
            qPos.push({nx, ny});
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        string temp;
        cin >> temp;
        color.push_back(temp);
    }

    int ret = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(!isChecked[i][j])
            {
                char curColor = color[i][j];
                bfs(i, j, curColor);
                ret++;
            }
        }
    }
    cout << ret << ' ';

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(color[i][j] == 'G') color[i][j] = 'R';
        }
    }
    memset(isChecked, false, sizeof(isChecked));

    ret = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(!isChecked[i][j])
            {
                char curColor = color[i][j];
                bfs(i, j, curColor);
                ret++;
            }
        }
    }
    cout << ret;
}