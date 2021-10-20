#include<bits/stdc++.h>
using namespace std;

int n = 60;
int w, e;

double rec(int round, int r, int p, vector<vector<vector<double>>> &dp, vector<vector<vector<bool>>> &vis, vector<vector<vector<char>>> &bestChoice){
    if (round == n)
    {
        return 0;
    }
    if (vis[round][r][p]==1)
    {
        return dp[round][r][p];
    }
    vis[round][r][p] = 1;

    int s = round - r - p;
    double probR, probP, probS;
    
    if (round == 0)
    {
        probR = probP =  probS = 1.0/3;
    }
    else
    {
        probR = (1.0 * s) / round;
        probP = (1.0 * r) / round;
        probS = (1.0 * p) / round;
    }
    
    double ans = 0, tmp = 0;
    char c;
    //rock
    tmp =  probS * (w + rec(round+1, r+1, p, dp, vis, bestChoice)) + probR * (e +  rec(round+1, r+1, p, dp, vis, bestChoice)) + probP * rec(round+1, r+1, p, dp, vis, bestChoice) ;  
    if (tmp > ans)
    {
        ans = tmp;
        c = 'R';  
    }
    
    //paper 
    tmp = probR * (w + rec(round+1, r, p+1, dp, vis, bestChoice)) + probP * (e +  rec(round+1, r, p+1, dp, vis, bestChoice)) + probS * rec(round+1, r, p+1, dp, vis, bestChoice) ;  
    if (tmp > ans)
    {
        ans = tmp;
        c = 'P';  
    }
    //scisor
    tmp = probP * (w + rec(round+1, r, p, dp, vis, bestChoice)) + probS * (e +  rec(round+1, r, p, dp, vis, bestChoice)) + probR * rec(round+1, r, p, dp, vis, bestChoice) ;  
    if (tmp > ans)
    {
        ans = tmp;
        c = 'S';  
    }
    bestChoice[round][r][p] = c;
    return dp[round][r][p] = ans;
}

int main(){
    int t, x;
    cin >> t >> x;
    for (int a = 0; a < t; a++)
    {
        
        cin >> w >> e;

        vector<vector<vector<double>>> dp (n, vector<vector<double>> (n, vector<double> (n, -1) ) );
        vector<vector<vector<bool>>> vis (n, vector<vector<bool>> (n, vector<bool> (n, 0) ) );
        vector<vector<vector<char>>> bestChoice (n, vector<vector<char>> (n, vector<char> (n) ) );
        rec(0, 0, 0, dp, vis, bestChoice);
        cout<<"Case #"<<a+1<<": ";
        int r = 0, p = 0;
        for (int i = 0; i < n; i++)
        {
            char c = bestChoice[i][r][p];
            cout<<c;
            if (c=='R')
            {
                r++;
            }
            if (c=='P')
            {
                p++;
            }   
        }
        cout<<endl;
    }
    return 0;
}