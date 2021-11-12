#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n, k;
        cin >> n >> k;

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int s, e;
            cin >> s >> e;
            mp.insert({s, e});
        }
        
        int output=0;
        int position=0;

        for (auto itr = mp.begin(); itr != mp.end(); /* itr++ */)
        {
            int start = max(itr->first, position);
            // cout<<start<<" "<<position<<" "<<itr->first<<"; ";
            int end = itr->second;

            if ((end - start) % k == 0)
            {
                output += (end - start) / k;
                itr = mp.upper_bound(end);
                position = end;
                continue;
            }

            if (start + k < end)
            {
                while (start + k < end)
                {
                    start += k;
                    output++;
                }
                // output--;
            }

            if (start + k > end)
            {
                output++;
                itr = mp.lower_bound(start + k);
                itr--;

                if (itr->second <= start + k)
                {
                    itr++;
                }
                if (itr->second > start + k)
                {
                    ;// do nothing;
                }
                
                position = start + k;
            }

        }
        cout << "Case #" << a + 1 << ": " << output << endl;
        
    }
    
    return 0;
}
