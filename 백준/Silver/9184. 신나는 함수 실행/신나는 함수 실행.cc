#include <iostream>
#include <vector>
#define SIZE 21
using namespace std;

int store[SIZE][SIZE][SIZE];
int n1, n2, n3;

int w(int a, int b, int c)
{
    if( a <= 0 || b <= 0 || c <= 0 )
        return 1;
    if( a > 20 || b > 20 || c > 20 )
        return w(20, 20, 20);
    
    if(store[a][b][c])
        return store[a][b][c];
    else if( a < b && b < c )
    {
        store[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return store[a][b][c];
    }
    else
    {
        store[a][b][c] =  w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return store[a][b][c];
    }
}

int main()
{   
    while(1)
    {
        cin >> n1 >> n2 >> n3;
        if( n1 == -1 && n2 == -1 && n3 == -1 )
            break;
        
        cout << "w(" << n1 << ", " << n2 << ", " << n3 << ") = " << w(n1, n2, n3) << "\n";
    }
        
    return 0;
}