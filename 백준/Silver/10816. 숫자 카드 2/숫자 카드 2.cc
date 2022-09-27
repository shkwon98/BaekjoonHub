#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, num;
vector<int> v;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        cin >> num;
        cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << " ";
    }

    return 0;
}