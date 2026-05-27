/***********************************************
 Author        : Akiramenai_
 Created On    : 27/05/2026 21:39:23
 Problem       : Message Route
************************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF=1e6;
int n,m;
vector<vector<int>>g;

vector<int>visited,dist,par;
void bfs(int node){
    visited.assign(n+1,0);
    dist.assign(n+1,INF);
    par.assign(n+1,-1);

    queue<int>q;
    q.push(node);
    dist[node]=1;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        if(visited[cur])continue;
        visited[cur]=1;

        for(auto v:g[cur]){
            if(dist[v]>dist[cur]+1){
                dist[v]=dist[cur]+1;
                par[v]=cur;
                q.push(v);
            }
        }
    }
}
void solve()
{
    cin>>n>>m;
    g.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1);

    if(dist[n]!=INF){
        cout<<dist[n]<<"\n";
        
        vector<int>path;
        int temp=n;
        while(temp!=1){
            path.push_back(temp);
            temp=par[temp];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        for(auto v:path)cout<<v<<" ";
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