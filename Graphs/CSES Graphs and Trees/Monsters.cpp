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

    ll si,sj;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};
    char dir[4] = {'U','D','R','L'};

    void printPath(int i, int j, vector<vi> &path)
    {
        cout<<"YES"<<endl;
        string ans = "";
        while(i!=si || j!=sj)
        {
            int k = path[i][j] - 1;
            ans += dir[k];
            i -= dr[k];
            j -= dc[k];
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl<<ans<<endl;
        exit(0);
    }

    void solve()
    {
        ll n,m;
        cin>>n>>m;
        string grid[n];
        queue<pair<ll,ll>> q;
        vector<vi> d(n,vi(m,-1)),d1(n,vi(m,-1)),path(n,vi(m,-1));
        fo(i,n)
        {
            cin>>grid[i];
            fo(j,m)
            {
                if(grid[i][j]=='M')
                {
                    q.push({i,j});
                    grid[i][j] = '.';
                    d[i][j] = 0;
                }
                if(grid[i][j]=='A')
                {
                    si = i;
                    sj = j;
                    grid[i][j] = '.';
                    d1[i][j] = 0;
                }
            }
        }
        while(!q.empty())
        {
            int i = q.front().f;
            int j = q.front().s;
            q.pop();
            fo(k,4)
            {
                int ni = i + dr[k];
                int nj = j + dc[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='.' && d[ni][nj]==-1)
                {
                    d[ni][nj] = 1 + d[i][j];
                    q.push({ni,nj});
                }
            }
        }

        q.push({si,sj});

        while(!q.empty())
        {
            int i = q.front().f;
            int j = q.front().s;
            q.pop();
            fo(k,4)
            {
                int ni = i + dr[k];
                int nj = j + dc[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='.' && d1[ni][nj]==-1)
                {
                    d1[ni][nj] = 1 + d1[i][j];
                    path[ni][nj] = k+1;
                    q.push({ni,nj});
                }
            }
        }

        fo(i,n)
        {
            fo(j,m)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if((d[i][j]==-1 && d1[i][j]!=-1) || (d1[i][j]<d[i][j]))
                        printPath(i,j,path);
                }
            }
        }
        cout<<"NO"<<endl;
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