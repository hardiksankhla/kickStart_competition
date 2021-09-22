#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        
        int d, n, k;
        cin >> d >> n >> k;

        vector<vector<pair<int, int>>> in (d+1);
        vector<vector<pair<int, int>>> out (d+1);

        long long sum = 0, ans = 0;
        int si = 0;

        multiset<pair<int, int>> top_K;
        multiset<pair<int, int>, greater<pair<int, int>>> remain; 

        for (int i = 0; i < n; i++)
        {
            int h, s, e;
            cin >> h >> s >> e;
            s--;
            e--;
            in[s].push_back( {h, i} );
            out[e+1].push_back( {h, i} );
        }

        for (int i = 0; i < d; i++)
        {
            int len = in[i].size();

            for (int j = 0; j < len; j++)
            {
                remain.insert({in[i][j].first, in[i][j].second});
            }

            len = out[i].size();
            int erased;

            for (int j = 0; j < len; j++)
            {
                remain.erase({out[i][j].first, out[i][j].second});
                
                erased =  top_K.erase({out[i][j].first, out[i][j].second});

                if (erased == 1)
                {
                    sum -= out[i][j].first;
                    si--;
                }
            }

            multiset<pair<int, int>> :: iterator itr_top;
            multiset<pair<int, int>, greater<pair<int, int>>> :: iterator itr_rem;

            while (si < k and !remain.empty())
            {
                itr_rem = remain.begin();
                sum += itr_rem->first;
                top_K.insert(*itr_rem);
                remain.erase(itr_rem);
                si++;
            }

            while (si == k and !remain.empty())
            {
                itr_rem = remain.begin();
                itr_top = top_K.begin();

                if (itr_rem->first > itr_top->first)
                {
                    int val1 = itr_rem->first, val2 = itr_top->first;
                    int attNo1 = itr_rem->second, attNo2 = itr_top->second;

                    top_K.erase(itr_top);
                    remain.erase(itr_rem);

                    top_K.insert({val1, attNo1});
                    remain.insert({val2, attNo2});

                    sum += val1 - val2;
                }
                else
                {
                    break;
                }   
            }
            ans = max(ans, sum);       
        }
        cout<<"Case #"<<a+1<<": "<<ans<<endl;
    }
    return 0;
}