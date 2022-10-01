#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int startIdx = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] - 'A' >= 0 && s[i] - 'Z' <= 0)
            s[i] = tolower(s[i]);
        
        if(s[i] == ' ')
        {
            if(s[startIdx] - 'a' >= 0 && s[startIdx] - 'z' <= 0)
                s[startIdx] = toupper(s[startIdx]);
            startIdx = i + 1;
        }
    }
    if(s[startIdx] - 'a' >= 0 && s[startIdx] - 'z' <= 0)
        s[startIdx] = toupper(s[startIdx]);
    
    answer = s;
    return answer;
}