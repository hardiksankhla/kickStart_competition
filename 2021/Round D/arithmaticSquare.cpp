#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int a = 0; a < t; a++)
    {
        vector<vector<int>> arr(3, vector<int>(3));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(i==1 and j==1){
                    continue;
                }
                cin>>arr[i][j];
            }
            
        }
    
        int ans1 = (arr[0][0]+arr[2][2])/2;
        int ans2 = (arr[0][2]+arr[2][0])/2;
        int ans3 = (arr[0][1]+arr[2][1])/2;
        int ans4 = (arr[1][0]+arr[1][2])/2;
        vector<pair<int,int>> sol;
        
        if (arr[0][0] - ans1 == ans1 - arr[2][2])
        {
            sol.push_back({1,ans1});
        }
        if (arr[0][2] - ans2 == ans2 - arr[2][0])
        {
            bool matched = false;
            for (int i = 0; i < sol.size(); i++)
            {
                if (sol[i].second==ans2)
                {
                    sol[i].first++;
                    matched = true;
                    break;
                }
                
            }
            if (!matched)
            {
                sol.push_back({1,ans2});
            } 
        }
        if (arr[0][1] - ans3 == ans3 - arr[2][1])
        {
            bool matched = false;
            for (int i = 0; i < sol.size(); i++)
            {
                if (sol[i].second==ans3)
                {
                    sol[i].first++;
                    matched = true;
                    break;
                }
                
            }
            if (!matched)
            {
                sol.push_back({1,ans3});
            } 
        }
        if (arr[1][0] - ans4 == ans4 - arr[1][2])
        {
            bool matched = false;
            for (int i = 0; i < sol.size(); i++)
            {
                if (sol[i].second==ans4)
                {
                    sol[i].first++;
                    matched = true;
                    break;
                }
                
            }
            if (!matched)
            {
                sol.push_back({1,ans4});
            } 
        }

        sort(sol.begin(), sol.end());
        reverse(sol.begin(), sol.end());
        // cout<<endl;
        // for (int i = 0; i < sol.size(); i++)
        // {
        //     cout<<sol[i].first<<" "<<sol[i].second<<endl;
        // }
        int count = 0;

        arr[1][1] = INT_MAX;
        if (sol.size())
        {
            arr[1][1] = sol[0].second;
        }
        
        if (arr[0][0] - arr[0][1] == arr[0][1] - arr[0][2])
        {
            count++;
        }
        if (arr[1][0] - arr[1][1] == arr[1][1] - arr[1][2])
        {
            count++;
        }
        if (arr[2][0] - arr[2][1] == arr[2][1] - arr[2][2])
        {
            count++;
        }

        if (arr[0][0] - arr[1][0] == arr[1][0] - arr[2][0])
        {
            count++;
        }
        if (arr[0][1] - arr[1][1] == arr[1][1] - arr[2][1])
        {
            count++;
        }
        if (arr[0][2] - arr[1][2] == arr[1][2] - arr[2][2])
        {
            count++;
        }

        if (arr[0][0] - arr[1][1] == arr[1][1] - arr[2][2])
        {
            count++;
        }
        if (arr[2][0] - arr[1][1] == arr[1][1] - arr[0][2])
        {
            count++;
        }

        cout<<"Case #"<<a+1<<": "<<count<<endl;
        
        
    }
    
    return 0;
}