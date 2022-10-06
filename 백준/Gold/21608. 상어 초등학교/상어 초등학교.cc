#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 21
using namespace std;

struct STUDENT
{
    int num;
    int Friend[4];
};

struct POSITION
{
    int x;
    int y;
    int nearly_empty;
    int nearly_friend;
};

int N, answer = 0;
int map[MAX][MAX];
STUDENT student_arr[MAX * MAX];
vector<STUDENT> vStudent;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool compare(POSITION a, POSITION b)
{
    if(a.nearly_friend > b.nearly_friend) return true;
    else if(a.nearly_friend == b.nearly_friend)
    {
        if(a.nearly_empty > b.nearly_empty) return true;
        else if(a.nearly_empty == b.nearly_empty)
        {
            if(a.x < b.x) return true;
            else if(a.x == b.x)
            {
                if(a.y < b.y) return true;
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

void set_position()
{
    for(int i = 0; i < vStudent.size(); ++i)
    {
        vector<POSITION> vPos;
        for(int x = 0; x < N; ++x)
        {
            for(int y = 0; y < N; ++y)
            {
                if(map[x][y] != 0) continue;
                int cntFriend = 0;
                int cntEmpty = 0;
                for(int k = 0; k < 4; ++k)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    if(map[nx][ny] == 0) cntEmpty++;
                    else
                    {
                        for(int j = 0; j < 4; ++j)
                        {
                            if(map[nx][ny] == vStudent[i].Friend[j])
                            {
                                cntFriend++;
                                break;
                            }
                        }
                    }
                }
                vPos.push_back({x, y, cntEmpty, cntFriend});
            }
        }
        sort(vPos.begin(), vPos.end(), compare);
        map[vPos[0].x][vPos[0].y] = vStudent[i].num;
    }
}

void calculate()
{
    for(int x = 0; x < N; ++x)
    {
        for(int y = 0; y < N; ++y)
        {
            int cntFriend = 0;
            for(int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                for(int j = 0; j < 4; ++j)
                {
                    if(map[nx][ny] == student_arr[map[x][y]].Friend[j])
                    {
                        cntFriend++;
                        break;
                    }
                }
            }
            switch(cntFriend)
            {
                case 0:
                    break;
                case 1:
                    answer++;
                    break;
                case 2:
                    answer += 10;
                    break;
                case 3:
                    answer += 100;
                    break;
                case 4:
                    answer += 1000;
                    break;
            }
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N * N; ++i)
    {
        int s, f0, f1, f2, f3;
        cin >> s >> f0 >> f1 >> f2 >> f3;
        vStudent.push_back({s, {f0, f1, f2, f3}});
        student_arr[s].Friend[0] = f0;
        student_arr[s].Friend[1] = f1;
        student_arr[s].Friend[2] = f2;
        student_arr[s].Friend[3] = f3;
    }
    
    set_position();
    calculate();
    cout << answer;
}