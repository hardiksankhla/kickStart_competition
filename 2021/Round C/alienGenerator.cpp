#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int a = 0; a < t; a++)
    {
        long long g;
        cin>>g;
        int count = 0;
        long long numerator = -1;
        for (long long i = 1; i < 1e7 and i <= g; i++)
        {
            numerator = 2*g-(i*(i-1));
            if (numerator >= 2 * i)
            {
                if (numerator%(2*i)==0)
                {
                    count++;
                }
            }
            else
            {
                break;
            }
        }
        cout<<"Case #"<<a+1<<": "<<count<<endl;
    }
    return 0;
}