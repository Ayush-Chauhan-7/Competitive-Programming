    // https://www.codechef.com/problems/TSHIRTS
    
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

    bool people[11][101];
    ll dp[1<<10];
    const int mod = 1e9 + 7;

    void in(int n)
    {
        string s;
        cin.ignore();
        for(int i=0;i<n;i++)
        {
            getline(cin,s);
            stringstream in(s);
            int a;
            while(in>>a)
                people[i][a] = 1;
        }
    }

    void solve()
    {
        ll n;
        cin>>n;
        memset(people, 0, sizeof people);
        memset(dp, 0, sizeof dp);
        in(n);
        dp[0] = 1;
        for(int i=1;i<=100;i++)
        {
            for(int j=(1<<n)-1;j>=0;j--)
            {
                for(int k=0;k<n;k++)
                {
                    if((j&(1<<k))==0 && people[k][i])
                    {
                        dp[j+(1<<k)] = (dp[j+(1<<k)]+dp[j])%mod;
                    }
                }
            }
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
        ll t;
        cin>>t;
        while(t--)
            solve();
        return 0;
    }