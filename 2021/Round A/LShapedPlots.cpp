#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> arr(r + 2, vector<int> (c + 2, 0));
        for (int i = 1; i <= r; i++){
            for (int j = 1; j <= c; j++){
                cin >> arr[i][j]; 
            }
        }
        vector<vector<int>> arrLeft(r + 2, vector<int> (c + 2, 0));
        vector<vector<int>> arrRight(r + 2, vector<int> (c + 2, 0));
        vector<vector<int>> arrUp(r + 2, vector<int> (c + 2, 0));
        vector<vector<int>> arrDown(r + 2, vector<int> (c + 2, 0));
        for (int i = 1; i <= r; i++){
            for (int j = 1; j <= c; j++){
                arrLeft[i][j] = arrRight[i][j] = arrUp[i][j] = arrDown[i][j] = arr[i][j]; 
            }
        }

        for (int i = 1; i <= r; i++){
            for (int j = 1; j <= c; j++){
                if (arr[i][j]==0){
                    continue;
                }
                arrRight[i][j] += arrRight[i][j - 1];
                arrDown[i][j] += arrDown[i - 1][j];
            }  
        }

        for (int i = r; i >= 1; i--){
            for (int j = c; j >= 1; j--){
                if (arr[i][j]==0){
                    continue;
                }
                arrLeft[i][j] += arrLeft[i][j + 1];
                arrUp[i][j] += arrUp[i + 1][j];
            }  
        }
        
        long long output = 0;
        for (int i = 1; i <= r; i++){
            for (int j = 1; j <= c; j++){
                if (arr[i][j] == 0){
                    continue;
                }
                if (arrRight[i][j] > 1){
                    output += min(arrRight[i][j] / 2, arrDown[i][j]) - 1;
                    output += min(arrRight[i][j] / 2, arrUp[i][j]) - 1;
                }
                if (arrLeft[i][j] > 1){
                    output += min(arrLeft[i][j] / 2, arrDown[i][j]) - 1;
                    output += min(arrLeft[i][j] / 2, arrUp[i][j]) - 1;
                }
                if (arrDown[i][j] > 1){
                    output += min(arrRight[i][j], arrDown[i][j] / 2) - 1;
                    output += min(arrLeft[i][j], arrDown[i][j] / 2) - 1;
                }
                if (arrUp[i][j] > 1){
                    output += min(arrRight[i][j], arrUp[i][j] / 2) - 1;
                    output += min(arrLeft[i][j], arrUp[i][j] / 2) - 1;
                }
            }  
        }
        cout << "Case #" << a + 1 << ": " << output << endl;
    }
    return 0;
}