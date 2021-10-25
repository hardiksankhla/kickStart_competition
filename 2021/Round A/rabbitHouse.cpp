#include<bits/stdc++.h>
using namespace std;

void makeSafe(priority_queue<pair<int, pair<int, int>>> &q, vector<vector<int>> &arr,long long &output){
    int i = q.top().second.first, j = q.top().second.second;
    q.pop();
    
    if (i > 0){
        if (arr[i][j] - arr[i - 1][j] > 1){
            output += arr[i][j] - arr[i - 1][j] - 1;
            arr[i - 1][j] += arr[i][j] - arr[i - 1][j] - 1;
            q.push({arr[i - 1][j], {i - 1, j}});
        }
    }
    
    if (j > 0){
        if (arr[i][j] - arr[i][j - 1] > 1){
            output += arr[i][j] - arr[i][j - 1] - 1;
            arr[i][j - 1] += arr[i][j] - arr[i][j - 1] - 1;
            q.push({arr[i][j - 1], {i, j - 1}});
        }
    }
    
    if (i < arr.size() - 1){
        if (arr[i][j] - arr[i + 1][j] > 1){
            output += arr[i][j] - arr[i + 1][j] - 1;
            arr[i + 1][j] += arr[i][j] - arr[i + 1][j] - 1;
            q.push({arr[i + 1][j], {i + 1, j}});
        }
    }
    
    if (j < arr[0].size() - 1){
        if (arr[i][j] - arr[i][j + 1] > 1){
            output += arr[i][j] - arr[i][j + 1] - 1;
            arr[i][j + 1] += arr[i][j] - arr[i][j + 1] - 1;
            q.push({arr[i][j + 1], {i, j + 1}});
        }
    }
}

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int r, c;
        cin >> r >> c;
        
        vector<vector<int>> arr(r, vector<int> (c, 0));
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cin >> arr[i][j];
            }
        }

        priority_queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                q.push({arr[i][j], {i, j}});
            }
        }

        long long output = 0;
        while (!q.empty()){
            makeSafe(q, arr, output);
        }
        
        cout << "Case #" << a + 1 << ": " << output << endl;
    }
    return 0;
}