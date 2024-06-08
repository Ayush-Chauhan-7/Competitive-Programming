    // Problem Link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
    
    #include <bits/stdc++.h>
    typedef unsigned long long ll;
    #define fo(i, n) for(ll i=0;i<n;i++)
    #define vi vector<ll>
    #define vp vector< pair <ll,ll> >
    #define f first
    #define s second
    #define pb push_back
    #define endl '\n'

    using namespace std;

    bool cost(ll n, ll x, ll y, ll k)
    {
        if(k<min(x,y))
            return false;
        ll ans = 1;
        k -= min(x,y);
        ans += (k/x) + (k/y);
        return ans>=n;
    }

    void solve()
    {
        ll n,x,y;
        cin>>n>>x>>y;
        ll low = 1, high = n * min(x, y);
        while(low<high)
        {
            ll mid = (low+high)/2;
            if(cost(n,x,y,mid))
                high = mid;
            else
                low = mid+1;
        }
        cout<<low<<endl;    
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        // ll t;
        // cin>>t;
        // while(t--)
            solve();
        return 0;
    }