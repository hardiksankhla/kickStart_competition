#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    int N, B;
    int output;

    for (int a = 0; a < T; a++)
    {
        cin>>N>>B;
        vector<int> arr(N);
        output = 0;
        
        for (int i = 0; i < N; i++)
        {
            cin>>arr[i];
        }
        
        sort(arr.begin(), arr.end());
        
        // Print
        // for (int i = 0; i < N; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

        for (int i = 0; i < N; i++)
        {
            B-=arr[i];
            if(B<0){
                break;
            }
            output++;
        }
        cout<<"Case #"<<a+1<<": "<<output<<endl;
    }
    return 0;
}