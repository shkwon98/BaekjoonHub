#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<string> map;
pair<int, int> red, blue;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int answer = 23432411;

int inverse_direction(int dir)
{
    if (dir == 0) return 1;
    if (dir == 1) return 0;
    if (dir == 2) return 3;
    if (dir == 3) return 2;
}

void move(int Rx, int Ry, int Bx, int By, int cnt, int dir)
{
    if (cnt > 10) return;

    bool redFlag = false;
    bool blueFlag = false;

    int nRx = Rx;
    int nRy = Ry;
    while (1)
    {
        nRx += dx[dir];
        nRy += dy[dir];
        if (map[nRx][nRy] == '#') break;
        if (map[nRx][nRy] == 'O')
        {
            redFlag = true;
            break;
        }
    }
    nRx -= dx[dir];
    nRy -= dy[dir];

    int nBx = Bx;
    int nBy = By;
    while (1)
    {
        nBx += dx[dir];
        nBy += dy[dir];
        if (map[nBx][nBy] == '#') break;
        if (map[nBx][nBy] == 'O')
        {
            blueFlag = true;
            break;
        }
    }
    nBx -= dx[dir];
    nBy -= dy[dir];

    if (blueFlag) return;
    if (redFlag)
    {
        answer = min(cnt, answer);
        return;
    }

    if (nRx == nBx && nRy == nBy)
    {
        int redDist = abs(nRx - Rx) + abs(nRy - Ry);
        int blueDist = abs(nBx - Bx) + abs(nBy - By);
        if (redDist > blueDist)
        {
            nRx -= dx[dir];
            nRy -= dy[dir];
        }
        else
        {
            nBx -= dx[dir];
            nBy -= dy[dir];
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if (i == dir) continue;
        if (i == inverse_direction(dir)) continue;
        move(nRx, nRy, nBx, nBy, cnt + 1, i);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string temp;
        cin >> temp;
        map.push_back(temp);
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j] == 'R')
            {
                red = { i, j };
                map[i][j] = '.';
            }
            else if (map[i][j] == 'B')
            {
                blue = { i, j };
                map[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < 4; ++i)
        move(red.first, red.second, blue.first, blue.second, 1, i);

    if (answer > 10) answer = -1;
    cout << answer;
}