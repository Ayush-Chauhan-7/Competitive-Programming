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

    int gcd(int a, int b, int& x, int& y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int d = gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }

    bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
        g = gcd(abs(a), abs(b), x0, y0);
        if (c % g) {
            return false;
        }

        x0 *= c / g;
        y0 *= c / g;
        if (a < 0) x0 = -x0;
        if (b < 0) y0 = -y0;
        return true;
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