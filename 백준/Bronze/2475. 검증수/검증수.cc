#include <iostream>
using namespace std;

int n[5], chk;
int temp = 0;

int main()
{
    for(int  i = 0; i < 5; ++i)
    {
        cin >> n[i];
        temp += n[i] * n[i];
    }
    chk = temp % 10;
    cout << chk;
    
    return 0;
}
