#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    sort(citations.begin(), citations.end());
    
    int answer = 0;
    
    for(int i = citations.back(); i >= 0; --i)
    {
        int cnt = 0;
        
        for(int j = 0; j < citations.size(); ++j)
            if(citations[j] >= i) cnt++;

        if(cnt >= i)
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}