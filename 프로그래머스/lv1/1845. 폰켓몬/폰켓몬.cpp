#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> poketmon;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(poketmon.find(nums[i]) == poketmon.end()) poketmon[nums[i]] = 1;
        else poketmon[nums[i]]++;
    }
    answer = min(poketmon.size(), nums.size() / 2);
    
    return answer;
}