/***********************************************
 Author        : Akiramenai_
 Created On    : 27/05/2026 21:22:04
 problem       : Building Roads
************************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
vector<vector<int>>g;

vector<int>visited;
void dfs(int node){
    visited[node]=1;

    for(auto v:g[node]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    visited.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    int cc=0;

    vector<pair<int,int>>new_roads;
    int fs=-1;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(fs==-1){
                fs=i;
            }
            else {
                new_roads.push_back({fs,i});
                fs=i;
            }
            dfs(i);
            cc++;
        }
    }
    cout<<cc-1<<endl;
    for(auto v:new_roads){
        cout<<v.first<<" "<<v.second<<"\n";
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    // cin >> t;

    while (t--)
        solve();
    return 0;
}