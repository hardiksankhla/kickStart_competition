#include<bits/stdc++.h>
using namespace std;

struct trie
{
    trie* child[26];
    // vector<struct trie*> child(26, NULL);
    int count = 0;
};

void insert(string &s, trie* root){

    trie* tmp = root;
    for (int i = 0; i < s.size(); i++){
        int childNo = s[i] - 'A';
        if (!tmp->child[childNo]){
            tmp->child[childNo] = new trie();
        }
        tmp = tmp->child[childNo];
    }
    tmp->count++;
}

void dfsTraverse(trie* root, int depth, const int &k, long long &output){
    // int noOfChild = root->child.size();
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i])
        {
            dfsTraverse(root->child[i], depth+1, k, output);
            root->count += root->child[i]->count;
        }
    }

    while (root->count >= k)
    {
        root->count -= k;
        output += depth;
    }
}

int main(){
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n, k;
        cin >> n >> k;

        trie* root = new trie();

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            insert(s, root);
        }

        long long output = 0;
        dfsTraverse(root, 0, k, output);

        cout << "Case #" << a + 1 << ": " << output << endl;
    }
    return 0;
}