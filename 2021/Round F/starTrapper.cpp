#include<bits/stdc++.h>
using namespace std;

long long sign(pair<int, int> &p1,  pair<int, int> &p2, pair<int, int> &p3){
    long long x1, x2, x3, y1, y2, y3, ans;
    x1 = p1.first;
    x2 = p2.first;
    x3 = p3.first;
    y1 = p1.second;
    y2 = p2.second;
    y3 = p3.second;

    ans = (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
    return ans;
}

bool pointInTri(pair<int, int> &bs,  pair<int, int> &pt1, pair<int, int> &pt2, pair<int, int> &pt3){
    long long d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(bs, pt1, pt2);
    d2 = sign(bs, pt2, pt3);
    d3 = sign(bs, pt3, pt1);

    has_neg = (d1 < 0) and (d2 < 0) and (d3 < 0);
    has_pos = (d1 > 0) and (d2 > 0) and (d3 > 0);

    if(d1 == 0 or d2 == 0 or d3 == 0){
        return false;
    }

    return (has_neg or has_pos);
}

bool pointInQuad(pair<int, int> &bs,  pair<int, int> &pt1, pair<int, int> &pt2, pair<int, int> &pt3, pair<int, int> &pt4){
    long long d1, d2, d3, d4;
    bool has_neg, has_pos;

    d1 = sign(bs, pt1, pt2);
    d2 = sign(bs, pt2, pt3);
    d3 = sign(bs, pt3, pt4);
    d4 = sign(bs, pt4, pt1);

    has_neg = (d1 < 0) and (d2 < 0) and (d3 < 0) and (d4 < 0);
    has_pos = (d1 > 0) and (d2 > 0) and (d3 > 0) and (d4 > 0);

    if(d1 == 0 or d2 == 0 or d3 == 0 or d4 == 0){
        return false;
    }

    return (has_neg or has_pos);
}

long double findPera(pair<int, int> &pt1, pair<int, int> &pt2, pair<int, int> &pt3){
    long long x1, x2, y1, y2, s1, s2, s3;
    
    x1 = pt1.first;
    x2 = pt2.first;
    y1 = pt1.second;
    y2 = pt2.second;

    s1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));

    x1 = pt2.first;
    x2 = pt3.first;
    y1 = pt2.second;
    y2 = pt3.second;

    s2 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));

    x1 = pt3.first;
    x2 = pt1.first;
    y1 = pt3.second;
    y2 = pt1.second;

    s3 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));

    long double ans;
    ans = sqrt(s1) + sqrt(s2) + sqrt(s3);
    return ans;
}

long double findPera1(pair<int, int> &pt1, pair<int, int> &pt2, pair<int, int> &pt3, pair<int, int> &pt4){
    long long x1, x2, y1, y2, s1, s2, s3, s4;
    
    x1 = pt1.first;
    x2 = pt2.first;
    y1 = pt1.second;
    y2 = pt2.second;

    s1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));

    x1 = pt2.first;
    x2 = pt3.first;
    y1 = pt2.second;
    y2 = pt3.second;

    s2 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));

    x1 = pt3.first;
    x2 = pt4.first;
    y1 = pt3.second;
    y2 = pt4.second;

    s3 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));

    x1 = pt4.first;
    x2 = pt1.first;
    y1 = pt4.second;
    y2 = pt1.second;

    s4 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));

    long double ans;
    ans = sqrt(s1) + sqrt(s2) + sqrt(s3) + sqrt(s4);

    return ans;
}

int main(){
    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        
        for (int i = 0; i < n; i++)
        {   int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }

        sort(v.begin(), v.end());

        pair<int, int> bs;
        cin >> bs.first >> bs.second;
        long double length = INT64_MAX;
        bool foundTrap = false;
        bool foundInQuad = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if(pointInTri(bs, v[i], v[j], v[k]))
                    {
                        long double para = findPera(v[i], v[j], v[k]);
                        length = min(length, para);
                        foundTrap = true;
                    }
                    else
                    {
                        for (int l = 0; l < n; l++)
                        {
                            if (pointInQuad(bs, v[i], v[j], v[k], v[l]))
                            {
                                long double para1 = findPera1(v[i], v[j], v[k], v[l]);
                                length = min(length, para1);
                                foundTrap = true;
                                foundInQuad = true;
                            }
                        }
                    }
                }
            }
        }
        
        cout.precision(20);
        if(foundTrap)
        {
            // if (foundInQuad)
            // {
            //     cout<<"Quad"<<endl;
            // }
            
            cout<<"Case #"<<a+1<<": "<<length<<endl;
        }
        else{
            cout<<"Case #"<<a+1<<": "<<"IMPOSSIBLE"<<endl;
        }

    }
    return 0;
}