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
        k--;
        ll ans = (k)%n;
        if(n%2)
        {
            ll z = n/2;
            ans += (k/z);
            ans%=n;
        }
        cout<<ans + 1<<endl;
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