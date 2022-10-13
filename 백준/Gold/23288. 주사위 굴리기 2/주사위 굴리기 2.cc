#include <iostream>
#include <queue>

#define MAX 21
using namespace std;

struct DICE_INFO
{
    int top;
    int bottom;
    int front;
    int back;
    int left;
    int right;
    int row;
    int col;
};

enum
{
    GO_RIGHT,
    GO_DOWN,
    GO_LEFT,
    GO_UP
};

enum
{
    CW,
    CCW,
    OPP,
};

int n, m, k;
int map[MAX][MAX];
DICE_INFO dice;

bool isVisited[MAX][MAX];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

int answer = 0;

void init()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> map[i][j];

    dice.top = 1;
    dice.front = 5;
    dice.right = 3;
    dice.bottom = 6;
    dice.back = 2;
    dice.left = 4;
    dice.row = 0;
    dice.col = 0;
}

void move_dice(int dir)
{
    if (dir == GO_RIGHT) // 오른쪽으로 이동
    {
        dice.right = dice.top;
        dice.top = dice.left;
        dice.left = 7 - dice.right;
        dice.bottom = 7 - dice.top;

        dice.col++;
    }
    else if (dir == GO_LEFT) // 왼쪽으로 이동
    {
        dice.left = dice.top;
        dice.top = dice.right;
        dice.right = 7 - dice.left;
        dice.bottom = 7 - dice.top;

        dice.col--;
    }
    else if (dir == GO_DOWN) // 아래로 이동
    {
        dice.front = dice.top;
        dice.top = dice.back;
        dice.back = 7 - dice.front;
        dice.bottom = 7 - dice.top;

        dice.row++;
    }
    else if (dir == GO_UP) // 위로 이동
    {
        dice.back = dice.top;
        dice.top = dice.front;
        dice.front = 7 - dice.back;
        dice.bottom = 7 - dice.top;

        dice.row--;
    }
}

int change_dir(int rotation, int curDir)
{
    int newDir;

    if (rotation == CW) newDir = (curDir + 1) % 4;
    else if (rotation == CCW) newDir = (curDir + 3) % 4;
    else newDir = (curDir + 2) % 4;

    return newDir;
}

void bfs(int row, int col)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            isVisited[i][j] = false;

    int curNum = map[row][col];

    queue<pair<int, int> > q;
    isVisited[row][col] = true;
    answer += curNum;
    q.push({ row, col });
    while (!q.empty())
    {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (isVisited[nr][nc]) continue;
            if (map[nr][nc] != curNum) continue;

            isVisited[nr][nc] = true;
            answer += curNum;
            q.push({ nr, nc });
        }
    }
}

void play_game(int cnt, int dir)
{
    if (cnt > k) return;

    bfs(dice.row, dice.col);

    int newDir;
    if (dice.bottom > map[dice.row][dice.col]) // 주사위 진행방향 시계방향 전환
    {
        newDir = change_dir(CW, dir);
    }
    else if (dice.bottom < map[dice.row][dice.col]) // 주사위 진행방향 반시계방향 전환
    {
        newDir = change_dir(CCW, dir);
    }
    else // 주사위 진행방향 유지
    {
        newDir = dir;
    }

    move_dice(newDir);
    if (dice.row < 0 || dice.col < 0 || dice.row >= n || dice.col >= m) // 주사위가 보드를 벗어나면 반대로 이동
    {
        newDir = change_dir(OPP, newDir);
        move_dice(newDir);
        move_dice(newDir);
    }

    play_game(cnt + 1, newDir);
}

int main()
{
    init();

    move_dice(GO_RIGHT);    // 첫 1회는 무조건 오른쪽으로 굴린다
    play_game(1, 0); // 점수계산 및 주사위 굴리기

    cout << answer;
}