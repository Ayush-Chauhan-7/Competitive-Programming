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

    int ans[9][9];
 
    int mv[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    
    struct node{
        int y,x,w;
        bool operator()(node n1,node n2){return n1.w>n2.w;}
    };
    
    bool dfs(int y,int x,int i){
        ans[y][x]=i;
        
        if(i==64)return true;
        
        priority_queue<node,vector<node>,node> pq;
        for(int a=0;a<8;a++){
            int ny=y+mv[a][0],nx=x+mv[a][1];
            if(ny<1||ny>8||nx<1||nx>8)continue;
            if(ans[ny][nx])continue;
        
            int w=0;
            for(int b=0;b<8;b++){
                int nny=ny+mv[b][0],nnx=nx+mv[b][1];
                if(nny<1||nny>8||nnx<1||nnx>8)continue;
                if(ans[nny][nnx])continue;
                w++;
            }
            
            pq.push({ny,nx,w});
        }
        
        while(!pq.empty()){
            node cur=pq.top();
            pq.pop();
            if(dfs(cur.y,cur.x,i+1))return true;
        }
        
        ans[y][x]=0;
        return false;
    }
    
    void solve(){
        int x,y;
        cin>>x>>y;
        dfs(y,x,1);
        for(int a=1;a<=8;a++){
            for(int b=1;b<=8;b++)cout<<ans[a][b]<<" ";
            cout<<endl;
        }
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