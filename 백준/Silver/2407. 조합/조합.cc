#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string combVal[101][101];

string addComb(string a, string b)
{
    if (a.length() > b.length())
    {
        while (a.length() != b.length())
        {
            b = '0' + b;
        }
    }
    else
    {
        while (a.length() != b.length())
        {
            a = '0' + a;
        }
    }

    string result = "";
    int sum = 0;
    for (int i = a.length() - 1; i >= 0; --i)
    {
        sum += a[i] - '0';
        sum += b[i] - '0';
        result = to_string(sum % 10) + result;
        if (sum > 9) sum = 1;
        else sum = 0;
    }
    if (sum == 1) result = "1" + result;

    return result;
}

string comb(int n, int m)
{
    if (combVal[n][m] != "") return combVal[n][m];
    if (n == m || m == 0) return "1";

    combVal[n][m] = addComb(comb(n - 1, m - 1), comb(n - 1, m));
    return combVal[n][m];
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << comb(n, m);
    return 0;
}