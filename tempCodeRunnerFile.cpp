

//D
#include <bits/stdc++.h>
using namespace std;

static const int INF = (1<<21);
int d[100010] = {INF};
int M[100010][100010];
int N;

void bfs(int s){
    queue<int> q;
    q.push(s);

    int u;
    while( !q.empty()){
        u = q.front();q.pop();
        for(int v = 0;v<N;v++){
            if(M[u][v] == 0) continue;
            if(d[v] != INF) continue;
            d[v] = d[u] + M[u][v];
            q.push(v);
        }
    }
}

int main(){
    cin >>N;
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++) M[i][j] = 0;
    }

    int u,v,w;
    for(int i = 0;i<N;i++){
        cin >> u >> v >> w; u--; v--;
        M[u][v] = w;
    }
    
    d[0] = 0;
    bfs(0);

    int ans;
    for(int i = 0;i<N;i++){
        ans = d[i]%2 == 0;
        cout << ans << endl;
    }

}