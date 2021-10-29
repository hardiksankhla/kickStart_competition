#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    for (int a = 0; a < t; a++)
    {
        int n, k, modulo = 1e9+7;
        string s;
        cin >> n >> k >> s;

        int output = 0;

        for (int i = 0; i < (n + 1) / 2; i++){
            output += (int)((s[i] - 'a') * pow(k, (n - 1) / 2 - i)) % modulo;
            output %= modulo;
        }

        string tmp = "";

        for (int i = 0; i < (n + 1) / 2; i++){
            tmp += s[i];
        }
        for (int  i = (n + 1) / 2; i < n; i++){
            tmp += s[n - 1 - i];
        }

        // cout << tmp << endl;
        
        if (tmp < s){
            output++;
        }
        output %= modulo;
        
        cout << "Case #" << a + 1 << ": " << output << endl;
    }
    
    return 0;
}