#include<bits/stdc++.h>
using namespace std;

void dfsTraverse(int root, vector<vector<int>> &graph, vector<int> &path, int A, int B, vector<int> &countA, vector<int> &countB)
{
    // cout<<root<<" ";
    path.push_back(root);

    // for (int i = 0; i < path.size(); i++)
    // {
    //     cout<<path[i]<<" ";
    // }
    // cout<<endl;
    
    for (int i = 0; i < graph[root].size(); i++)
    {
        dfsTraverse(graph[root][i], graph, path, A, B, countA, countB);
    }

    countA[path.back()] ++;
    if (path.size() > A)
    {
        // cout << root << " " << path[path.size() - 1 - A] << "; " << A << endl;
        countA[path[path.size() - 1 - A]] += countA[path.back()];
    }
    
    countB[path.back()] ++;
    if (path.size() > B)
    {
        // cout << root << " " << path[path.size() - 1 - B] << "; " << B << endl;
        countB[path[path.size() - 1 - B]] += countB[path.back()];
    }
    
    path.pop_back();
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        int n, A, B;
        cin >> n >> A >> B;

        vector<vector<int>> graph(n + 1);

        for (int i = 0; i < n-1; i++)
        {
            int tmp;
            cin >> tmp;
            graph[tmp].push_back(i+2);
        }

        // for (int i = 0; i < graph.size(); i++)
        // {
        //     cout<<i<<" : ";
        //     for (int j = 0; j < graph[i].size(); j++)
        //     {
        //         cout<<graph[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<int> path;
        vector<int> countA(n + 1, 0);
        vector<int> countB(n + 1, 0);
        
        dfsTraverse(1, graph, path, A, B, countA, countB);

        // for (int i = 0; i < countA.size(); i++)
        // {
        //     cout << countA[i] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i < countB.size(); i++)
        // {
        //     cout << countB[i] << " ";
        // }
        // cout << endl;
        
        long double output = 0;

        for (int i = 0; i < n+1; i++)
        {
            output += n * (countA[i] + (long long)countB[i]) - countA[i] * (long long)countB[i];
        }
        output /= n;
        output /= n;

        cout.precision(10);
        cout << "Case #" << a + 1 << ": " << output << endl;
        
    }
    
    return 0;
}
