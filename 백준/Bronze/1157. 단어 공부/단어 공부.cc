#include <iostream>
using namespace std;

string input;
int alphabet[26] = {};

int main()
{
    cin >> input;
    for (int i = 0; i < input.length(); ++i)
    {
        if (input[i] < 97)
            alphabet[input[i] - 65]++;
        else
            alphabet[input[i] - 97]++;
    }
    
    int max = 0, maxIdx = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (alphabet[i] > max)
        {
            max = alphabet[i];
            maxIdx = i;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (alphabet[i] == max)
            cnt++;
    }
    
    if (cnt > 1)
        cout << "?";
    else
        cout << (char)(maxIdx + 65);
    
    return 0;
}
