#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        int n;
        cin >> n;

        vector<int> arr(n, 0);
        int maxPossibleSum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > 0)
            {
                maxPossibleSum += arr[i];
            }
            if (arr[i] < 0)
            {
                maxPossibleSum -= arr[i];
            }
        }

        vector<int> countOfPrefixSum (2 * maxPossibleSum + 1, 0);

        countOfPrefixSum[maxPossibleSum] = 1;
        int prefixSum = 0;
        long long output = 0;

        for (int i = 0; i < n; i++)
        {
            prefixSum += arr[i];
            for (int j = 0; j * j <= maxPossibleSum + prefixSum; j++)
            {
                output += countOfPrefixSum[maxPossibleSum + prefixSum - (j * j)];
            }
            countOfPrefixSum[maxPossibleSum + prefixSum]++;
        }

        cout << "Case #" << a + 1 << ": " << output <<endl;
    }

    return 0;
}
