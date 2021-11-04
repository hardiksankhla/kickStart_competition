#include<bits/stdc++.h>
using namespace std;


class segmentTree
{
private:
    vector<long long> st;
    int n;
public:
    segmentTree(vector<long long> &arr);
    void updateST(int index, vector<long long> &arr);
    long long sumST(int left, int rigth);
    ~segmentTree();
};

segmentTree::segmentTree(vector<long long> &arr)
{   
    this->n = arr.size();
    this->st = vector<long long> (2*n,0);
    
    for (int i = 0; i < n ; i++)
    {
        st[n+i] = arr[i];
    }
    for (int i = n-1; i >0 ; i--)
    {
        st[i] = st[2*i] + st[2*i + 1];
    }
}

void segmentTree::updateST(int index, vector<long long> &arr)
{
    st[n+index] = arr[index];
    index += n;

    while (index>1) 
    {
        index /= 2;
        st[index] = st[2*index]+st[2*index +1];
    }
}

long long segmentTree::sumST(int left, int right)
{
    long long sum = 0;
    left += n;
    right += n;

    while (left<=right)
    {
        if (left%2!=0)
        {
            sum += st[left];
            left += 1;
        }
        
        if (right%2==0)
        {
            sum += st[right];
            right -=1;
        }

        left/=2;
        right/=2;
    }
    return sum;
}

segmentTree::~segmentTree()
{
}


int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        int n, q;
        cin >> n >> q;

        vector<int> arr(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<long long> multiAltArr(n, 0);
        vector<long long> altArr(n, 0);
        
        for (int i = 0; i < n; i++)
        {
            multiAltArr[i] = pow(-1, i) * (i + 1) * arr[i];
            altArr[i] = pow(-1, i) * arr[i];
            // cout<<multiAltArr[i]<<" ";
        }
        // cout<<endl;

        // for (int i = 0; i < n; i++)
        // {
        //     cout<<altArr[i]<<" ";
        // }
        // cout<<endl;


        segmentTree stMultiAltArr(multiAltArr);
        segmentTree stAltArr(altArr);

        long long output = 0;

        for (int i = 0; i < q; i++)
        {
            char operation;
            cin >> operation;
            if (operation=='Q')
            {
                int left, right;
                cin >> left >> right;
                left--;
                right--;
                long long value = pow(-1, left)*( stMultiAltArr.sumST(0, right) - stMultiAltArr.sumST(0, left-1) - (left)*stAltArr.sumST(left, right) );
                // cout<<value<<" "<<endl;
                output += value;
            }
            if (operation=='U')
            {
                int pos, value;
                cin >> pos >> value;
                pos--;
                arr[pos]=value;
                multiAltArr[pos] = pow(-1, pos) * (pos + 1) * arr[pos];
                altArr[pos] = pow(-1, pos) * arr[pos];
                stMultiAltArr.updateST(pos, multiAltArr);
                stAltArr.updateST(pos, altArr);

            }
            
        }
        
        cout << "Case #" << a + 1 << ": " << output << endl;
    }
    
    return 0;
}
