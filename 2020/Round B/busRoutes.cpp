#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        long long n, d;
        cin >> n >> d;

        vector<long long> arr(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            d -= d % arr[i];
        }
        
        cout << "Case #" << a + 1 << ": " << d << endl;
    }
    return 0;
}