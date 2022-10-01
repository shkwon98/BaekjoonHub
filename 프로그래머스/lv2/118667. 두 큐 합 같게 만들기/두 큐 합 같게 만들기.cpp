#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    long long sum1 = 0, sum2 = 0;
    int len = queue1.size();
    queue<int> q1, q2;
    for(int i = 0; i < len; ++i)
    {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    long long target = (sum1 + sum2) / 2;
    int cnt = 0;
    while(sum1 != sum2)
    {
        if(cnt > 4 * len) return -1;
        if(sum1 > target)
        {
            q2.push(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop();
        }
        else
        {
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
        }
        cnt++;
    }

    return cnt;
}