#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while(t > 0)
    {
        t--;

        int res = 0;

        int n, x, y, k;
        cin >> n >> x >> y >> k;

        while (n > 0)
        {
            if (y < x * min(n, k))
            {
                n -= k;
                res += y;
            }
            else
            {
                n--;
                res += x;
            }
        }
        cout << res << endl;
    }
}