/***********************************************
 Author        : Akiramenai_
 Created On    : 30/05/2026 12:06:23
 Problem       : Shortest Routes I
************************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
const int INF=1e17;
using state=pair<int,int>;

int n,m;
vector<vector<state>>g;

vector<int>visited,dist;
void dijkstra(){
    visited.assign(n+1,0);
    dist.assign(n+1,INF);

    priority_queue<state,vector<state>,greater<>>pq;

    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty()){
        state cur=pq.top();
        pq.pop();

        if(visited[cur.S])continue;
        visited[cur.S]=1;

        for(auto x:g[cur.S]){
            int v=x.F;
            int wt=x.S;
            if(dist[v]>dist[cur.S]+wt){
                dist[v]=dist[cur.S]+wt;
                pq.push({dist[v],v});
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }

    dijkstra();

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
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