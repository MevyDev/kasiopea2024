#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long buildable(long long logDays, long long days, long long logPerDay, long long cost, long long maxPerDay)
{
    long long beforeBuilding = (logDays - 1) * (logDays) * logPerDay / 2;
    long long afterBuilding = (days - logDays) * logPerDay * logDays;
    long long housesBuilt = (beforeBuilding + afterBuilding) / cost;
    long long maxHouses = maxPerDay * (days - logDays);
    return min(maxHouses, housesBuilt);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long t;
    cin >> t;
    while (t > 0)
    {
        t--;
        long long days, logPerDay, cost, maxPerDay;
        cin >> days >> logPerDay >> cost >> maxPerDay;

        long long left = 1; long long right = days - 1;
        while(left < right)
        {
            long long mid = left + (right - left) / 2;
            long long a = buildable(mid, days, logPerDay, cost, maxPerDay);
            long long b = buildable(mid + 1, days, logPerDay, cost, maxPerDay);

            if (a < b)
            {
                left = mid + 1;
            }
            else if (a > b)
            {
                right = mid;
            }
            else
            {
                long long maxVal = 0;
                for(long long i = left; i < right + 1; i++)
                {
                    long long temp = buildable(i, days, logPerDay, cost, maxPerDay);
                    if(maxVal < temp)
                    {
                        maxVal = temp;
                        left = i;
                    }
                }
                right = left;
            }
        }
        cout << buildable(left, days, logPerDay, cost, maxPerDay) << '\n';
    }
}
