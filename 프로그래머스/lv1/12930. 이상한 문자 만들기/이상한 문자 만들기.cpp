#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    int cnt = 0;
    
    for(int i = 0; i < s.length(); ++i)
    {
        char curr = s[i];
        
        if(curr == ' ')
        {
            answer += curr;
            cnt = 0;
            continue;
        }
        
        if(cnt % 2) answer += tolower(curr);
        else answer += toupper(curr);
        
        cnt++;
    }
    
    return answer;
}