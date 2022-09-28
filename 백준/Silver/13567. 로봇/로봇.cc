#include <iostream>
#include <utility>
#include <string>
using namespace std;

int M, n;
pair<int, int> map(0, 0);
bool isIn = true;

void robot()
{
    string cmd;
    int val;
    int dir = 4000;
    for(int i = 0; i < n; ++i)
    {
        cin >> cmd >> val;
        if(cmd == "MOVE" && dir % 4 == 0) map.first += val;
        else if(cmd == "MOVE" && dir % 4 == 1) map.second += val;
        else if(cmd == "MOVE" && dir % 4 == 2) map.first -= val;
        else if(cmd == "MOVE" && dir % 4 == 3) map.second -= val;
        else if(cmd == "TURN" && val == 0) dir++;
        else if(cmd == "TURN" && val == 1) dir--;
        
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
