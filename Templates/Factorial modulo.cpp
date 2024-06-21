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

    int factmod(int n, int p) {
        vector<int> f(p);
        f[0] = 1;
        for (int i = 1; i < p; i++)
            f[i] = f[i-1] * i % p;

        int res = 1;
        while (n > 1) {
            if ((n/p) % 2)
                res = p - res;
            res = res * f[n%p] % p;
            n /= p;
        }
        return res;
    }

    void solve()
    {
        
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