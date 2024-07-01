    // https://leetcode.com/problems/word-ladder-ii/
    
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

    vector<vector<string>> findLadders(string b, string e, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        if(!st.count(e))
            return ans;
        unordered_map<string,int> m;
        queue<string> q;
        int sz = b.size();
        m[b] = 1;
        st.erase(b);
        q.push(b);
        while(!q.empty())
        {
            string word = q.front();
            if(word==e)
                break;
            int pos = m[word];
            q.pop();
            for(int i=0;i<sz;i++)
            {
                char x = word[i];
                for(char j='a';j<='z';j++)
                {
                    if(j==x)
                        continue;
                    word[i] = j;
                    if(st.count(word))
                    {
                        q.push(word);
                        m[word] = pos+1;
                        st.erase(word);
                    }
                }
                word[i] = x;
            }
        }
        unordered_map<int,vector<string>> rm;
        for(auto i:m)
            rm[i.second].push_back(i.first);
        vector<string> seq;
        seq.push_back(e);
        auto dfs = [&](int pos, string word,auto&& dfs) -> void
        {
            if(pos==1)
            {
                if(word==b)
                {
                    reverse(seq.begin(),seq.end());
                    ans.push_back(seq);
                    reverse(seq.begin(),seq.end());
                }
                return;
            }
            int ind = pos-1;
            for(string prev:rm[ind])
            {
                int c=0;
                for(int i=0;i<sz;i++)
                {
                    if(word[i]!=prev[i])
                        c++;
                }
                if(c==1)
                {
                    seq.push_back(prev);
                    dfs(ind,prev,dfs);
                    seq.pop_back();
                }
            }
        };
        dfs(m[e],e,dfs);
        return ans;
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