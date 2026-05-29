/***********************************************
 Author        : Akiramenai_
 Created On    : 27/05/2026 22:03:58
 Problem       : Round Trip
************************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
vector<vector<int>>g;

bool is_cycle=0;
int en=0,st=0;
vector<int>visited,par;
void dfs(int node){
    visited[node]=1;

    for(auto v:g[node]){
        if(visited[v]&&v!=par[node]){//back edge to parent not 
            is_cycle=1;
            en=v;
            st=node;
        }
        else if(!visited[v]){
            par[v]=node;
            dfs(v);
        }
    }
}

void solve()
{
    cin>>n>>m;
    g.resize(n+1);

    visited.assign(n+1,0);
    par.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    vector<int>cycle;
    if(is_cycle){

        int temp=en;
        while(temp!=st){
            cycle.push_back(temp);
            temp=par[temp];
        }
        cycle.push_back(st);
        cycle.push_back(en);
        reverse(cycle.begin(),cycle.end());
        cout<<(int)cycle.size()<<"\n";
        for(auto v:cycle)cout<<v<<" ";
    }
    else {
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