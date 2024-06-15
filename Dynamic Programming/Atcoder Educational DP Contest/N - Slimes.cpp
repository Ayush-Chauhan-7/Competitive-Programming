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

    ll dp[402][402];

    void solve()
    {
        ll n,cost,mini;
        cin>>n;
        vi a(n),pref(n);
        fo(i,n)
        {
            cin>>a[i];
            pref[i] = a[i];
            if(i)
                pref[i] += pref[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                mini = 1e18;
                cost = pref[j];
                if(i)
                    cost -= pref[i-1];
                for(int k=i+1;k<=j;k++)
                    mini = min(mini, cost + dp[i][k-1]+dp[k][j]);
                dp[i][j] = mini;
            }
        }
        cout<<dp[0][n-1]<<endl;
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