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
        int n,m,si,sj,ei,ej,f=0;
        cin>>n>>m;
        string grid[n];
        vector<vi> path(n,vi(m,0));
        fo(i,n)
        {
            cin>>grid[i];
            fo(j,m)
            {
                if(grid[i][j]=='A')
                {
                    si = i;
                    sj = j;
                    grid[i][j] = '#';
                }
                if(grid[i][j]=='B')
                {
                    ei = i;
                    ej = j;
                    grid[i][j] = '.';
                }
            }
        }
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,1,-1};
        char dir[4] = {'U','D','R','L'};
        map<char,int> drr;
        drr['U'] = 1, drr['D']=0, drr['R']=3, drr['L']=2;
        queue<pair<int,int>> q;
        q.push({si,sj});
        while(!q.empty())
        {
            int i = q.front().f;
            int j = q.front().s;
            q.pop();
            fo(k,4)
            {
                int ni = i+dr[k];
                int nj = j+dc[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='.')
                {
                    grid[ni][nj] = '#';
                    path[ni][nj] = k+1;
                    if(ni==ei && nj==ej)
                        f=0;
                    q.push(make_pair(ni,nj));
                }
            }
            if(f)
                break;
        }
        int i=ei, j = ej;
        if(path[i][j]!=0)
        {
            cout<<"YES"<<endl;
            string ans = "";
            while(i!=si || j!=sj)
            {
                int k = path[i][j]-1;
                ans += dir[k];
                i -= dr[k];
                j -= dc[k];
                
            }
            reverse(ans.begin(),ans.end());
            cout<<ans.size()<<endl<<ans<<endl;
        }
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
        solve();
        return 0;
    }