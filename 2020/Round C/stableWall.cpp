#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int r, c;
        cin >> r >> c;

        vector<vector<char>> arr(r, vector<char>(c, 'A'));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }

        vector<vector<bool>> ocupied(r + 1, vector<bool>(c, 0));
        
        for (int i = 0; i < c; i++)
        {
            ocupied[r][i] = 1;
        }

        set<char> block;
        
        for (int i = r - 1; i >= 0; i--)    
        {   
            for (int j = 0; j < c; j++)
            {
                block.insert(arr[i][j]);
            }
        }

        queue<char> blocks;
        
        for (auto itr = block.begin(); itr!= block.end(); itr++)
        {
            blocks.push(*itr);
        }
        
        int noOfChar = blocks.size();
        int tmpCount = noOfChar;
        bool solutionFound = true;
        string output = "";

        while (!blocks.empty())
        {   
            if (tmpCount == 0)
            {
                solutionFound = false;
                break;
            }
            
            char front = blocks.front();
            bool frontNotGood = false;

            for (int i = r - 1; i >= 0; i--)
            {
                for (int j = 0; j < c; j++)
                {
                    if (ocupied[i + 1][j] == 0 and arr[i][j] == front and arr[i+1][j] != front)
                    {
                        frontNotGood = true;
                        break;                
                    }
                }
                if (frontNotGood)
                {
                    blocks.pop();
                    blocks.push(front);
                    tmpCount --;
                    break;
                }
            }

            if (frontNotGood == false)
            {
                blocks.pop();
                tmpCount = noOfChar;
                noOfChar --;
                output += front;

                for (int i = r - 1; i >= 0; i--)
                {
                    for (int j = 0; j < c; j++)
                    {
                        if (arr[i][j] == front)
                        {
                            ocupied[i][j] = 1;
                        }
                    }
                }

            }

        }

        if (solutionFound){
            cout << "Case #" << a + 1 << ": " << output << endl;
        }
        else{
            cout << "Case #" << a + 1 << ": " << -1 << endl;
        } 
    }
    return 0;
}