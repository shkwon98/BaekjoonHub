#include <iostream>

using namespace std;

int N;
int score[1001];
float high = 0.0;
int sum = 0;
float avg;

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> score[i];
        sum += score[i];
        
        if(score[i] > (int)high)
            high = score[i] * 1.0;
    }
    
    avg = (sum / high * 100) / N;
    cout << avg;
    
    return 0;
}
