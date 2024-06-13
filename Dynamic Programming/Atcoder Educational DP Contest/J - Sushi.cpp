    #include <bits/stdc++.h>
    typedef long long ll;
    #define fo(i, n) for(int i=0;i<n;i++)
    #define vi vector<ll>
    #define vp vector< pair <ll,ll> >
    #define f first
    #define s second
    #define pb push_back
    #define endl '\n'

    using namespace std;
    
    long double dp[301][301][301];

    void solve()
    {
        int n, c1=0, c2=0, c3=0,z;
        cin>>n;
        vector<int> a(n);
        fo(i,n)
        {
            cin>>a[i];
            if(a[i]==1)
                c1++;
            else if(a[i]==2)
                c2++;
            else if(a[i]==3)
                c3++;
        }
        dp[0][0][0] = 0;
        fo(k, c3+1)
        {
            fo(j, n+1)
            {
                fo(i,n+1)
                {
                    z = i+j+k;
                    if(!z || z>n)
                        continue;
                    dp[i][j][k] = 1;
                    if(i>0)
                        dp[i][j][k] += (dp[i-1][j][k]*i)/n;
                    if(j>0)
                        dp[i][j][k] += (dp[i+1][j-1][k]*j)/n;
                    if(k>0)
                        dp[i][j][k] += (dp[i][j+1][k-1]*k)/n;
                    dp[i][j][k] *= (long double)n/z;
                }
            }
        }
        cout<<setprecision(10)<<dp[c1][c2][c3]<<endl;
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