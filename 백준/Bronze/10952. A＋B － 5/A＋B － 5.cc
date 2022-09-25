#include <iostream>
using namespace std;

int A, B;

int main()
{
    while (1)
    {
        cin >> A >> B;
        if (!A && !B) break;
        cout << A + B << "\n";
    }
    
    return 0;
}