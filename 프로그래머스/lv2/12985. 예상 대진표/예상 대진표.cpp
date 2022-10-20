#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    int num = n;
    while(num > 1)
    {
        num /= 2;
        answer++;
    }
    
    int cp = n / 2;
    int d = cp / 2;
    while(answer > 1)
    {
        if(a <= cp && b <= cp)
        {
            cp -= d;
            d /= 2;
            answer--;
            continue;
        }
        if(a > cp && b > cp)
        {
            cp += d;
            d /= 2;
            answer--;
            continue;
        }
        
        break;
    }

    return answer;
}