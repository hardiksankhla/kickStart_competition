#include<bits/stdc++.h>
using namespace std;


class segmentTree
{
private:
    vector<long long> st;
    long long n;
public:
    segmentTree(vector<long long> &arr);
    void updateST(long long index, vector<long long> &arr);
    long long gcdST(long long rigth);
    ~segmentTree();
};

segmentTree::segmentTree(vector<long long> &arr)
{   
    this->n = arr.size();
    this->st = vector<long long> (2 * n, 0);
    // OR
    // n = arr.size();
    // st = vector<long long> (2*n);
    for (long long i = 0; i < n ; i++)
    {
        st[n + i] = arr[i];
    }
    for (long long i = n - 1; i > 0 ; i--)
    {
        st[i] = __gcd(st[2 * i], st[2 * i + 1]);
    }
}

void segmentTree::updateST(long long index, vector<long long> &arr){
    st[n + index] = arr[index];
    index += n;
    while (index > 1) 
    {
        index /= 2;
        st[index] = __gcd(st[2 * index], st[2 * index + 1]);
    }
}

long long segmentTree::gcdST(long long right){
    long long gcd = 0;
    long long left = n;
    right += n;
    while (left<=right)
    {
        if (left%2!=0)
        {
            gcd = __gcd(gcd, st[left]);
            left += 1;
        }
        
        if (right%2==0)
        {
            gcd = __gcd(gcd, st[right]);
            right -= 1;
        }

        left/=2;
        right/=2;
    }
    return gcd;
}

segmentTree::~segmentTree()
{
}


void dfsTraverse(long long city, vector<vector<pair<long long , pair<long long, long long> >>> &graph, vector<long long> &parentOf, vector<long long> &costForLoad, segmentTree &st, vector<vector<pair<long long, long long>>> &queryNode, vector<long long> &output, long long maxLoad)
{
    for (long long i = 0; i < graph[city].size(); i++)
    {
        if (graph[city][i].first != parentOf[city])
        {
            costForLoad[graph[city][i].second.first] = graph[city][i].second.second; 
            st.updateST(graph[city][i].second.first, costForLoad);
            
            // Everything is done here.
            
            for (int j = 0; j < queryNode[graph[city][i].first].size(); j++)
            {   
                if (queryNode[graph[city][i].first][j].first > maxLoad)
                {
                    output[queryNode[graph[city][i].first][j].second] = st.gcdST(maxLoad);
                }
                else
                {
                    output[queryNode[graph[city][i].first][j].second] = st.gcdST(queryNode[graph[city][i].first][j].first);
                }
            }
            
            dfsTraverse(graph[city][i].first, graph, parentOf, costForLoad, st, queryNode, output, maxLoad);
            
            costForLoad[graph[city][i].second.first] = 0;
            st.updateST(graph[city][i].second.first, costForLoad);
        }
    }
}

int main()
{
    long long t;
    cin >> t;

    for (long long a = 0; a < t; a++)
    {
        long long n, q;
        cin >> n >> q;

        vector<vector<pair<long long , pair<long long, long long> >>> graph(n + 1, vector<pair<long long, pair<long long, long long> >>());
        long long maxLoad = -1;
        
        for (long long i = 0; i < n - 1; i++)
        {
            long long n1, n2, l, c;   // node1, node2, load, cost;
            cin >> n1 >> n2 >> l >> c;
            graph[n1].push_back({n2, {l, c}});
            graph[n2].push_back({n1, {l, c}});
            maxLoad = max(maxLoad, l);
        }

        // Using bfs to find the parent of each node.

        queue<long long> que; 
        que.push(1);
        vector<long long> parentOf(n + 1, 0);
        parentOf[1] = 1;

        while (!que.empty())
        {
            long long front = que.front();
            for (long long i = 0; i < graph[front].size(); i++)
            {   
                if (parentOf[graph[front][i].first] == 0)
                {
                    parentOf[graph[front][i].first] = front;
                    que.push(graph[front][i].first);
                }
            }
            que.pop();
        }

        // for (long long i = 0; i < parentOf.size(); i++)
        // {
        //     cout<<parentOf[i]<<" ";
        // }
        // cout << endl;
        
        vector<long long> costForLoad(maxLoad + 1, 0);
        segmentTree st(costForLoad);
        vector<vector<pair<long long, long long>>> queryNode(n + 1);

        for (long long i = 0; i < q; i++)
        {
            long long c, w;
            cin >> c >> w;
            queryNode[c].push_back({w, i});
        }
        
        vector<long long> output (q, 0);
        dfsTraverse(1, graph, parentOf, costForLoad, st, queryNode, output, maxLoad);

        cout << "Case #" << a + 1 << ":";
        for (long long i = 0; i < q; i++)
        {
            cout<<" "<<output[i];
        }
        cout << endl;
    }
    return 0;
}