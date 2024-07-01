    // https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
    
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

    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int> q;
        q.push(start);
        vector<int> dist(100000,-1);
        dist[start] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(u==end)
                break;
            for(auto i:arr)
            {
                int v = (u*i)%(100000);
                if(dist[v]==-1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[end];
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        return 0;
    }