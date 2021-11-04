#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        int output = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == k and i + k - 1 < n)        
            {
                output++;
                int j;
                for (j = 0; j < k - 1; j++)
                {
                    if (arr[j + i + 1] != arr[j + i] - 1)
                    {
                        output--;
                        break;
                    }
                }
                i += j;
                // cout << i << endl;
            }
        }
        cout << "Case #" << a + 1 << ": " << output << endl;
    }
    return 0;
}
