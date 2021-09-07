#include<bits/stdc++.h>
using namespace std;

int calculateV(long long x, int p){
    int count = 0;
    if (x)
    {
        while (x % p == 0)
        {
            x=x/p;
            count++;
        }
    }
    return count;
}

void setV(int pos, int p, vector<long long> &arr, vector<long long> &AmodPisZero,  vector<long long> &AmodPisNotZero, vector<long long> &AmodPisNotZeroAndSevenP2, vector<long long> &countAmodPisNotZero){
    long long x = arr[pos]%p;
    if (!x)
    {
        AmodPisZero[pos] = calculateV(arr[pos], p);
        AmodPisNotZero[pos] = 0;
        AmodPisNotZeroAndSevenP2[pos] = 0;
        countAmodPisNotZero[pos] = 0;
    }
    else{
        AmodPisZero[pos] = 0;
        AmodPisNotZero[pos] = calculateV(arr[pos] - x, p);;
        AmodPisNotZeroAndSevenP2[pos] = calculateV(arr[pos] + x, p) - 1;
        countAmodPisNotZero[pos] = 1;
    } 
}

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
    // OR
    // n = arr.size();
    // st = vector<long long> (2*n);
    for (int i = 0; i < n ; i++)
    {
        st[n+i] = arr[i];
    }
    for (int i = n-1; i >0 ; i--)
    {
        st[i] = st[2*i] + st[2*i + 1];
    }
    // for (int i = 0; i < 2*n; i++)
    // {
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
    
}

void segmentTree::updateST(int index, vector<long long> &arr){
    st[n+index] = arr[index];
    index += n;
    while (index>1) 
    {
        index /= 2;
        st[index] = st[2*index]+st[2*index +1];
    }
    // for (int i = 0; i < 2*n; i++)
    // {
    //     cout<<st[i]<<" ";
    // }
    // cout<<endl;
}

long long segmentTree::sumST(int left, int right){
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


int main(){
    int t;
    cin>>t;
    for (int a = 0; a < t; a++)
    {
        int n,q,p;
        cin>>n>>q>>p;
        vector<long long> arr(n);//Ai
        vector<long long> AmodPisZero(n);//v(A)
        vector<long long> AmodPisNotZero(n);//v(a-b)
        vector<long long> AmodPisNotZeroAndSevenP2(n);//v(a+b) -1
        vector<long long> countAmodPisNotZero(n);//x
        
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            setV(i, p, arr, AmodPisZero, AmodPisNotZero, AmodPisNotZeroAndSevenP2, countAmodPisNotZero);
        }

        // segmentTree stAmodP =  segmentTree(arr);
        // OR
        // segmentTree st1(arr);
        segmentTree stAmodPisZero(AmodPisZero);
        segmentTree stAmodPisNotZero(AmodPisNotZero);
        segmentTree stAmodPisNotZeroAndSevenP2(AmodPisNotZeroAndSevenP2);
        segmentTree stcountAmodPisNotZero(countAmodPisNotZero);
        
        vector<long long> outArr;
        
        for (int i = 0; i < q; i++)
        {
            int qindx;
            cin>>qindx;
    
            if (qindx==1)
            {
                int pos, val;
                cin>>pos>>val;
                pos--;
                arr[pos] = val;
                setV(pos, p, arr, AmodPisZero, AmodPisNotZero, AmodPisNotZeroAndSevenP2, countAmodPisNotZero);
                stAmodPisZero.updateST(pos, AmodPisZero);
                stAmodPisNotZero.updateST(pos, AmodPisNotZero);
                stAmodPisNotZeroAndSevenP2.updateST(pos, AmodPisNotZeroAndSevenP2);
                stcountAmodPisNotZero.updateST(pos, countAmodPisNotZero);
            }


            else if (qindx==2)
            {
                int s,l,r;
                cin>>s>>l>>r;
                l--;
                r--;
                long long output = 0;
                int vOfS = calculateV(s, p);
                // cout<<"v of s = "<<vOfS<<endl;
                output += s*stAmodPisZero.sumST(l, r);
                // cout<<"stAmodPisZero = " << s*stAmodPisZero.sumST(l, r)<<endl;
                output += stAmodPisNotZero.sumST(l, r) + stcountAmodPisNotZero.sumST(l, r) * vOfS;
                if (s%2==0 and p==2)
                {
                    output += stAmodPisNotZeroAndSevenP2.sumST(l, r);
                }
                // cout<<output<<" ";
                outArr.push_back(output);
            }
            
        }
        cout<<"Case #"<<a+1<<": ";

        for (int i = 0; i < outArr.size(); i++)
        {
            cout<<outArr[i]<<" ";
        }
        
        cout<<endl;
    }
    return 0;
}
