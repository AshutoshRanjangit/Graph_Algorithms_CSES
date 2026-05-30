/***********************************************
 Author        : Akiramenai_
 Created On    : 30/05/2026 13:00:05
************************************************/
#include <bits/stdc++.h>
using namespace std;

//FLOYD WARSHALL ALGORITHM
//AS nodes are small
//we can build a adjacency matrix
#define int long long
const int INF=1e18;
int n,m,q;
vector<vector<int>>dist;

void solve()
{
    cin>>n>>m>>q;

    dist.assign(n+1,vector<int>(n+1,INF));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[b][a],c);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dist[i][j]=0;
        }
    }

    //flyod warshall algo
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                dist[j][i]=min(dist[j][i],dist[j][k]+dist[k][i]);
            }
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;

        if(dist[a][b]!=INF)
            cout<<dist[a][b]<<"\n";
        else 
            cout<<"-1\n";
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