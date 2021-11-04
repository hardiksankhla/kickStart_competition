#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for (int a = 0; a < t; a++)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        int output=0;

        for (int i = 1; i < n-1; i++)
        {
            if (arr[i] > arr[i + 1] and arr[i] > arr[i - 1])
            {
                output ++;
            }   
        }
        cout<<"Case #"<<a+1<<": "<<output<<endl;
    }
    return 0;
}