#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;

    for (int a = 0; a < T; a++)
    {
        int n;
        cin>>n;
        int arr[n];
        int up = 0, down = 0, output = 0;


        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        
        for (int i = 1; i < n; i++)
        {
            if (arr[i]>arr[i-1])
            {
                up++;
                down = 0;
                if(up>3){
                    up = 0;
                    output++;
                }
            }
            if (arr[i]<arr[i-1])
            {
                down++;
                up = 0;
                if(down>3){
                    down = 0;
                    output++;
                }
            }
            
        }
        cout<<"Case #"<<a+1<<": "<<output<<endl;
    }
    

    return 0;
}