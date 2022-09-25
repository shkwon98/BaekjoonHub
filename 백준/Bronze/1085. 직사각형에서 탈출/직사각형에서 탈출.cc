#include <iostream>
#include <algorithm>
using namespace std;

int x, y, w, h;
int ans;

int main()
{
    cin >> x >> y >> w >> h;
    ans = min(min(x, y), min(w - x, h - y));
    cout << ans;
    return 0;
}