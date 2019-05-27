//A
#include <bits/stdc++.h>
using namespace std;
int main(){
       int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<char> vec(N);
    for (int i = 0;i<N;i++){
        char s = S[i];
        if (i != K-1) vec[i] = s;
        else vec[i] = tolower(s);
    }
    for(int i = 0;i<N;i++){
        cout << vec[i];
    }
    cout << endl;
}





//B
#include <bits/stdc++.h>
using namespace std;

int main(){
    string S,ans;
    cin >> S;
    int s = atoi(S.c_str());
    int b = s%100;
    int a = (s-b) / 100;
    if(1<=a && a <= 12){
        if (1<=b &&b<=12){
            ans = "AMBIGUOUS";
        }else ans = "MMYY";
    }else if(1<=b &&b<=12){
        ans = "YYMM";
    }else ans = "NA";

    cout << ans << endl;
}




//C
#include <bits/stdc++.h>
using namespace std;
double dice(int i,int K){
    int k = i;
    int count = 0;
    while(k < K){
        k = k*2;
        count++;
    }
    //cout << pow(0.5,count) << endl;
    return pow(0.5, count);
}

int main(){
    int N,K;
    double ans=0;
    cin >> N >> K;
    for(int i= 1;i<=N;i++){
        ans += dice(i,K);
    }
    ans = ans / N;
    cout <<setprecision(12)<< ans << endl;
}




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