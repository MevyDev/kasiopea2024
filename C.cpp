#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while(t > 0)
    {
        t--;

        int n;
        cin >> n;

        unordered_map<int, int> maxMap;

        int maxCount = 0;

        for(int i = 0; i < n; i++)
        {
            int size;
            cin >> size;
            maxMap[size]++;
            maxCount = max(maxCount, maxMap[size]);
        }
        cout << maxCount << endl;
    }
}