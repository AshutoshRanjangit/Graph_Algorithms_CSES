/***********************************************
 Author        : Akiramenai_
 Created On    : 29/05/2026 11:40:45
 Problem       : Monsters
************************************************/

//multisource bfs approach

#include <bits/stdc++.h>
using namespace std;
using state=pair<int,int>;
const int INF=1e9;
#define F first
#define S second
#define int long long

int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

int n,m;
vector<string>arr;

vector<vector<int>>visited;
vector<vector<state>>par;
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]=='.')return 1;
    else return 0;
}
void bfs(vector<state>st,vector<vector<int>>&dist){
    visited.assign(n,vector<int>(m,0));
    dist.assign(n,vector<int>(m,INF));
    par.assign(n,vector<state>(m,{-1,-1}));

    queue<state>q;

    for(auto v:st){
        q.push(v);
        dist[v.F][v.S]=0;
    }

    while(!q.empty()){
        state cur=q.front();
        q.pop();

        if(visited[cur.F][cur.S])continue;
        visited[cur.F][cur.S]=1;

        for(int i=0;i<4;i++){
            int nx=cur.F+dx[i];
            int ny=cur.S+dy[i];

            if(is_valid(nx,ny)){

                if(dist[nx][ny]>dist[cur.F][cur.S]+1){
                    dist[nx][ny]=dist[cur.F][cur.S]+1;
                    par[nx][ny]=cur;
                    q.push({nx,ny});
                }
            }
        }
    }

}

void solve()
{
    cin>>n>>m;
    arr.resize(n);

    vector<state>monsters,start;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='M')monsters.push_back({i,j});
            else if(arr[i][j]=='A')start.push_back({i,j});
        }
    }

    //run bfs from all the monsters starting with 0 dist
    vector<vector<int>>dist,dist_me;
    bfs(monsters,dist);

    bfs(start,dist_me);

    int final=1e9;
    state en;
    for(int i=0;i<n;i++){
        if(dist[i][0]>dist_me[i][0]){
            if(dist_me[i][0]<final){
                final=dist_me[i][0];
                en={i,0};
            }
        }

        if(dist[i][m-1]>dist_me[i][m-1]){
            if(dist_me[i][m-1]<final){
                final=dist_me[i][m-1];
                en={i,m-1};
            }
        }
    }

    for(int j=0;j<m;j++){
        if(dist[0][j]>dist_me[0][j]){
            if(dist_me[0][j]<final){
                final=dist_me[0][j];
                en={0,j};
            }
        }

        if(dist[n-1][j]>dist_me[n-1][j]){
            if(dist_me[n-1][j]<final){
                final=dist_me[n-1][j];
                en={n-1,j};
            }
        }
    }


    if(final!=1e9){
        cout<<"YES\n";
        cout<<final<<"\n";
        vector<state>path;

        state temp=en;

        while(temp!=start[0]){
            path.push_back(temp);
            temp=par[temp.F][temp.S];
        }
        path.push_back(start[0]);

        reverse(path.begin(),path.end());

        for(int i=0;i<path.size()-1;i++){
            if(path[i+1].F-path[i].F>0)cout<<"D";
            if(path[i+1].F-path[i].F<0)cout<<"U";

            if(path[i+1].S-path[i].S>0)cout<<"R";
            if(path[i+1].S-path[i].S<0)cout<<"L";
        }
    }
    else{
        cout<<"NO";
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