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

    vector<ll> p,sz;

    void init(int n)
    {
        p.resize(n);
        sz.assign(n,1);
        iota(p.begin(),p.end(),0);
    }

    int find(int x)
    {
        while(x != p[x])
            x = p[x] = p[p[x]];
        return x;
    }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x==y)
            return false;
        if(sz[x]<sz[y])
            swap(x,y);
        sz[x] += sz[y];
        p[y] = x;
        return true;
    }

    void solve()
    {
        ll n,m,u,v,szz=0,x;
        cin>>n>>m;
        init(n+1);
        fo(i,m)
        {
            cin>>u>>v;
            if(unite(u,v))
            {
                n--;
                x = find(u);
                szz = max(szz,sz[x]);
            }
            cout<<n<<" "<<szz<<endl;
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