#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int a = 0; a < t; a++)
    {
        long long n;
        cin>>n;
        long double ans=0;
        if (n<=1e7)      
        {
            for (int i = 1; i <= n; i++)
            {
                ans+=(1/(long double)i);
            }

        }
        else{
            ans = log(n)+1/(2*n)+0.577215664901532;
        }
        
        cout.precision(10);
        cout<<"Case #"<<a+1<<": "<<ans<<endl;
    }
    
    
    return 0;
}