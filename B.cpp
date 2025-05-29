#include <iostream>
#include <vector>

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

        int firstBook = -1;
        int lastBook = -1;
        int spaceCount = 0;

        for(int i = 0; i < n; i++)
        {
            char pos;
            cin >> pos;
            if(firstBook == -1)
            {
                if(pos == 'K') firstBook = i;
            }
            else
            {
                if(pos != 'K') spaceCount++;
            }
            if(pos == 'K')
            {
                lastBook = i;
            }
        }
        if(firstBook == lastBook) cout << 0 << endl;
        else
        {
            cout << spaceCount - (n - lastBook - 1) << endl;
        }
    }
}