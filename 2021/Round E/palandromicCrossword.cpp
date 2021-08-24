#include<bits/stdc++.h>
using namespace std;

void fillvertical(int i, int j, int &count, vector<vector<char>> &crossword, vector<vector<pair<bool,bool>>> &visited);
void fillhorizontal(int i, int j, int &count, vector<vector<char>> &crossword, vector<vector<pair<bool,bool>>> &visited);

void fillvertical(int i, int j, int &count, vector<vector<char>> &crossword, vector<vector<pair<bool,bool>>> &visited){
    if (visited[i][j].first)
    {
        return;
    }
    
    visited[i][j].first = true;
    int starti=i,endi=i;
    int n = crossword.size();
      
    for (int k = i+1; k < n; k++)
    {
        if (crossword[k][j]=='#')
        {
            break;
        }
        endi++;
    }

    for (int k = i-1; k >= 0; k--)
    {
        if (crossword[k][j]=='#')
        {
            break;
        }
        starti--;
    }

    // cout<<"start = "<<starti<<" end = "<<endi<<endl;
    if (crossword[endi+starti-i][j]=='.')
    {
        crossword[endi+starti-i][j] = crossword[i][j];
        visited[endi+starti-i][j].first = true;
        count++;
        fillhorizontal(endi+starti-i, j, count, crossword, visited);
    }
}

void fillhorizontal(int i, int j, int &count, vector<vector<char>> &crossword, vector<vector<pair<bool,bool>>> &visited){
    if (visited[i][j].second)
    {
        return;
    }
    
    visited[i][j].second = true;
    int startj=j,endj=j;
    int n = crossword[i].size();
    
    for (int k = j+1; k < n; k++)
    {
        if (crossword[i][k]=='#')
        {
            break;
        }
        endj++;
    }

    for (int k = j-1; k >= 0; k--)
    {
        if (crossword[i][k]=='#')
        {
            break;
        }
        startj--;
    }

    // cout<<"start = "<<startj<<" end = "<<endj<<endl;
    if (crossword[i][endj+startj-j]=='.')
    {
        crossword[i][endj+startj-j] = crossword[i][j];
        visited[i][endj+startj-j].second = true;
        count++;
        fillvertical(i, endj+startj-j, count, crossword, visited);
    }
}

int main(){
    int t;
    cin>>t;
    for (int a = 0; a < t; a++)
    {
        int n,m, count;
        cin>>n>>m;
        count =0;
        vector<vector<char>> crossword(n, vector<char> (m));
        vector<vector<pair<bool,bool>>> visited(n, vector<pair<bool,bool>> (m,{false,false}));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>crossword[i][j];
            }
            
        }

        // cout<<"crossword is : "<<endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout<<crossword[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {   
                if (crossword[i][j]!='#' and crossword[i][j]!='.')
                {
                    if (visited[i][j].first==false)
                    {
                        fillvertical(i, j, count, crossword, visited);
                    }
                    if (visited[i][j].second==false)
                    {
                        fillhorizontal(i, j, count, crossword, visited);
                    } 
                }
            }
        }

        // cout<<endl;
        cout<<"Case #"<<a+1<<": "<<count<<endl;
        // cout<<"final crossword is : "<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout<<crossword[i][j];
            }
            cout<<endl;
        }
        // cout<<endl;
    }
    return 0;
}