#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for (int a = 0; a < t; a++){
        int n;
        int area;
        cin >> n >> area;
        if(area <= n - 3){
            cout << "Case #" << a + 1 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << "Case #" << a + 1 << ": " << "POSSIBLE" << endl;
        
        vector<pair<pair<int, int>, pair<int, int>>> points((n + 1) / 2, {{-1, -1}, {-1, -1}});
        int len = points.size();
        points[0] = {{1 - 1, 0}, {1, 0}};
        
        for (int i = 2; i < n; i++){
            if (i == n - 1){
                if ((i / 2) % 2 == 0 and i % 2 == 0){
                    points[i/2].first = {0, i/2 + area - 1};
                    area--;
                    continue;
                }
                if ((i / 2) % 2 == 0 and i % 2 != 0){
                    points[i/2].second = {1 + area -1, i/2};
                    area--;
                    continue;
                }
                if ((i / 2) % 2 != 0 and i % 2 == 0){
                    points[i/2].first = {1, i/2 + area - 1};
                    area--;
                    continue;
                }
                if ((i / 2) % 2 != 0 and i % 2 != 0){
                    points[i/2].second = {2 + area - 1, i/2};
                    area--;
                    continue;
                }
            }
            
            if ((i / 2) % 2 == 0 and i % 2 == 0){
                points[i/2].first = {0, i/2};
                area--;
                continue;
            }
            if ((i / 2) % 2 == 0 and i % 2 != 0){
                points[i/2].second = {1, i/2};
                area--;
                continue;
            }
            if ((i / 2) % 2 != 0 and i % 2 == 0){
                points[i/2].first = {1, i/2};
                area--;
                continue;
            }
            if ((i / 2) % 2 != 0 and i % 2 != 0){
                points[i/2].second = {2, i/2};
                area--;
                continue;
            }
        }

        for (int i = 0; i < len; i++){
            cout << points[i].first.first << " " << points[i].first.second << endl;
        }
        
        for (int i = len - 1; i >= 0; i--){
            if (points[i].second.first == -1){
                continue;
            }
            cout << points[i].second.first << " " << points[i].second.second << endl;
        }
    }
    return 0;
}