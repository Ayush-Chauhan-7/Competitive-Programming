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

    int phi(int n) {
        int result = n;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        }
        if (n > 1)
            result -= result / n;
        return result;
    }

    void phi_1_to_n(int n) {
        vector<int> phi(n + 1);
        phi[0] = 0;
        phi[1] = 1;
        for (int i = 2; i <= n; i++)
            phi[i] = i - 1;

        for (int i = 2; i <= n; i++)
            for (int j = 2 * i; j <= n; j += i)
                phi[j] -= phi[i];
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