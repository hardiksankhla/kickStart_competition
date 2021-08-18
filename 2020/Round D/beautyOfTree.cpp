#include<bits/stdc++.h>
using namespace std;

void colorNode(int node, vector<vector<int>> &graph, int num, vector<int> &prob_arr){
    prob_arr[node-1]++;
    int count = 0;
    while (node!=1)
    {
       node = graph[node][0] ; 
       count++;
        if (count%num==0)
        {
            prob_arr[node-1]++;
        }  
    } 
}

int main(){
    int T;
    cin>>T;
    for (int a = 0; a < T; a++)
    {
        int N, A, B;
        cin>>N>>A>>B;
        
        if (N==1){
            cout<<"Case #"<<a+1<<": "<<1<<endl;
            continue;
        }
        
        vector<vector<int>> tree(N+1);
        int temp;

        for (int i = 0; i < N-1; i++)
        {
            cin>>temp;
            tree[i+2].push_back(temp);
        }

        // for (int i = 0; i < tree.size(); i++)
        // {   
        //     cout<<i<<" -> ";
        //     for (int j = 0; j < tree[i].size(); j++)
        //     {
        //         cout<<tree[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<int> prob_A(N,0);
        vector<int> prob_B(N,0);

        for (int i=1; i<N+1; i++){
            colorNode(i, tree, A, prob_A );
            colorNode(i, tree, B, prob_B );
        }

        // for (int i=1; i<N+1; i++){
        //     cout<<prob_A[i-1]<<" ";
        // }
        // cout<<endl;
        // for (int i=1; i<N+1; i++){
        //     cout<<prob_B[i-1]<<" ";
        // }
        // cout<<endl;

        double output = 0;

        for (int i=1; i<N+1; i++){
            output+= 1-( (1- double(prob_A[i-1])/N) * ((1-double(prob_B[i-1])/N)) );
        }
        cout.precision(10);
        cout<<"Case #"<<a+1<<": "<<output<<endl;  
    }
    return 0;
}