    // https://codeforces.com/contest/1110/problem/C
    
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

    vi decToBinary(int n)
    {
        vi ans;
        ll flag=0;
        for (int i = 25; i >= 0; i--) {
            int k = n >> i;
            if (k & 1)
            {
                ans.pb(1);
                flag=1;
            }
            else if(flag)
                ans.pb(0);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void solve()
    {
        ll n,b=0;
        cin>>n;
        vi a = decToBinary((n));
        fo(i,a.size())
            b += (a[i]==0)*(1<<i);
        if(!b)
        {
            for(int i=3;i*i<=n;i+=2)
            {
                if(n%i==0)
                {
                    b = n/i;
                    break;
                }
            }
        }
        b = max(1ll,b);
        cout<<__gcd((n&b),(n^b))<<endl;
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