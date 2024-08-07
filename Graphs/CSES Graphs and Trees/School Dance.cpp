#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005;
ll n,id,vis[N],path[N],pathLength;
vector<vector<ll>>adj(N,vector<ll>(N)),temp;
ll getPath(ll src,ll sink,ll curLen,ll maxCap)
{
    path[curLen]=src;
    if(src==sink)
    {
        pathLength=curLen+1;
        return maxCap;
    }
    ll ret=0;
    vis[src]=id;
    for(ll i=0; i<n; i++)
    {
        if(vis[i]==id||adj[src][i]<=0)continue;
        ret=getPath(i,sink,curLen+1,min(maxCap,adj[src][i]));
        if(ret>0)break;
    }
    return ret;
}
ll maxFlow(ll src,ll sink)
{
    ll total_flow=0;
    while(1)
    {
        id++;
        ll newFlow=getPath(src,sink,0,INT_MAX);
        if(!newFlow)break;
        for(ll i=1; i<pathLength; i++)
        {
            ll j=path[i-1],k=path[i];
            adj[j][k]-=newFlow;
            adj[k][j]+=newFlow;
        }
        total_flow+=newFlow;
    }
    return total_flow;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,m,k;
    cin>>a>>m>>k;
    n=a+m+2;
    vector<int>u(k),v(k);
    for(int i=0; i<k; i++)
    {
        cin>>u[i]>>v[i],--u[i],--v[i];
        adj[u[i]][a+v[i]]++;
    }
    for(int i=0;i<a;i++){
        adj[a+m][i]++;
    }
    for(int i=0;i<m;i++){
        adj[i+a][a+m+1]++;
    }
    temp=adj;
    cout<<maxFlow(a+m,a+m+1)<<'\n';
    for(int i=0;i<a;i++){
        for(int j=a;j<a+m;j++){
            if(adj[i][j]!=temp[i][j])cout<<i+1<<' '<<j-a+1<<'\n';
        }
    }
    return 0;
}