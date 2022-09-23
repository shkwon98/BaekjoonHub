#include <iostream>

using namespace std;

int a, b, c, d, e, f;

int main()
{
    cin >> a >> b;
    
    c = a * (b % 10);
    d = a * (b % 100 - b % 10) / 10;
    e = a * (b / 100);
    f = a * b;
    
    cout << c << "\n"
         << d << "\n"
         << e << "\n"
         << f;
    return 0;
}