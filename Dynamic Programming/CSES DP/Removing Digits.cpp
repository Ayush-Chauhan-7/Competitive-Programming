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

    int dig(int n)
    {
        int maxi = 0;
        while(n)
        {
            maxi = max(maxi,n%10);
            n/=10;
        }
        return maxi;
    }

    void solve()
    {
        int n;
        cin>>n;
        int ans = 0,  rem;
        while(n)
        {
            rem = dig(n);
            n-=rem;
            ans++;
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
        solve();
        return 0;
    }