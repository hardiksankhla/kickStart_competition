#include<bits/stdc++.h>
#include<vector>
using namespace std;

int plates(vector<vector<int>> &arr, int row, int plateLeft, int N, int K, vector<vector<int>> &record){
    
    if (record[row][plateLeft]!=-1)
    {
        return record[row][plateLeft];
    }
    
    if (plateLeft==0)
    {
        record[row][plateLeft]=0;
        return record[row][plateLeft];
    }
    
    if (row<N)
    {
        int temp=INT_MIN;
        for (int i = 0; i < K; i++)
        {   
            if (plateLeft-i>0)
            {
                temp = max(temp, arr[row][i] + plates(arr, row+1, plateLeft-(i+1), N, K, record) );
            } 
        }
        temp = max(temp,  plates(arr, row+1, plateLeft, N, K, record)) ;
        record[row][plateLeft] = temp;
        return record[row][plateLeft];
    }
    else{
        record[row][plateLeft]=0;
        return record[row][plateLeft];
    }  
}

int main(){
    int T;
    cin>>T;
    int N, K, P;
    for (int a = 0; a < T; a++)
    {
        cin>>N>>K>>P;
        vector<vector<int>> arr(N, vector<int> (K, 0));
        
        // Take input
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < K; j++)
            {
                cin>>arr[i][j];
            }
            
        }
        
        // Print
        // cout<<endl;
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < K; j++)
        //     {
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        vector<vector<int>> prefixArr(N, vector<int>(K, 0));
        for (int i = 0; i < N; i++)
        {   
            prefixArr[i][0] = arr[i][0];
            for (int j = 1; j < K; j++)
            {
                prefixArr[i][j] = prefixArr[i][j-1]+arr[i][j];
            }
        }
        
        // Print
        // cout<<endl;
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < K; j++)
        //     {
        //         cout<<prefixArr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        vector<vector<int>> record(N+1, vector<int> (P+1, -1));

        int output = plates(prefixArr, 0, P, N, K, record);
        cout<<"Case #"<<a+1<<": "<<output<<endl;
    }    
    return 0;
}