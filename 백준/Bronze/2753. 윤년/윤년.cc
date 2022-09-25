#include <iostream>
using namespace std;

int N;

int main()
{
    cin >> N;
    if((!(N % 4) && N % 100) || !(N % 400)) cout << 1;
    else cout << 0;
    return 0;
}