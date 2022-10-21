#include <string>

using namespace std;

int arr[60001];

int fibo(int cnt)
{
    if(arr[cnt] != 0) return arr[cnt];
    
    else if(cnt == 1)
    {
        arr[1] = 1;
        return 1;
    }
    
    else if(cnt == 2)
    {
        arr[2] = 2;
        return 2;
    }
    
    arr[cnt] = (fibo(cnt - 1) + fibo(cnt - 2)) % 1000000007;
    return arr[cnt];
}

int solution(int n)
{
    int answer = 0;
    
    answer = fibo(n);
    
    return answer;
}