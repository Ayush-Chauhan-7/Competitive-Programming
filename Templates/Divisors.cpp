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


    long long numberOfDivisors(long long num) {
        long long total = 1;
        for (int i = 2; (long long)i * i <= num; i++) {
            if (num % i == 0) {
                int e = 0;
                do {
                    e++;
                    num /= i;
                } while (num % i == 0);
                total *= e + 1;
            }
        }
        if (num > 1) {
            total *= 2;
        }
        return total;
    }

    long long SumOfDivisors(long long num) {
        long long total = 1;

        for (int i = 2; (long long)i * i <= num; i++) {
            if (num % i == 0) {
                int e = 0;
                do {
                    e++;
                    num /= i;
                } while (num % i == 0);

                long long sum = 0, pow = 1;
                do {
                    sum += pow;
                    pow *= i;
                } while (e-- > 0);
                total *= sum;
            }
        }
        if (num > 1) {
            total *= (1 + num);
        }
        return total;
    }

    void solve()
    {
        ll n;
        cin>>n;
        vi div;
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