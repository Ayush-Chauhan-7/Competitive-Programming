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

    int find(vector<int> &union_find, int ind) {
        while(union_find[ind] != ind)
            ind = union_find[ind];
        return ind;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> m;
        vector<int> union_find(accounts.size(), 0);
        unordered_map<int, vector<string>> res_map;
        for (int i = 0; i < accounts.size(); i++) {
            union_find[i] = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                if (m.find(accounts[i][j]) != m.end()) {
                    int root1 = find(union_find, i);
                    int root2 = find(union_find, m[accounts[i][j]]);
                    union_find[root1] = root2;
                }
                else
                    m[accounts[i][j]] = union_find[i];
            }
        }
        for (auto it : m) {
            int ind = find(union_find, it.second);
            res_map[ind].push_back(it.first);
        }
        vector<vector<string>> res;
        for (auto it : res_map) {
            vector<string> email = it.second;
            sort(email.begin(), email.end());
            email.insert(email.begin(), accounts[it.first][0]);
            res.push_back(email);
        }
        return res;
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