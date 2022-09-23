#include <iostream>
#include <string>

using namespace std;

int n;
int tempScore = 0;
int totalScore = 0;

int main()
{
    cin >> n;
    string answer[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> answer[i];
        for(int idx = 0; idx < answer[i].length(); ++idx)
        {
            if(answer[i][idx] == 'O')
                tempScore++;
            else
                tempScore = 0;
            totalScore += tempScore;
        }
        cout << totalScore << "\n";
        
        totalScore = 0;
        tempScore = 0;
    }
    
    return 0;
}
