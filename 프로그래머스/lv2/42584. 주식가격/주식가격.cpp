#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); ++i)
    {
        int temp = prices.size() - i - 1;
        for(int j = i + 1; j < prices.size(); ++j)
        {
            if(prices[i] > prices[j])
            {
                temp = j - i;
                break;
            }
        }
        answer.push_back(temp);
    }
    return answer;
}