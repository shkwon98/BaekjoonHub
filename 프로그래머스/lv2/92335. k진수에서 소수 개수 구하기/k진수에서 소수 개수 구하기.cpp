#include <string>
#include <stack>
#include <cmath>
using namespace std;

int primeNumCnt(stack<long long> s)
{
    int cnt = 0;
    while(!s.empty())
    {
        long long cur = s.top();
        s.pop();
        
        bool isPrimeNum = true;
        if(cur < 2) isPrimeNum = false;
        for(int i = 2; i <= sqrt(cur); ++i)
        {
            if(cur % i == 0)
            {
                isPrimeNum = false;
                break;
            }
        }
        
        if(isPrimeNum) cnt++;
    }
    return cnt;
}

int solution(int n, int k)
{
    string num = "";
    while(n > 0)
    {
        num = to_string(n % k) + num;
        n /= k;
    }
    
    stack<long long> s;
    string tmp = "";
    for(int i = 0; i < num.length(); ++i)
    {
        if(num[i] == '0' && !tmp.empty())
        {
            s.push(stoll(tmp));
            tmp = "";
        }
        else tmp += num[i];
    }
    if(!tmp.empty()) s.push(stoll(tmp));
    
    return primeNumCnt(s);
}