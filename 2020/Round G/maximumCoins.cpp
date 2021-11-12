#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        vector<pair<int, int>> startingPoint;
        for (int i = 0; i < n; i++)
        {
            startingPoint.push_back({0, i});
            startingPoint.push_back({i, 0});
        }

        long long output = 0;

        for (int i = 0; i < startingPoint.size(); i++)
        {
            int r, c;
            r = startingPoint[i].first;
            c = startingPoint[i].second;
            long long sum = 0;
            
            while (r < n and c < n)
            {
                sum += arr[r][c];
                r++;
                c++;
            }
            
            output = max(output, sum);
        }

        cout << "case #" << a + 1 << ": " << output << endl;
    }

    return 0;
}