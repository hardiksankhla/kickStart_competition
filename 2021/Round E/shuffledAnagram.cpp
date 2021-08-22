#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    string s;
    string output;
    
    for (int a = 0; a < t; a++)
    {
        cin>>s;
        
        vector<int> arr(256,0);
        for (int i = 0; i < s.length(); i++)
        {
            arr[s[i]]++;
        }
        int maxAlpha = INT_MIN;
        
        for (int i = 0; i < 256; i++)
        {
            maxAlpha = max(maxAlpha, arr[i]);
        }
        
        string temp = s;
        output ="";

        if (2*maxAlpha>s.length()){
            output = "IMPOSSIBLE";
        }
        else{
            sort(temp.begin(), temp.end());
            do
            {
                bool flag = true;
                for (int i = 0; i < s.length(); i++)
                {
                    if (temp[i]==s[i])
                    {
                        flag = false;
                        break;
                        }  
                }
                if (flag)
                {
                    output = temp;
                    break;
                }
            } while (next_permutation(temp.begin(), temp.end())); 
        }
        cout<<"Case #"<<a+1<<": "<<output<<endl;
    }
    return 0;
}