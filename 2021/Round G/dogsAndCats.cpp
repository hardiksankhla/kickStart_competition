#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        long long n, d, c, m;
        cin >> n >> d >> c >> m;
        string s;
        cin >> s;
        // cout<<n<<" "<<d<<" "<<c<<" "<<m<<" "<<s<<endl;
        bool lineMove = true;
        string output = "YES";
        for (int i = 0; i < s.size(); i++)
        {
            if (lineMove){
                if (s[i] == 'C'){
                    if (c){
                            c--;   
                    }
                    else{
                        lineMove = false;
                        continue;
                    }
                }
                
                if (s[i] == 'D'){
                    if (d){
                        d--;
                        c += m;
                    }
                    else{
                        lineMove = false;
                        output = "NO";
                        break;
                    }
                }                
            }
            else{
                if (s[i]=='D'){
                    output = "NO";
                    break;
                }   
            } 
        }
        cout << "Case #" << a + 1 << ":" << " " << output << endl;
        
    }
    
    return 0;
}