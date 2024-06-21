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
        int n,x;
        cin>>n;
        vi primes(n+1,1),twos;
        primes[0] = 0;
        for(int i=2;i<=n;i++)
        {
            if(primes[i]==1)
            {
                for(int j=i;j<=n;j+=i)
                {
                    if(primes[j]==1)
                        primes[j] = i;
                }
            }
        }
        x = n;
        map<ll,ll> m;
        while(x>1)
        {
            m[primes[x]]++;
            x/=primes[x];
        }
        for(int i=2;i<=n;i*=2)
            twos.pb(i);
        ll ans = 1,maxi=0,c=0,rem,mini=1e18;
        for(auto i:m)
        {
            ans*=i.f;
            maxi = max(maxi,i.s);
            mini = min(mini,i.s);
            if(maxi==mini && binary_search(twos.begin(),twos.end(),i.s))
                continue;
            else
                c=1;
        }
        if(maxi>1)
        {
            rem = ceil(log2(maxi));
            c+=rem;
        }
        else
            c=0;
        cout<<ans<<" "<<c<<endl;
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