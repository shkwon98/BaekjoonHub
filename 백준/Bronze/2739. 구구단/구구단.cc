#include <iostream>
using namespace std;

int N;

int main()
{
    cin >> N;
    for (int i = 1; i < 10; ++i)
    {
        cout << N << " * " << i << " = " << N * i << "\n";
    }
    return 0;
}
