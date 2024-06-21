    // https://codeforces.com/contest/1848/problem/C
    
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

    ll gcd(ll a, ll b) {
        if (a == 0) {
            return 0;
        }
        if (b == 0) {
            return 1;
        }
        if (a >= b) {
            ll r = a % b;
            ll k = a / b;
            if (k % 2 == 1) {
                return gcd(b, r) + k + k / 2;
            } else {
                return gcd(r, b) + k + k / 2;
            }
        }
        return 1 + gcd(b, abs(a - b));
    }

    void solve()
    {
        ll n,cnt,x,y,z;
        cin>>n;
        vi a(n),b(n);
        fo(i,n)
            cin>>a[i];
        fo(i,n)
            cin>>b[i];
        set<ll> c;
        fo(i,n)
        {
            if(a[i]==0 && b[i]==0)
                continue;
            c.insert(gcd(a[i],b[i])%3);
        }
        if(c.size()<=1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
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