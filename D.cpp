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

        int x = 0;
        int y = 0;

        for(int i = 0; i < n; i++)
        {
            int num;
            cin >> num;

            int temp = max(num + x, y);
            x = y;
            y = temp;
        }
        cout << y << endl;
    }
}