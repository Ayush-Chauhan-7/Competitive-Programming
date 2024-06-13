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
        ll n,W,sum=0;
        cin>>n>>W;
        vi v(n), w(n);
        fo(i,n)
        {
            cin>>w[i]>>v[i];
            sum += v[i];
        }
        vi dp(sum+1,1e12);
        dp[0] = 0;
        fo(i,n)
        {
            for(int j = sum - v[i]; j>=0; j--)
                dp[j+v[i]] = min(dp[j]+w[i], dp[j+v[i]]);
        }
        for(int i=sum; i>=0; i--)
        {
            if(dp[i]<=W)
            {
                cout<<i<<endl;
                return;
            }
        }
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