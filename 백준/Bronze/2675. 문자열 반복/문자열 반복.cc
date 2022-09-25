#include <iostream>
#include <string>
using namespace std;

int T, R;
string S[1000];

int main()
{
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> R >> S[i];
        for(int j = 0; j < S[i].length(); ++j)
            for(int k = 0; k < R; ++ k)
                cout << S[i][j];
        cout << "\n";
    }
    return 0;
}
