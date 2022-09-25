#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num[2];
int n[2];

int main()
{
    cin >> num[0] >> num[1];
    
    reverse(num[0].begin(), num[0].end());
    reverse(num[1].begin(), num[1].end());

    n[0] = stoi(num[0]);
    n[1] = stoi(num[1]);
    
    if (n[0] > n[1])
        cout << n[0];
    else
        cout << n[1];
    
    return 0;
}