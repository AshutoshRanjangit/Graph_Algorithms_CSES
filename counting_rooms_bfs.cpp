/***********************************************
 Author        : Akiramenai_
 Created On    : 27/05/2026 15:19:29
************************************************/
#include <bits/stdc++.h>
using namespace std;

//solving using bfs
#define int long long
#define F first
#define S second
using state=pair<int,int>;
const int INF=1e9;

int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

int n,m;
vector<string>arr;

vector<vector<int>>visited;

bool is_valid(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m && arr[x][y]=='.')return true;
    else return false;
}

void bfs(state st){

    queue<state>q;
    q.push(st);

    while(!q.empty()){
        state cur=q.front();
        q.pop();

        if(visited[cur.F][cur.S])continue;
        visited[cur.F][cur.S]=1;

        for(int i=0;i<4;i++){
            int nx=cur.F+dx[i];
            int ny=cur.S+dy[i];

            if(is_valid(nx,ny)&&(!visited[nx][ny])){
                q.push({nx,ny});
            }
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
                bfs({i,j});
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