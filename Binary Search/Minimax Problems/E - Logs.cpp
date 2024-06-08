// E - Logs
// https://atcoder.jp/contests/abc174/tasks/abc174_e

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    auto cost = [n,k,&a](ll x)
    {
        ll count = 0;
        for(int i=0;i<n;i++)
        {
            count += (a[i]-1)/x;
            if(count>k)
                return false;
        }
        return true;
    };
    ll low=1, high = *max_element(a.begin(),a.end());
    while(low<=high)
    {
        ll mid = (low) + ((high-low)/2);
        if(cost(mid))
            high = mid-1;
        else
            low = mid+1;
    }
    cout<<low<<endl;
    return 0;
}