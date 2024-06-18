    // https://codeforces.com/blog/entry/84641
    
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
    ll pre[20], five[20];

    ll count(ll x)
    {
        string s = to_string(x);
        int n = s.size(), digit;
        ll ans = pre[n-1];
        for(int i=1;i<=n;i++)
        {
            digit = s[i-1]-'0';
            if(digit%2!=i%2)
            {
                ans += ((digit+1)/2)*five[n-i];
                break;
            }
            else
            {
                ans += (digit/2)*five[n-i];
                if(i==n)
                    ans++;
            }
        }
        return ans;
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        five[0] = 1;
        for(int i=1;i<20;i++)
        {
            five[i] = 5*five[i-1];
            pre[i] = pre[i-1] + five[i];
        }
        ll t;
        cin>>t;
        while(t--)
        {
            ll L,R;
            cin>>L>>R;
            L--;
            ll sol = count(R)-count(L);
            cout<<sol<<endl;
        }
        return 0;
    }