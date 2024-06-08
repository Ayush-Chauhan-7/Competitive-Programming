// G. Student Councils
// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

using namespace std;

int main() {
    ll n,k;
    cin>>k>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    auto cost = [n, k, &a](ll x){
        ll slots = x*k;
        for(int i=0;i<n;i++)
            slots -= min(x,a[i]);
        return slots<=0;
    };
    ll lo = 0;
    ll hi = *max_element(a.begin(),a.end())*((n/k)+1);
    while(lo<=hi)
    {
        ll mid = lo+((hi-lo)/2);
        if(cost(mid))
            lo = mid+1;
        else
            hi = mid-1;
    }
    cout<<hi<<endl;
    return 0;
}