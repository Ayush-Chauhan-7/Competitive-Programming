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
        ll n,k;
        cin>>n>>k;
        vi a(n), dp(k+1);
        fo(i,n)
            cin>>a[i];
        fo(i,k+1)
        {
            fo(j,n)
            {
                if(i-a[j]>=0 && dp[i-a[j]]==0)
                    dp[i] = 1;
            }
        }
        cout<< (dp[k]==1?"First":"Second")<<endl; 
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