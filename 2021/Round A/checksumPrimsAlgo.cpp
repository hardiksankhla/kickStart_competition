#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n;
        cin >> n;
        
        vector<vector<int>> arr (n, vector<int> (n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        vector<vector<int>> cost (n, vector<int> (n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> cost[i][j];
            }
        }

        vector<vector<int>> chkSum (2, vector<int> (n, 0));
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < n; j++){
                cin >> chkSum[i][j];
            }
        }

        // End of Inputs

        // vector<vector<int>> matrix(2*n, vector<int>());
        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < n; j++){
        //         if (arr[i][j] == -1)
        //         {
        //             matrix[i].push_back(n + j);
        //             matrix[n + j].push_back(i);
        //         }
        //     }
        // }

        pair<int, pair<int, int>> maxEdge = {INT_MIN, {INT_MIN, INT_MIN}};

        vector<set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>>> matrix(2*n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (arr[i][j] == -1)
                {
                    matrix[i].insert({cost[i][j], {i, j}});
                    matrix[n + j].insert({cost[i][j], {i, j}});
                    maxEdge = max(maxEdge, {cost[i][j], {i, j}});
                }
            }
        }
        if (maxEdge.first == INT_MIN)
        {
            cout << "Case #" << a + 1 << ": " << 0 << endl;
            continue;
        }
        
        vector<bool> vis(2*n, false);
        set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>> q;
        set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>> remainingQ;
        q.insert(maxEdge);
        while (!q.empty())
        {   
            set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>> :: iterator itr;
            itr = q.begin();
            // cout<<itr->first<<" ("<<itr->second.first<<" "<<itr->second.second<<"); ";
            int index = itr->second.first;
            int index2 = itr->second.second + n;

            if (vis[index] and vis[index2])
            {
                remainingQ.insert(*itr);
                q.erase(*itr);
                continue;
            }

            if (!vis[index]){
                vis[index] = true;
                matrix[index].erase(*itr);
                set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>> :: iterator itr2;
                for (itr2 = matrix[index].begin(); itr2 != matrix[index].end(); itr2++){
                    q.insert(*itr2);
                }
            }
            
            if (!vis[index2]){
                vis[index2] = true;
                matrix[index2].erase(*itr);
                set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>> :: iterator itr2;
                for (itr2 = matrix[index2].begin(); itr2 != matrix[index2].end(); itr2++){
                    q.insert(*itr2);
                }
            }

            q.erase(*itr);
        }
        
        long long output = 0;
        // cout<<endl;
        set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>> :: iterator itr;
        for (itr = remainingQ.begin(); itr != remainingQ.end(); itr++)
        {
            output += itr->first;
            // cout<<itr->first<<" ("<<itr->second.first<<" "<<itr->second.second<<"); ";
        }
        
        cout << "Case #" << a + 1 << ": " << output << endl;
    }
    
    return 0;
}