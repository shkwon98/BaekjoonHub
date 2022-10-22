#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long minTime = 1;
    long long maxTime = (long long)times.back() * n;
    long long midTime;
    long long cnt;
    
    while(minTime <= maxTime)
    {
        midTime = (minTime + maxTime) / 2;
        cnt = 0;
        
        for(int i = 0; i < times.size(); ++i)
            cnt += midTime / times[i];
        
        if(cnt < n) minTime = midTime + 1;
        else
        {
            answer = midTime;
            maxTime = midTime - 1;
        }
    }
    
    return answer;
}