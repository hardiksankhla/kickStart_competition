#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        string s;
        cin >> s;

        vector<int> kick;
        vector<int> prefixStart(s.size(), 0);

        for (int i = 0; i < (int)s.size() - 3; i++) //  (int) is important to convert it into signed int, size() returns unsigned int, it returns only positive value;
        {
            if (s[i] == 'K' and s[i + 1] == 'I' and s[i + 2] == 'C' and s[i + 3] == 'K')
            {
                kick.push_back(i);
            }
            if (i < s.size() - 4)
            {
                if (s[i] == 'S' and s[i + 1] == 'T' and s[i + 2] == 'A' and s[i + 3] == 'R' and s[i + 4] == 'T')
                {
                    prefixStart[i]++;
                }
            }
        }

        for (int i = 1; i < s.size(); i++)
        {
            prefixStart[i] += prefixStart[i - 1];
        }

        long long output = 0;

        for (int i = 0; i < kick.size(); i++)
        {
            output += prefixStart.back() - prefixStart[kick[i]];
            // cout << prefixStart.back() << " " << prefixStart[kick[i]] << endl;
        }
        cout << "Case #" << a + 1 << ": " << output << endl;
    }

    return 0;
}