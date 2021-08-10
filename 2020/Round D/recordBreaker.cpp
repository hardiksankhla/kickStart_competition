#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    for (int a = 0; a < T; a++)
    {
        int n;
        cin>>n;
        int array[n];

        for (int i = 0; i < n; i++)
        {
            cin>>array[i];
        }
        int lastDay = -1;
        int output = 0;
        for (int i = 0; i < n; i++)
        {
            if (array[i]>lastDay)
            {
                lastDay = array[i];
                if (i<n-1){
                    if (array[i]>array[i+1]){
                        output+=1;
                    }
                }
                else{
                    output+=1;
                }
            }   
        }
        cout<<"Case #"<<a+1<<": "<<output<<endl;
    }
    return 0;
}