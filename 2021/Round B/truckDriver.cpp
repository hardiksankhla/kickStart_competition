#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        int n, q;
        cin >> n >> q;

        vector<vector<pair<long long, pair<long long, long long> >>> graph(n + 1, vector<pair<long long, pair<long long, long long> >>());

        for (int i = 0; i < n - 1; i++)
        {
            long long n1, n2, l, c;   // node1, node2, load, cost;
            cin >> n1 >> n2 >> l >> c;
            graph[n1].push_back({n2, {l, c}});
            graph[n2].push_back({n1, {l, c}});
        }

        queue<int> que; 
        que.push(1);
        vector<pair<long long, pair<long long, long long> > > parentOf(n + 1, {0, {0, 0}});
        parentOf[1] = {1, {0, 0}};

        while (!que.empty())
        {
            int front = que.front();
            // cout << front << " " << graph[front].size() << endl;
            for (int i = 0; i < graph[front].size(); i++)
            {   
                if (parentOf[graph[front][i].first].first == 0)
                {
                    parentOf[graph[front][i].first] = {front, {graph[front][i].second.first, graph[front][i].second.second}};
                    que.push(graph[front][i].first);
                }
            }
            que.pop();
        }

        // for (int i = 0; i < parentOf.size(); i++)
        // {
        //     cout << i << "->" << parentOf[i].first << " " << parentOf[i].second.first << " " << parentOf[i].second.second << "; ";
        // }
        
        cout << "Case #" << a + 1 << ":";

        for (int i = 0; i < q; i++)
        {
            int c, w;
            cin >> c >> w;

            long long gcd1 = 0;

            while (c != 1)
            {    
                if (w >= parentOf[c].second.first)
                {
                    // cout<<parentOf[c].second.second<<endl;
                    gcd1 = __gcd(gcd1, parentOf[c].second.second);
                }
                c = parentOf[c].first;
            }
            cout<<" "<<gcd1;
        }
        cout<<endl;
    }
    return 0;
}