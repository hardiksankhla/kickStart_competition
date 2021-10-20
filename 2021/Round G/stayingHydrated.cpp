#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        int k;
        cin >> k;
        vector<long long> xPoint(2 * k, 0);
        vector<long long> yPoint(2 * k, 0);
        for (int i = 0; i < k; i++)
        {
            long long x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            xPoint[2 * i] = x1;
            xPoint[2 * i + 1] = x2;
            yPoint[2 * i] = y1;
            yPoint[2 * i + 1] = y2;
        }
        
        sort(xPoint.begin(), xPoint.end());
        sort(yPoint.begin(), yPoint.end());

        pair<int, int> output = {xPoint[xPoint.size()/2 - 1], yPoint[yPoint.size()/2 - 1]};

        cout << "Case #" << a + 1 << ": " << output.first << " " << output.second << endl;
    }
    
    return 0;
}