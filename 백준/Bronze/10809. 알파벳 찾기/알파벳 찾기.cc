#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string word;
int alpha[26];

int main()
{
    cin >> word;
    memset(alpha, -1, sizeof(alpha));
    for(int i = 0; i < word.length(); ++i)
    {
        for(int j = 0; j < 26; ++j)
        {
            if(word[i] - 'a' == j && alpha[j] == -1) alpha[j] = i;
        }
    }
    
    for(int j = 0; j < 26; ++j)
    {
        cout << alpha[j] << " ";
    }
    return 0;
}
