#include <iostream>
#include <queue>
using namespace std;

int truckNum, bridgeLen, maxWeight, truck;
int cnt = 0, weight = 0;
queue<int> qWaiting, qCrossing;

int main()
{
    cin >> truckNum >> bridgeLen >> maxWeight;
    for(int i = 0; i < truckNum; ++i)
    {
        cin >> truck;
        qWaiting.push(truck);
    }

    int temp = qWaiting.front();
    qWaiting.pop();
    qCrossing.push(temp);
    weight += temp;
    cnt++;
    while(weight != 0)
    {
        if(qCrossing.size() == bridgeLen)
        {
            temp = qCrossing.front();
            qCrossing.pop();
            weight -= temp;
        }
        while(qCrossing.size() < bridgeLen)
        {
            temp = qWaiting.front();
            if(!qWaiting.empty() && weight + temp <= maxWeight)
            {
                qWaiting.pop();
                qCrossing.push(temp);
                weight += temp;
            }
            else
                qCrossing.push(0);
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}