#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        int N, A, B, C;
        cin >> N >> A >> B >> C;

        if (A + B - C <= N  /* and A <= N and  B <= N and C <= min(A, B) */ )
        {
            vector<int> arr(N, 0);

            for (int i = 0; i < A - C; i++)
            {
                arr[i] = N - 1;
            }

            for (int i = 0; i < B - C; i++)
            {
                arr[N - 1 - i] = N - 1;
            }

            int count = 0;
            for (int i = 0; i < N; i++)
            {
                if (arr[i] == 0)
                {
                    arr[i] = N;
                    count++;
                }
            }
            
            for (int i = 1; i < N - 1; i++)
            {
                if (arr[i] == N)
                {
                    if (count > C)
                    {
                        arr[i] = 1;
                        count--;
                    }
                }
            }

            if (count != C)
            {
                cout << "Case #" << a + 1 << ": IMPOSSIBLE" << endl;
                continue;
            }
            
                
            cout << "Case #" << a + 1 << ":";
            for (int i = 0; i < arr.size(); i++)
            {
                cout << " " << arr[i];
            }
            cout << endl;
        }
        else
        {
            cout << "Case #" << a + 1 << ": IMPOSSIBLE" << endl;
        }

    }
    
    return 0;
}
