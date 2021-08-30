#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int x = 0; x < t; x++)
    {
        int n,m;
        cin>>n>>m;
        // cout<<"n = "<<n<<" m = "<<m<<endl;

        map<long long, long long> prbSet;

        for (int i = 0; i < n; i++)
        {
            long long a,b;
            cin>>a>>b;
            prbSet[a] = b;
        }
        
        
        vector<long long> output;
        map<long long, long long> :: iterator itr;

        for (int i = 0; i < m; i++)
        {
            
            long long a;
            cin>>a;
            
            if (prbSet.empty())
            {   
                break;
            }
            
            itr = prbSet.lower_bound(a);

            if(itr == prbSet.begin() ){
                long long first, second;
                first = (*itr).first;
                second = (*itr).second;
                prbSet.erase(itr);
                if (first+1<=second)
                {
                    prbSet[first+1] = second;
                }
                output.push_back(first);
                // cout<<endl<<"output #1 "<<i<<" : "<<output.back()<<endl;
            }

            else if( itr == prbSet.end() ){
                map<long long, long long> :: iterator itr2;
                itr2 = itr;
                itr2--;
                long long first, second;
                first = (*itr2).first;
                second = (*itr2).second;
                prbSet.erase(itr2);

                if (second<=a)
                {
                    if (first<=second-1)
                    {
                        prbSet[first] = second-1; 
                    }
                   output.push_back(second);
                //    cout<<endl<<"output #2 "<<i<<" : "<<output.back()<<endl;
                }
                else{
                    if (first<=a-1)
                    {
                        prbSet[first] = a-1; 
                    }
                    if (a+1<=second)
                    {
                        prbSet[a+1] = second;
                    }
                    output.push_back(a);
                    // cout<<endl<<"output #3 "<<i<<" : "<<output.back()<<endl;
                }
                
            }
            else{
                map<long long, long long> :: iterator itr2;
                itr2 = itr;
                itr2--;
                long long prevfirst, prevsecond, first, second;
                first = (*itr).first;
                second = (*itr).second;
                prevfirst = (*itr2).first;
                prevsecond = (*itr2).second;
                
                // if (first == a)
                // {
                //    prbSet.erase(itr);
                //    if (first+1 <= second)
                //    {
                //        prbSet[first+1] = second; 
                //    }
                //    output.push_back(first);
                // }
                
                // else if (prevsecond <= a)
                if (prevsecond <= a)
                {
                    if (abs(prevsecond-a)<=abs(first-a))
                    {
                        prbSet.erase(itr2);
                        if (prevfirst<=prevsecond-1)
                        {
                            prbSet[prevfirst] = prevsecond-1;
                        }
                        output.push_back(prevsecond);
                        // cout<<endl<<"output #4 "<<i<<" : "<<output.back()<<endl;
                    }
                    else{
                        prbSet.erase(itr);
                        if (first+1 <= second)
                        {
                            prbSet[first+1] = second; 
                        }
                        output.push_back(first);
                        // cout<<endl<<"output #5 "<<i<<" : "<<output.back()<<endl;
                    }
                }

                else{
                    prbSet.erase(itr2);
                    if (prevfirst <= a-1)
                    {
                        prbSet[prevfirst] = a-1;
                    }
                    if (a+1 <= prevsecond)
                    {
                        prbSet[a+1] = prevsecond;
                    }
                    output.push_back(a);
                    // cout<<endl<<"output #6 "<<i<<" : "<<output.back()<<endl;
                }
            }
        }

        cout<<"Case #"<<x+1<<": ";
        for (int i = 0; i < output.size(); i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<endl;

        
    }
    return 0;
}
