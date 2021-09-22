#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        int n;
        string s;
        cin >> n >> s;
        vector<pair<int , int>> v(n, {1e7, 1e7});

        for (int i = 0; i < n - 1; i++){
            if(s[i] == '1'){
                v[i].first = 0;
            }
            v[i + 1].first = v[i].first + 1;
        }

        for (int i = n - 1; i > 0; i--){
             if(s[i] == '1'){
                v[i].second = 0;
            }
            v[i - 1].second = v[i].second + 1;
        }

        long long output = 0;
        
        for (int i = 0; i < n; i++)
        {
            output += min(v[i].first, v[i].second);
        }

        if(n == 1){
            output = 0; 
        }

        cout<<"Case #"<<a+1<<": "<<output<<endl;
    }
    return 0;
}