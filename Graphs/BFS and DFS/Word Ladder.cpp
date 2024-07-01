    // https://leetcode.com/problems/word-ladder/
    
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

    int ladderLength(string b, string e, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        if(!st.count(e))
            return 0;
        map<string,int> m;
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
        return m[e];
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