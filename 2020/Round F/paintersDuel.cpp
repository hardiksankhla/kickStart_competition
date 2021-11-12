#include<bits/stdc++.h>
using namespace std;

int aMovesDuel(vector<vector<vector<pair<int, int> >>> &graph, int r1, int p1, int r2, int p2, vector<vector<bool>> &vis, int roomPaintedByA, int roomPaintedByB, bool aTraped, bool bTraped, int &output);
int bMovesDuel(vector<vector<vector<pair<int, int> >>> &graph, int r1, int p1, int r2, int p2, vector<vector<bool>> &vis, int roomPaintedByA, int roomPaintedByB, bool aTraped, bool bTraped, int &output);

int bMovesDuel(vector<vector<vector<pair<int, int> >>> &graph, int r1, int p1, int r2, int p2, vector<vector<bool>> &vis, int roomPaintedByA, int roomPaintedByB, bool aTraped, bool bTraped, int &output){
    if (aTraped and bTraped)
    {
        output = max(output, roomPaintedByA - roomPaintedByB);
        // cout<<"Room: "<<roomPaintedByA<<" "<<roomPaintedByB<<" "<<roomPaintedByA - roomPaintedByB<<endl;
        return roomPaintedByA - roomPaintedByB;
    }
    bool anyValidPath = false;
    int value=INT_MAX;
    for (int i = 0; i < graph[r2][p2].size(); i++)
    {
        if (!vis[graph[r2][p2][i].first][graph[r2][p2][i].second])
        {
            anyValidPath = true;
            vis[graph[r2][p2][i].first][ graph[r2][p2][i].second] = true;
            
            if (value==INT_MAX)
            {
                value = aMovesDuel(graph, r1, p1, graph[r2][p2][i].first, graph[r2][p2][i].second, vis, roomPaintedByA, roomPaintedByB + 1, aTraped, bTraped, output);
            }
            else
            {
                value = min(value, aMovesDuel(graph, r1, p1, graph[r2][p2][i].first, graph[r2][p2][i].second, vis, roomPaintedByA, roomPaintedByB + 1, aTraped, bTraped, output) );
            }
            
            vis[graph[r2][p2][i].first][ graph[r2][p2][i].second] = false;
        }
    }
    if (anyValidPath == false)
    {
        bTraped = true;
        value = aMovesDuel(graph, r1, p1, r2, p2, vis, roomPaintedByA, roomPaintedByB, aTraped, bTraped, output);
    }
    return value;
}


int aMovesDuel(vector<vector<vector<pair<int, int> >>> &graph, int r1, int p1, int r2, int p2, vector<vector<bool>> &vis, int roomPaintedByA, int roomPaintedByB, bool aTraped, bool bTraped, int &output){
    if (aTraped and bTraped)
    {
        output = max(output, roomPaintedByA - roomPaintedByB);
        // cout<<"Room: "<<roomPaintedByA<<" "<<roomPaintedByB<<" "<<roomPaintedByA - roomPaintedByB<<endl;
        return roomPaintedByA - roomPaintedByB;
    }
    bool anyValidPath = false;
    int value=INT_MIN;
    for (int i = 0; i < graph[r1][p1].size(); i++)
    {
        if (!vis[graph[r1][p1][i].first][graph[r1][p1][i].second])
        {
            anyValidPath = true;
            vis[graph[r1][p1][i].first][ graph[r1][p1][i].second] = true;

            if (value==INT_MIN)
            {
                value = bMovesDuel(graph, graph[r1][p1][i].first, graph[r1][p1][i].second, r2, p2,  vis, roomPaintedByA + 1, roomPaintedByB, aTraped, bTraped, output);
            }
            else
            {
                value = max(value, bMovesDuel(graph, graph[r1][p1][i].first, graph[r1][p1][i].second, r2, p2,  vis, roomPaintedByA + 1, roomPaintedByB, aTraped, bTraped, output) );   
            }

            vis[graph[r1][p1][i].first][ graph[r1][p1][i].second] = false;
        }
    }
    if (anyValidPath == false)
    {
        aTraped = true;
        value = bMovesDuel(graph, r1, p1, r2, p2, vis, roomPaintedByA, roomPaintedByB, aTraped, bTraped, output);
    }
    return value;
}



int main(int argc, char const *argv[])
{
    int t;
    cin >>t;
    for (int a = 0; a < t; a++)
    {
        int s, r1, p1, r2, p2, c;
        cin >> s >> r1 >> p1 >> r2 >> p2 >> c;
        r1--;
        p1--;
        r2--;
        p2--;

        vector<vector<vector<pair<int, int> >>> graph(s, vector<vector<pair<int, int>>>(2*s));

        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < 2 * i + 1; j++)
            {
                if (j > 0)
                {
                    graph[i][j].push_back({i, j - 1});
                }
                if (j < 2 * i)
                {
                    graph[i][j].push_back({i, j + 1});
                }
                if (i < s - 1)
                {
                    if (j % 2 == 0)
                    {
                        graph[i][j].push_back({i+1, j+1});
                    }
                }
                if (i > 0)
                {
                    if (j % 2 != 0)
                    {
                        graph[i][j].push_back({i - 1, j - 1});
                    }
                }
            }
        }

        // for (int i = 0; i < s; i++)
        // {
        //     for (int j = 0; j < 2 * i + 1; j++)
        //     {   
        //         cout<<""<<i<<","<<j<<":";
        //         for (int k = 0; k < graph[i][j].size(); k++)
        //         {
        //             cout<<" {"<<graph[i][j][k].first<<", "<<graph[i][j][k].second<<"}";     
        //         }
        //         cout<<";   ";
        //     }
        //     cout<<endl;
        // }

        vector<vector<bool>> vis(s, vector<bool> (2*s, false));
        for (int i = 0; i < c; i++)
        {
            int r, p;
            cin >> r >> p;
            r--;
            p--;
            vis[r][p] = true;
        }
        
        // pair<int, int> alma = {r1, p1};
        // pair<int, int> berthe = {r2, p2};
        vis[r1][p1] = true;
        vis[r2][p2] = true;

        int output = INT_MIN; //maxmimum possible score
        
        int output2 = aMovesDuel(graph, r1, p1, r2, p2, vis, 1, 1, false, false, output); //maximum possible score when berthe competes;

        // cout << "Case #" << a + 1 << ": " << output << " " << output2 << endl;
        cout << "Case #" << a + 1 << ": " << output2 << endl;
    }
    
    return 0;
}