/***********************************************
 Author        : Akiramenai_
 Created On    : 27/05/2026 16:19:29
 Problem       : Labyrinth 
************************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first 
#define S second
using state=pair<int,int>;
const int INF=1e6;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char ch[]={'R','D','L','U'};

int n,m;
vector<string>arr;

vector<vector<int>>visited,dist;
vector<vector<state>>par;
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]!='#')return true;
    else return false;
}

void bfs(state st){
    visited.assign(n,vector<int>(m,0));
    dist.assign(n,vector<int>(m,INF));
    par.assign(n,vector<state>(m,{-1,1}));

    queue<state>q;
    q.push(st);
    dist[st.F][st.S]=0;
    par[st.F][st.S]={-1,-1};

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
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    state st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A')st={i,j};
            if(arr[i][j]=='B')en={i,j};
        }
    }

    bfs(st);

    if(dist[en.F][en.S]!=INF){
        cout<<"YES\n";
        cout<<dist[en.F][en.S]<<"\n";

        vector<pair<int,int>>path;
        state temp=en;
        while(temp!=st){
            path.push_back(temp);
            temp=par[temp.F][temp.S];
        }
        path.push_back(st);

        reverse(path.begin(),path.end());
        // for(auto v:path){
        //     cout<<v.F<<","<<v.S<<"\n";
        // }

        //now printing the directions
        for(int i=0;i<path.size()-1;i++){
            int delta_x=path[i+1].F-path[i].F;
            int delta_y=path[i+1].S-path[i].S;
            for(int i=0;i<4;i++){
                if(delta_x==dx[i]&&delta_y==dy[i]){
                    cout<<ch[i];
                }
            }
        }
        cout<<endl;
    }
    else {
        cout<<"NO\n";
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