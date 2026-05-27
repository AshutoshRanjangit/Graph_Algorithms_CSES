/***********************************************
 Author        : Akiramenai_
 Created On    : 27/05/2026 14:49:11
************************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
using state =pair<int,int>;

int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

//find number of components
int n,m;
vector<string>arr;

vector<vector<int>>visited;
bool is_valid(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m && arr[x][y]=='.')return true;
    else return false;
}
void dfs(state node){
    visited[node.F][node.S]=1;

    for(int i=0;i<4;i++){
        int nx=node.F+dx[i];
        int ny=node.S+dy[i];

        if(is_valid(nx,ny)&&(!visited[nx][ny])){
            dfs({nx,ny});
        }
    }
}
void solve()
{
    cin>>n>>m;
    arr.resize(n);
    visited.assign(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.'&&(!visited[i][j])){
                dfs({i,j});
                cnt++;
            }
        }
    }

    cout<<cnt;
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