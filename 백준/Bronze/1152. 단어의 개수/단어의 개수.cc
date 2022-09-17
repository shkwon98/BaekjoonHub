#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int wordCount = 1;
    
    getline(cin, str);
    
    if(str[0] == ' ') wordCount--;
    
    for(int i = 0; i < str.length(); ++i)
    {
        if((str[i] == ' ') && str[i + 1])
        {
            wordCount++;
        }
    }
    
    cout << wordCount;
    return 0;
}