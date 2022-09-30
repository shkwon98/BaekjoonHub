#include <iostream>
#include <vector>
using namespace std;

int N;
int term[16], pay[16];
int total = 0;

void func(int day, int sum)
{    
    if(day > N)
    {
        total = max(total, sum);
        return;
    }

    int nextStartDay = day + term[day];
    for(int j = nextStartDay; j <= N + 1; ++j)
    {
        func(j, sum + pay[day]);
    }
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> term[i] >> pay[i];

    for(int i = 1; i <= N; ++i)
        func(i, 0);

    cout << total;
    return 0;
}
