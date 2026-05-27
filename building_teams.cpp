/***********************************************
 Author        : Akiramenai_
 Created On    : 27/05/2026 21:54:26
 Problem       : Building Teams
************************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long

//bipartite checking 
//using 3-color technique

int n,m;
vector<vector<int>>g;

bool is_possible=1;
vector<int>visited,color;
void dfs(int node,int col){
    visited[node]=1;
    color[node]=col;

    for(auto v:g[node]){
        if(color[v]==col){
            is_possible=0;
        }
        if(!visited[v]){
            dfs(v,3-col);
        }
    }
}

void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    visited.assign(n+1,0);
    color.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    //there can be disconnected compronents also 
    //we need to take care of that also

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,1);
        }
    }

    if(is_possible){
        for(int i=1;i<=n;i++){
            cout<<color[i]<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE";
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