#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s(nums.begin(), nums.end());
    return min(s.size(), nums.size() / 2);;
}