#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    for (int a = 0; a < t; a++){
        int n;
        cin >> n;
        
        vector<int> arr(n, 0);
        
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        vector<int> diff(n - 1, INT_MAX);
        
        for (int i = 0; i < n - 1; i++){
            diff[i] = arr[i + 1] - arr[i];
        }

        set<pair<int, pair<int, int>>> diffSet;
        pair<int, pair<int, int>> tmp = {INT_MAX, {INT_MAX, INT_MAX}};
        
        for (int i = 0; i < n - 1; i++){
            if (tmp.first != diff[i]){
                diffSet.insert(tmp);
                tmp.first = diff[i];
                tmp.second.first = i;
                tmp.second.second = i + 1;
            }
            else{
                tmp.second.second = i + 1;
            }
        }
        diffSet.insert(tmp);
        
        auto tmpItr = diffSet.begin();
        int output = 0;

        for (auto itr = diffSet.begin(); itr != diffSet.end(); itr++){
            // cout << itr->first << " (" << itr->second.first << " " <<itr->second.second << "); ";
            if (diffSet.size() == 2){
                output = max(output, itr->second.second - itr->second.first + 1);
            }
            else{
                output = max(output, itr->second.second - itr->second.first + 2);
            }

            if (itr->first != INT_MAX){
                if (itr->second.first > 1){
                    if (arr[itr->second.first] - arr[itr->second.first - 2] == 2 * itr->first ){
                        output = max(output, itr->second.second - itr->second.first + 3);
                    }
                }

                if (itr->second.second < n - 2){
                    if (arr[itr->second.second + 2] - arr[itr->second.second] == 2 * itr->first ){
                        output = max(output, itr->second.second - itr->second.first + 3);
                    }
                }
            }
            
            if (itr != diffSet.begin()){
                if (itr->first == tmpItr->first){
                    if (itr->second.first - tmpItr->second.second == 2){
                        output = max(output, itr->second.second - tmpItr->second.first + 1);
                    }   
                }
            }
            tmpItr = itr;
        }
        cout << "Case #" << a + 1 << ": " << output << endl;
    }
    return 0;
}