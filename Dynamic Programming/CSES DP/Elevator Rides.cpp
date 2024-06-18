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
        int n,w,weight,groups;
        cin>>n>>w;
        vp dp(1<<n);
        vi a(n);
        fo(i,n)
            cin>>a[i];
        dp[0] = {1,0};
        for(ll mask=1;mask<(1<<n);mask++)
        {
            dp[mask] = {21,0};
            fo(i,n)
            {
                if(mask>>i&1)
                {
                    groups = dp[mask^(1<<i)].f;
                    weight = dp[mask^(1<<i)].s;
                    if(weight+a[i]>w)
                    {
                        groups++;
                        weight = a[i];
                    }
                    else
                        weight += a[i];
                    dp[mask] = min(dp[mask],{groups,weight});
                }
            }
        }
        cout<<dp[(1<<n)-1].f<<endl;
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