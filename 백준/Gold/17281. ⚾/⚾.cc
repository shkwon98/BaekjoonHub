#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 51
#define PLAYER_NUM 10
int N, answer = 0;
int order[PLAYER_NUM] = { 0, };
int game[MAX][PLAYER_NUM];

void playGame()
{
    int score = 0;
    int startPlayer = 1;
    bool baseState[4];
    for (int i = 1; i <= N; ++i)
    {
        int outCnt = 0;
        bool nextIning = false;
        memset(baseState, false, sizeof(baseState));
        while (1)
        {
            for (int j = startPlayer; j < PLAYER_NUM; ++j)
            {
                int player = game[i][order[j]];
                if (player == 0)
                    outCnt++;
                else if (player == 1)
                {
                    for (int k = 3; k >= 1; --k)
                    {
                        if (baseState[k])
                        {
                            if (k == 3)
                            {
                                baseState[k] = false;
                                score++;
                            }
                            else
                            {
                                baseState[k + 1] = true;
                                baseState[k] = 0;
                            }
                        }
                    }
                    baseState[1] = true;
                }
                else if (player == 2)
                {
                    for (int k = 3; k >= 1; --k)
                    {
                        if (baseState[k])
                        {
                            if (k == 3 || k == 2)
                            {
                                baseState[k] = false;
                                score++;
                            }
                            else
                            {
                                baseState[k + 2] = true;
                                baseState[k] = false;
                            }
                        }
                    }
                    baseState[2] = true;
                }
                else if (player == 3)
                {
                    for (int k = 3; k >= 1; --k)
                    {
                        if (baseState[k])
                        {
                            baseState[k] = false;
                            score++;
                        }
                    }
                    baseState[3] = true;
                }
                else
                {
                    for (int k = 3; k >= 1; --k)
                    {
                        if (baseState[k])
                        {
                            baseState[k] = false;
                            score++;
                        }
                    }
                    score++;
                }
                if (outCnt == 3)
                {
                    startPlayer = j + 1;
                    if (startPlayer == PLAYER_NUM) startPlayer = 1;
                    nextIning = true;
                    break;
                }
            }
            if (nextIning) break;
            startPlayer = 1;
        }
    }

    if (answer < score) answer = score;
}

void dfs(int cnt)
{
    if (cnt == PLAYER_NUM)
    {
        playGame();
        return;
    }
    for (int i = 1; i < PLAYER_NUM; i++)
    {
        if (order[i] != 0) continue;

        order[i] = cnt;
        dfs(cnt + 1);
        order[i] = 0;
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j < PLAYER_NUM; j++)
            cin >> game[i][j];

    order[4] = 1;
    dfs(2);

    cout << answer;
    return 0;
}