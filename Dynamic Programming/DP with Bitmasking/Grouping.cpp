    // https://atcoder.jp/contests/dp/tasks/dp_u
    
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

    ll a[16][16], dp[1<<16], score[1<<16];

    void solve()
    {
        int n;
        cin>>n;
        fo(i,n)
            fo(j,n)
                cin>>a[i][j];
        fo(i,1<<n)
        {
            fo(j,n)
            {
                if(i>>j&1)
                {
                    for(int k=j+1;k<n;k++)
                    {
                        if(i>>k&1)
                            score[i] += a[j][k];
                    }
                }
            }
        }
        fo(i,1<<n)
        {
            for(int j=i; j; j= (j-1)&i)
                dp[i] = max(dp[i], dp[i^j]+score[j]);
        }
        cout<<dp[(1<<n)-1]<<endl;
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