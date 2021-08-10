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

        int diff, currentLength, ans;

        for (int i = 0; i < n; i++)
        {
            cin>>array[i];
        }

        for (int i = 0; i < n-1; i++)
        {   
            if (i==0){
                diff = array[i]-array[i+1];
                currentLength = 2;
                ans =2;
            }
            else{
                if (diff==array[i]-array[i+1]){
                    currentLength +=1;
                    ans = max(ans, currentLength);
                }
                else{
                    diff = array[i]-array[i+1];
                    currentLength = 2;
                }
            }
        }
        cout<<"Case #"<<a+1<<": "<<ans<<endl;
    }
    return 0;
}