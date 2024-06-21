    // https://codeforces.com/problemset/problem/1932/E
    
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vector<int> a(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            a[i] = a[i + 1] + (s[i] - '0');
        }
        string res;
        int c = 0;
        for (int i = 0; i < n; i++) {
            c += a[i];
            res += (char)(c % 10 + '0');
            c /= 10;
        }
        res += (char)(c + '0');
        while (res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        cout << res << "\n";
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