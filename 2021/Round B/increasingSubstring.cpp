#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a++){
        int n;
        string s;
        cin >> n >> s;
        
        vector<int> output(n, 1);
        for (int i = 1; i < n; i++){
            if (s[i] > s[i - 1]){
                output[i] = output[i - 1] + 1;
            }
        }
        
        cout << "Case #" << a + 1 << ":";
        for (int i = 0; i < n; i++){
            cout << " " << output[i];
        }
        cout << endl;
    }
    return 0;
}