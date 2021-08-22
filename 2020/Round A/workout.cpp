#include<bits/stdc++.h>
using namespace std;

int searchInterval (int left, int right, vector<int> &arr, int k){
        
    int middle= (right+left)/2;    
    int middleInterval = 0;

    for (int j = 0; j < arr.size()-1; j++)
    {
        middleInterval+=  ceil((arr[j+1]-arr[j])/double(middle)) - 1;
        // cout<<ceil((arr[j+1]-arr[j])/double(middle)) - 1<<" ";
    }
    
    // cout<<"Left "<<left<<" right "<<right<<" max gap = "<<middle<<" middle interval = "<<middleInterval<<endl;
    
    if (left == right-1)
    {
        if(middleInterval<=k){
            return left;
        }
        if(middleInterval>k){
            return right;
        }
        
    }
    
    if(middleInterval<=k){
        return searchInterval( left, middle, arr, k);
    }
    
    if(middleInterval>k){
        return searchInterval( middle, right, arr, k);
    }
}

int main(){
    int t;
    cin>>t;
    int n, k;
    for (int a = 0; a < t; a++)
    {   
        cin>>n>>k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int temp = searchInterval( 1, 1e9, arr, k);
        cout<<"Case #"<<a+1<<": "<<temp<<endl;
    }
    
    return 0;
}