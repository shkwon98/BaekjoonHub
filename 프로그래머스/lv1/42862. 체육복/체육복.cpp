#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int clothNum[n + 2];
    for(int i = 1; i < n + 1; ++i)
        clothNum[i] = 1;
    
    for(int i = 0; i < reserve.size(); ++i)
        clothNum[reserve[i]]++;
    
    for(int i = 0; i < lost.size(); ++i)
        clothNum[lost[i]]--;
    
    int answer = 0;
    for(int i = 1; i < n + 1; ++i)
    {
        if(clothNum[i] == 0)
        {
            if(clothNum[i - 1] == 2)
            {
                clothNum[i - 1]--;
                clothNum[i]++;
                answer++;
            }
            else if(clothNum[i + 1] == 2)
            {
                clothNum[i + 1]--;
                clothNum[i]++;
                answer++;
            }
        }
        else answer++;
    }
    
    return answer;
}