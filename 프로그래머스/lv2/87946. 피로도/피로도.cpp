#include <string>
#include <vector>

using namespace std;

bool isChecked[9];
int answer = 0;

void recursive(int cnt, int energy, vector<vector<int>> dungeons)
{
    for(int i = 0; i < dungeons.size(); ++i)
    {
        if(isChecked[i]) continue;
        if(energy < dungeons[i][0]) continue;
        
        isChecked[i] = true;
        
        recursive(cnt + 1, energy - dungeons[i][1], dungeons);
        
        isChecked[i] = false;
    }
    
    if(cnt > answer) answer = cnt;
}

int solution(int k, vector<vector<int>> dungeons)
{
    recursive(0, k, dungeons);
    
    return answer;
}