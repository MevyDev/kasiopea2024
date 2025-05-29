#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t > 0)
    {
        t--;
        int n;
        cin >> n;
        unordered_map<int, vector<int>> graph;
        vector<int> teams(n + 1, 0);
        vector<bool> visited(n + 1, false);
        vector<int> res(n - 1, 0);
        graph.clear();
        for (int i = 1; i < n; i++)
        {
            cin >> teams[i];
        }
        for (int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<stack<int>> closest(n+1);
        stack<int> stk;
        stack<int> depth;

        stk.push(n);
        depth.push(0);
        stack<int> path;

        while (!stk.empty())
        {
            int cur = stk.top();
            int dist = depth.top();

            while(path.size() > dist)
            {
                closest[path.top()].pop();
                path.pop();
            }

            stk.pop();
            depth.pop();
            visited[cur] = true;
            if (cur != n)
            {
                if(closest[cur].empty())
                {
                    res[cur - 1] = dist;
                }
                else
                {
                    res[cur - 1] = dist - closest[cur].top();
                }
            }
            closest[cur].push(dist);
            path.push(cur);
            for (int node : graph[cur])
            {
                if (!visited[node])
                {
                    stk.push(node);
                    depth.push(dist + 1);
                }
            }
        }
        for (int num : res)
        {
            cout << num << " ";
        }

        cout << endl;
    }
}
