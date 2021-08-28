#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int a = 0; a < t; a++)
    {
        long long n,c;
        cin>>n>>c;
        
        vector<pair<long long, int>> arr; 
        for (int i = 0; i < n; i++)
        {
            long long l,r;
            cin>>l>>r;
            
            arr.push_back({l+1,1});
            arr.push_back({r,-1});
            
        }

        sort(arr.begin(), arr.end());

        vector<pair<long long, int>> arr2; 
        arr2.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr2.back().first==arr[i].first)
            {
                arr2.back().second += arr[i].second;
            }
            else{
                arr2.push_back(arr[i]);
            }
            
        }

        // cout<<endl;
        // for (int i = 0; i < arr2.size(); i++)
        // {
        //     cout<<arr2[i].first<<" "<<arr2[i].second<<endl;
        // }

        for (int i = 1; i < arr2.size(); i++)
        {
            arr2[i].second = arr2[i-1].second + arr2[i].second;
        }

        // cout<<endl;
        // for (int i = 0; i < arr2.size(); i++)
        // {
        //     cout<<arr2[i].first<<" "<<arr2[i].second<<endl;
        // }

        vector<pair<int, long long>> arr3;

        for (int i = 0; i < arr2.size()-1; i++)
        {
            arr3.push_back({arr2[i].second, arr2[i+1].first - arr2[i].first });
        }

        // cout<<endl;
        // for (int i = 0; i < arr3.size(); i++)
        // {
        //     cout<<arr3[i].first<<" "<<arr3[i].second<<endl;
        // }

        sort(arr3.begin(), arr3.end());
        // reverse(arr3.begin(), arr3.end());

        long long output =0;
        // cout<<endl;
        while (c > 0 and arr3.size()!=0)  
        {
            if (c >= arr3.back().second)
            {
                c = c - arr3.back().second;
                output += arr3.back().second * arr3.back().first;
                // cout<<output<<endl;
                arr3.pop_back();    
            }

            else{
                output += c * arr3.back().first;
                // cout<<output<<endl;
                c = c - arr3.back().second;
            }
        }

        output += n;
        cout<<"Case #"<<a+1<<": "<<output<<endl;
        
    }
    return 0;
}
