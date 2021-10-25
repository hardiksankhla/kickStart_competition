#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int count = 0;
        for (int i = 0; i < n/2; i++){
            if (s[i] != s[n-1-i]){
                count++;
            }
        }
        int output = abs(count-k);
        cout << "Case #" << a + 1 << ": " << output << endl;
    }
    return 0;
}