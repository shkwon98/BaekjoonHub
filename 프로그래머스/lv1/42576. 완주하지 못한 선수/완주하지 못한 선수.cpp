#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_map<string, int> people;
    
    for(int i = 0; i < participant.size(); ++i)
    {
        if(people.find(participant[i]) == people.end()) people[participant[i]] = 1;
        else people[participant[i]]++;
    }
    
    for(int i = 0; i < completion.size(); ++i)
        people[completion[i]]--;
    
    for(auto key : participant)
    {
        if(people[key] > 0)
        {
            answer = key;
            break;
        }
    }
        
    
    return answer;
}