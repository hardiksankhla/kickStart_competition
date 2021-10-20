#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for (int a = 0; a < t; a++){
        int n, k;
        cin >> n >> k;

        vector<long long> b(n, 0);
        for (int i = 0; i < n; i++){
            cin >> b[i]; 
        }

        vector<long long> sumArr(n + 1, 0);
        for (int i = 0; i < n; i++){
            sumArr[i + 1] = sumArr[i] + b[i];
        }

        vector<long long> noOfTree(k + 1, INT_MAX); // no. of trees for no. of bananas

        for (int i = 0; i < n; i++){
            for (int  j = 0; j <= i; j++){
                long long sum = sumArr[i] - sumArr[j];
                if (sum <= k){
                    noOfTree[sum] = min(noOfTree[sum], (long long)(i - j));
                } 
            }
            for (int j = i + 1; j <= n; j++){
                long long sum = sumArr[j] - sumArr[i];
                if (sum <= k){
                    noOfTree[k] = min(noOfTree[k], noOfTree[k - sum] + j - i);
                } 
            }
        }
        
        if (noOfTree[k] == INT_MAX){
            noOfTree[k] = -1;
        }
        cout << "Case #" << a + 1 << ": " << noOfTree[k] << endl;
    }
    return 0;
}