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
        ll n;
        cin>>n;
        vi h(n);
        fo(i,n)
            cin>>h[i];
        ll p1=abs(h[1]-h[0]),p2=0, c1,c2;
        for(int i = 2;i<n;i++)
        {
            c1 = abs(h[i]-h[i-1]) + p1;
            c2 = abs(h[i]-h[i-2]) + p2;
            p2 = p1;
            p1 = min(c1,c2);
        }
        cout<<p1<<endl;
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