#include<bits/stdc++.h>
using namespace std;

void changeVisGroupAtoB(int a, int b, vector<int> &visGroup){
    for (int i = 0; i < visGroup.size(); i++){
        if (visGroup[i] == a){
            visGroup[i] = b;
        }
    }
    return;
}

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a++){
        int n;
        cin >> n;
        
        vector<vector<int>> arr (n, vector<int> (n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        vector<vector<int>> cost (n, vector<int> (n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> cost[i][j];
            }
        }

        vector<vector<int>> chkSum (2, vector<int> (n, 0));
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < n; j++){
                cin >> chkSum[i][j];
            }
        }

        // End of Inputs

        vector<pair<int, pair<int, int>>> queue;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (arr[i][j] == -1){
                    queue.push_back({cost[i][j], {i, j+n}});
                }
            }
        }

        vector<pair<int, pair<int, int>>> remainingQueue;
        vector<int> visGroup(2*n, -1);
        int groupNo = 1;
        sort(queue.begin(), queue.end());
        
        while (!queue.empty()){
            int index = queue.back().second.first;
            int index2 = queue.back().second.second;

            if (visGroup[index] == visGroup[index2] and visGroup[index]!= -1){
                remainingQueue.push_back( queue.back());
                // cout<<queue.back().first<<" ("<<queue.back().second.first<<" "<<queue.back().second.second<<"); ";
                queue.pop_back();
                continue;
            }
            if(visGroup[index] == visGroup[index2] and visGroup[index]== -1){
                visGroup[index] = groupNo;
                visGroup[index2] = groupNo;
                groupNo++;
                // cout<<queue.back().first<<" ("<<queue.back().second.first<<" "<<queue.back().second.second<<"); ";
                queue.pop_back();
                continue;
            }
            if (visGroup[index] != visGroup[index2] and (visGroup[index] == -1 or visGroup[index2] == -1 ) ){
                int maxGroupNo = max(visGroup[index], visGroup[index2]);
                visGroup[index] = maxGroupNo;
                visGroup[index2] = maxGroupNo;
                // cout<<queue.back().first<<" ("<<queue.back().second.first<<" "<<queue.back().second.second<<"); ";
                queue.pop_back();
                continue;
            }
            if (visGroup[index] != visGroup[index2] and (visGroup[index] != -1 and visGroup[index2] != -1 ) ){
                int A, B;
                if (visGroup[index] > visGroup[index2]){
                    A = visGroup[index];
                    B = visGroup[index2];
                }
                else{
                    B = visGroup[index];
                    A = visGroup[index2];
                }
                
                changeVisGroupAtoB(A,B, visGroup);
                // cout<<queue.back().first<<" ("<<queue.back().second.first<<" "<<queue.back().second.second<<"); ";
                queue.pop_back();
                continue;
            }
        }

        long long output = 0;
        for (int i = 0; i < remainingQueue.size(); i++)
        {
            output += remainingQueue[i].first;
        }
        // cout<<endl;
        cout << "Case #" << a + 1 << ": " << output << endl;
    }
}