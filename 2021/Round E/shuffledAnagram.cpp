#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    for (int a = 0; a < t; a++)
    {
        string s;
        cin>>s;
        int n = s.length();
        vector<int> arr(256,0);

        for (int i = 0; i < n; i++)
        {
            arr[s[i]]++;
        }

        int maxAlpha = INT_MIN;
        for (int i = 0; i < 256; i++)
        {
            maxAlpha = max(maxAlpha, arr[i]);
        }

        string output ="";

        if (2*maxAlpha > n){
            output = "IMPOSSIBLE";
        }
        else{
            vector<char> temp(n,'a');
            vector<pair<char, int>> s2(n);

            for (int i = 0; i < n; i++)
            {
                s2[i] = {s[i],i};
            }

            sort(s2.begin(),s2.end());

            for (int i = 0; i < n; i++)
            {
                temp[s2[(i+n/2)%n].second] = s2[i].first;
            }

            for (int i = 0; i < n; i++)
            {
                output+=temp[i];   
            }
        }
        cout<<"Case #"<<a+1<<": "<<output<<endl;
    }
    return 0;
}