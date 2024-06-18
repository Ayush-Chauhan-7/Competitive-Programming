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

    ll dp[(100*1000)+1];

    void solve()
    {
        int n,sum=0;
        cin>>n;
        vi a(n);
        fo(i,n)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        dp[0] = 1;
        fo(i,n)
        {
            sum+=a[i];
            for(int j=sum;j>=a[i];j--)
                dp[j] |= dp[j-a[i]];
        }
        ll ans = 0;
        for(int i=1;i<=sum;i++)
        {
            if(dp[i])
                ans++;
        }
        cout<<ans<<endl;
        for(int i=1;i<=sum;i++)
        {
            if(dp[i])
                cout<<i<<" ";
        }
        cout<<endl;
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        solve();
        return 0;
    }