#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define MAX 51
int N, L, R, arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

queue<pair<int, int>> q;
vector<pair<int, int>> v;
int sum = 0;

void bfs(pair<int, int> start)
{
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int na = temp.first + dx[i];
            int nb = temp.second + dy[i];

            if (na >= 0 && nb >= 0 && na < N && nb < N && !visited[na][nb])
            {
                if (abs(arr[na][nb] - arr[temp.first][temp.second]) >= L && abs(arr[na][nb] - arr[temp.first][temp.second]) <= R)
                {
                    q.push({ na, nb });
                    visited[na][nb] = true;
                    v.push_back({ na, nb });
                    sum += arr[na][nb];
                }
            }
        }
    }
}

int main()
{
    int days = 0;

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    bool flag = true;
    while (flag)
    {
        flag = false;
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                {
                    v.clear();
                    v.push_back({ i, j });
                    sum = arr[i][j];
                    bfs({ i, j });
                }

                if (v.size() >= 2)
                {
                    flag = true;
                    for (int i = 0; i < v.size(); i++)
                    {
                        arr[v[i].first][v[i].second] = sum / v.size();
                    }
                }
            }
        }
        if (flag) days++;
    }
    cout << days;
}
