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

    d1 = sign(bs, pt1, pt2);
    d2 = sign(bs, pt2, pt3);
    d3 = sign(bs, pt3, pt1);

    if ( (d1 < 0 and d2 < 0 and d3 < 0) or (d1 > 0 and d2 > 0 and d3 > 0) )
    {
        return true;
    }
    return false;
}

bool pointOnTri(pair<int, int> &bs,  pair<int, int> &pt1, pair<int, int> &pt2, pair<int, int> &pt3){
    long long d1, d2, d3;

    d1 = sign(bs, pt1, pt2);
    d2 = sign(bs, pt2, pt3);
    d3 = sign(bs, pt3, pt1);

    if(d1 == 0 or d2 == 0 or d3 == 0){
        if ( (d1 <= 0 and d2 <= 0 and d3 <= 0) or (d1 >= 0 and d2 >= 0 and d3 >= 0) )
        {
            return true;
        }
    }
    return false;
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

long double findPera(pair<int, int> &pt1, pair<int, int> &pt2, pair<int, int> &pt3, pair<int, int> &pt4){
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

long double findPera(pair<int, int> &pt1, pair<int, int> &pt2){
    long long x1, x2, y1, y2, s1;
    
    x1 = pt1.first;
    x2 = pt2.first;
    y1 = pt1.second;
    y2 = pt2.second;

    s1 = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));

    long double ans;
    ans = sqrt(s1);
    return ans;
}

int main(){
    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        map<pair<int, int>, pair<int, int>> inLine;
        
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
                long double distance = INT_MAX;
                if (i != j)
                {
                    if (sign(v[i], bs, v[j]) == 0)
                    {
                        long double temp = findPera(bs, v[j]);
                        if ( (v[i].first < bs.first and bs.first < v[j].first ) or ( v[i].first > bs.first and bs.first > v[j].first ))
                        {   
                            if (distance > temp)
                            {
                                distance = temp;
                                inLine.insert({v[i], v[j]});
                            }
                        }
                        else if (v[i].first == bs.first and bs.first == v[j].first)
                        {
                            if ( (v[i].second < bs.second and bs.second < v[j].second ) or ( v[i].second > bs.second and bs.second > v[j].second ))
                            {
                                if (distance > temp)
                                {
                                    distance = temp;
                                    inLine.insert({v[i], v[j]});
                                }
                            }
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i != j and j != k and k != i)
                    {
                        if(pointInTri(bs, v[i], v[j], v[k]))
                        {
                            long double para = findPera(v[i], v[j], v[k]);
                            length = min(length, para);
                            foundTrap = true;
                        }
                        else
                        {  
                            if (pointOnTri(bs, v[i], v[j], v[k]))
                            {
                                pair<int, int> p4 {1e7, 1e7};
                                map<pair<int, int>, pair<int, int>> :: iterator itr;
                                
                                if (sign(v[i], bs, v[j]) == 0 and sign(v[j], bs, v[k]) == 0)
                                {
                                    continue;
                                }
                                
                                if (sign(v[i], bs, v[j]) == 0)
                                {   
                                    itr = inLine.find(v[k]);
                                    if (itr == inLine.end())
                                    {
                                        continue;
                                    }
                                    p4 = itr->second;

                                    long double para1 = findPera(v[i], v[k], v[j], p4);
                                    length = min(length, para1);
                                }

                                if (sign(v[i], bs, v[k]) == 0)
                                {   
                                    itr = inLine.find(v[j]);
                                    if (itr == inLine.end())
                                    {
                                        continue;
                                    }
                                    p4 = itr->second;

                                    long double para1 = findPera(v[i], v[j], v[k], p4);
                                    length = min(length, para1);
                                }

                                if (sign(v[j], bs, v[k]) == 0)
                                {   
                                    itr = inLine.find(v[i]);
                                    if (itr == inLine.end())
                                    {
                                        continue;
                                    }
                                    p4 = itr->second;

                                    long double para1 = findPera(v[j], v[i], v[k], p4);
                                    length = min(length, para1);
                                }

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
            cout<<"Case #"<<a+1<<": "<<length<<endl;
        }
        else{
            cout<<"Case #"<<a+1<<": "<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}