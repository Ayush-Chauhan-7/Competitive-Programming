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

    vector<long long> trial_division3(long long n) {
            vector<long long> factorization;
            for (int d : {2, 3, 5}) {
                while (n % d == 0) {
                    factorization.push_back(d);
                    n /= d;
                }
            }
            static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
            int i = 0;
            for (long long d = 7; d * d <= n; d += increments[i++]) {
                while (n % d == 0) {
                    factorization.push_back(d);
                    n /= d;
                }
                if (i == 8)
                    i = 0;
            }
            if (n > 1)
                factorization.push_back(n);
            return factorization;
        }

    void solve()
    {
        int n,x;
        cin>>n;
        vi primes(n+1,1),pf;
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
        while(x>1)
        {
            pf.pb(primes[x]);
            x/=primes[x];
        }
        for(auto i:pf)
            cout<<i<<" ";
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