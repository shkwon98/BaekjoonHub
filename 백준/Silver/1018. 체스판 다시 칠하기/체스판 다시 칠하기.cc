#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    char arr[N][M];
    char ex1[8] = { 'W','B','W','B','W','B','W','B' };
    char ex2[8] = { 'B','W','B','W','B','W','B','W' };
    int cnt1 = 0;
    int cnt2 = 0;
    int tempAns;
    int ans = 50 * 50;
    int x = 0;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i <= N - 8; i++)
    {
        for(int j = 0; j <= M - 8; j++)
        {
            for(int row = i; row < i + 8; row+=2)
            {
                for(int col = j; col < j + 8; col++)
                {
                    if(arr[row][col] != ex1[x])     cnt1++;
                    if(arr[row + 1][col] != ex2[x]) cnt1++;
                    if(arr[row][col] != ex2[x])     cnt2++;
                    if(arr[row + 1][col] != ex1[x]) cnt2++;
                    x++;
                }
                x = 0;
            }
            if(cnt1 > cnt2) tempAns = cnt2;
            else tempAns = cnt1;
            if(ans > tempAns) ans = tempAns;
            cnt1 = 0;
            cnt2 = 0;
        }
    }

    cout << ans;
    return 0;
}