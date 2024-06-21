    // https://codeforces.com/contest/1485/problem/C
    
    #include <bits/stdc++.h>
    typedef long long ll;
    #define fo(i, n) for(ll i=0;i<n;i++)
    #define vi vector<ll>
    #define vp vector< pair <ll,ll> >
    #define f first
    #define s second
    #define pb push_back
    #define endl '\n'

    using namespace std;


    void solve()
    {
        ll x,y,ans=0;
        cin >> x >> y;
        // a = bk + k 
        // k < b --> k * k < bk + k --> k < sqrt(x)
        for (int i = 1; i * i <= x; i++) 
        {
            // a = (k + 1) b s.t a <= x && b <= y
            ans += max(0ll, min(y, x / i - 1) - i);
        }
        cout<<ans<<endl;
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        ll t;
        cin>>t;
        while(t--)
            solve();
        return 0;
    }