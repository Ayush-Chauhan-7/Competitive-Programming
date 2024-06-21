    // https://codeforces.com/problemset/problem/1091/C
    
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
        ll n,last,terms;
        cin>>n;
        vi div,ans;
        for(int i=1;i<=sqrtl(n);i++)
        {
            if(n%i==0)
            {
                if(n/i == i)
                    div.pb(i);
                else
                {
                    div.pb(i);
                    div.pb(n/i);
                }
            }
        }
        for(ll i: div)
        {
            last = n-i+1;
            terms = n/i;
            ans.pb((terms*(1+last))/2);
        }
        sort(ans.begin(),ans.end());
        for(ll i:ans)
            cout<<i<<" ";
        cout<<endl;
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