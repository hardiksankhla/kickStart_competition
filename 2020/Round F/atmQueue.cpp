#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        int n, x;
        cin >> n >> x;

        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            int money;
            cin >> money;
            arr[i] = {(money - 1) / x, i + 1};
            // cout<< money/x<<endl;
        }

        sort(arr.begin(), arr.end());
        
        cout << "Case #" << a + 1 << ":";
        for (int i = 0; i < n; i++)
        {
            cout << " " << arr[i].second;
        }
        cout << endl;
    }
    
    return 0;
}
