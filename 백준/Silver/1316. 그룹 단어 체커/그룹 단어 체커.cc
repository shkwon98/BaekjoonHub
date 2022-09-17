#include <iostream>
#include <string>

using namespace std;

bool checkGroupWord(string word)
{
    bool isGroupWord = true;
    for(int i = 0; i < word.length(); ++i)
    {
        if(word[i] != word[i + 1])
        {
            for(int j = i + 2; j < word.length(); ++j)
            {
                if(word[i] == word[j])
                {
                    isGroupWord = false;
                }
            }
        }
    }
    return isGroupWord;
}

int main()
{
    int nTotal;
    string word;
    cin >> nTotal;
    
    int nGroupWord = nTotal;
    for(int i = 0; i < nTotal; ++i)
    {
        cin >> word;
        if(!checkGroupWord(word)) nGroupWord--;
    }

    cout << nGroupWord;
    return 0;
}