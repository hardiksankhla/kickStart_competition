#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, vector<vector<int>> &output, int S, int K){
    vector<int> :: iterator itr;
    itr = arr.begin();
    itr = itr +S-1;
    
    vector<int> :: iterator itr2;
    itr2 = arr.begin();
    itr2 = itr2 +S;

    int room = S;
    int leftmove =0;
    int rightmove =0;

    // cout<<*itr<<" "<<*itr2<<endl;
    // cout<<room<<endl;
    output[S].push_back(room);
    // cout<<"moves "<<leftmove<<" "<<rightmove<<endl;

    while ( true)
    {
        if(*itr > *itr2){
            itr2++;
            rightmove++;
            room = S+rightmove;
        }

        else if(*itr < *itr2){
            itr--;
            leftmove++;
            room = S-leftmove;
        }
        // cout<<*itr<<" "<<*itr2<<endl;
        // cout<<room<<endl;
        output[S].push_back(room);
        // cout<<"moves "<<leftmove<<" "<<rightmove<<endl;
        
        if (itr==arr.begin() and itr2==(arr.end()-1))
        {
            break;
        } 
    }
} 

int main(){
    int T;
    cin>>T;
    for (int a = 0; a < T; a++)
    {
        int N, Q;
        cin>>N>>Q;

        vector<int> arr(N+1);
        vector<bool> computed(N+1, false);
        vector<vector<int>> output(N+1);
        arr[0] = INT_MAX;
        arr[N] = INT_MAX; 
        
        for (int i = 1; i < N; i++)
        {
            cin>>arr[i];
        }

        // for (int i = 0; i < N+1; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

        int S, K;
        cout<<"Case #"<<a+1<<": ";
        for (int i = 0; i < Q; i++)
        {
            cin>>S>>K;
            if (computed[S]==false)
            {
                solve(arr, output, S, K);
                computed[S]=true;
            }
            cout<<output[S][K-1]<<" ";
        }  
        cout<<endl; 
    }
    return 0;
}