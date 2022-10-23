#include <string>
#include <vector>

using namespace std;

bool isChecked[9];
int answer = 0;

void dfs(int cnt, int energy, vector<vector<int>> dungeons)
{
    if(cnt > answer) answer = cnt;

    for(int i = 0; i < dungeons.size(); ++i)
    {
        if(isChecked[i]) continue;
        if(energy < dungeons[i][0]) continue;

        isChecked[i] = true;
        dfs(cnt + 1, energy - dungeons[i][1], dungeons);
        isChecked[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    dfs(0, k, dungeons);
    return answer;
}