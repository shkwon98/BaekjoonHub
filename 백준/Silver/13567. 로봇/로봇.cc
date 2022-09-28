#include <iostream>
#include <utility>
#include <string>
using namespace std;

int M, n;
pair<int, int> map(0, 0);
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isIn = true;

void robot()
{
    string cmd;
    int val;
    int idx = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> cmd >> val;
        if(!isIn) continue;

        if(cmd == "MOVE")
        {
            map.first += dir[idx][0] * val;
            map.second += dir[idx][1] * val;
        }
        else if(cmd == "TURN" && val == 0) idx = (idx + 1) % 4;
        else if(cmd == "TURN" && val == 1) idx = (idx + 3) % 4;

        if(map.first < 0 || map.first > M || map.second < 0 || map.second > M)
            isIn = false;
    }
    return;
}

int main()
{
    cin >> M >> n;

    robot();

    if(isIn) cout << map.first << " " << map.second;
    else cout << -1;

    return 0;
}
