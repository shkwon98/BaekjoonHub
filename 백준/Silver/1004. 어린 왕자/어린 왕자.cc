#include <iostream>

using namespace std;

bool inbound(int x1, int y1, int x2, int y2, int r)
{
    if ((x1 - x2) ^ (2) + (y1 - y2) ^ (2) < r ^ (2)) return true;
    else return false;
}
int main()
{
    int T;
    cin >> T;
    int ans[T] = { 0, };
    for (int i = 0; i < T; ++i)
    {
        int x_start, y_start, x_goal, y_goal;
        cin >> x_start >> y_start >> x_goal >> y_goal;

        int n;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            int x_planet, y_planet, r;
            cin >> x_planet >> y_planet >> r;

            if (((x_start - x_planet) * (x_start - x_planet) + (y_start - y_planet) * (y_start - y_planet) < r * r) && ((x_goal - x_planet) * (x_goal - x_planet) + (y_goal - y_planet) * (y_goal - y_planet) > r * r))
            {
                ans[i]++;
            }
            if (((x_start - x_planet) * (x_start - x_planet) + (y_start - y_planet) * (y_start - y_planet) > r * r) && ((x_goal - x_planet) * (x_goal - x_planet) + (y_goal - y_planet) * (y_goal - y_planet) < r * r))
            {
                ans[i]++;
            }
        }
    }
    for (int i = 0; i < T; ++i)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}