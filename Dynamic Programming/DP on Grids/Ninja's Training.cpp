// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ll p1,p2,p3,d1,d2,d3,n;
    cin>>n;
    cin>>p1>>p2>>p3;
    for(int i=1;i<n;i++)
    {
        cin>>d1>>d2>>d3;
        d1 += max(p2,p3);
        d2 += max(p1,p3);
        d3 += max(p1,p2);
        p1 = d1;
        p2 = d2;
        p3 = d3;
    }
    cout<<max(p1,max(p2,p3))<<endl;
    
    return 0;
}