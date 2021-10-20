#include<bits/stdc++.h>
using namespace std;
const int32_t M=1e9+7;
const int32_t MM=998244353;

int fun(int a, int b, int m, int rand1){
    // a *= a;
    // a %= m;
    // a += b*b;
    // a ^= b/7;
    // a %= m;
    a += 489;
	a ^= 2309480;
	a *= 25;
	a += 123;
	a %= MM;
	a *= 34563;
	a %= M;
	a = 17 +  rand1 * a + b + a * a % M * b % MM + a * a % MM * a % M * (b + 23) % MM;


    return a;
}

int evaluate(string &s, int m, int rand1){

    vector<pair<int, int>> v;
    for (auto c : s){
        if (c=='(')
        {
            continue;
        }

        else if (c==')')
        {   
            int b = v.back().second;
            v.pop_back();
            char o = v.back().second;
            v.pop_back();
            int a = v.back().second;
            v.pop_back();
            int result; 

            if (o == '+')
            {
                result = (b + a) % m;
            }
            if (o == '*')
            {
                result = (b * a) % m;
            }
            if (o == '#')
            {
                result = fun(a, b, m, rand1) % m;
            }
            v.push_back({0, result});    
        }

        else if (c >= '0' and c <= '9')
        {
            if (v.empty() or v.back().first != 0)
            {
                v.push_back({0, 0});
            }
            v.back().second *= 10;
            v.back().second += c - '0';
            v.back().second %= m; 
        }

        else
        {
            v.push_back({1, c});
        }
    }
    return v.back().second;
}


int main(){
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        int n;
        cin >> n;
        string s[n];

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        // cout << endl;
        int rand1 = rand()%10000;
        cout<<"rand1 = "<< rand1<<endl;
        vector<int> eval(n, 0);
        for (int i = 0; i < n; i++)
        {
            eval[i] = evaluate(s[i], 46027, rand1);
        }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << eval[i] << " ";
        // }
        // cout << endl;
        // cout << endl;
        
        vector<int> unique;
        vector<int> output(n, 0);

        unique.push_back(eval[0]);

        for (int i = 0; i < n; i++)
        {
            int m = unique.size();
            bool isUnique = true;
            for (int j = 0; j < m; j++)
            {
                if (eval[i] == unique[j])
                {
                    output[i] = j+1;
                    isUnique = false;
                    break;
                }
            }

            if (isUnique)
            {
                unique.push_back(eval[i]);
                output[i] = m+1;
            }
        }

        cout<<"Case #"<<a+1<<": ";
        for (int i = 0; i < n; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
    }
    return 0;
}