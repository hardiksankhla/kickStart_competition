#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        long long r,c,k;
        cin>>r>>c>>k;
        long long r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;

        r1--;
        c1--;
        long long length = c2-c1;
        long long width = r2-r1;

        long long cuts1 = 0;
        long long cuts2 =0;

        if(r2==r and r1==0){
            cuts1 += 0;
        }
        else if(r2==r xor r1==0){
            cuts1+= ceil(min(c-c1, c2)/double(k));
        }
        else if(r2!=r and r1!=0){
            cuts1+= ceil(min(c-c1, c2)/double(k))+ceil(length/double(k));
        }

        if(c2==c and c1==0){
            cuts1 += 0;
        }
        else if(c2==c xor c1==0){
            cuts1+= ceil(width/double(k));
        }
        else if(c2!=c and c1!=0){
            cuts1+= 2*ceil(width/double(k));
        }
        
        if(r2==r and r1==0){
            cuts2 += 0;
        }
        else if(r2==r xor r1==0){
            cuts2+= ceil(length/double(k));
        }
        else if(r2!=r and r1!=0){
            cuts2+= 2*ceil(length/double(k));
        }

        if(c2==c and c1==0){
            cuts2 += 0;
        }
        else if(c2==c xor c1==0){
            cuts2+= ceil(min(r-r1, r2)/double(k));
        }
        else if(c2!=c and c1!=0){
            cuts2+= ceil(min(r-r1, r2)/double(k))+ceil(width/double(k));
        }


        long long output = min(cuts1,cuts2);

        output+= min( 
        (length-1) * ceil(width/double(k)) + (length * (width-1)),
        (width-1) * ceil(length/double(k)) + (width * (length-1)) );
        cout<<endl;
        cout<<"Case #"<<i+1<<": "<<output<<endl;
        cout<<endl;
    }
    
    return 0;
}