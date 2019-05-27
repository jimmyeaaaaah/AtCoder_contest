//D問題

#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int hoge(int max, int add){
    int n = 1; int ans = 0; int newnum;
    int m = max;
    while(max/10 != 0) {max = max/10;n++;}
    for(int i = 0;i<=n;i++){
        newnum = (m/(int)pow(10,i))*(int)pow(10,i+1) + add*pow(10,i) + m%(int)pow(10,i);
        //cout << newnum << endl;
        chmax(ans, newnum);
    }
    return ans;
}

int main(){
    int N,M; cin >> N >> M;
    int num[M], cost[M];
    int dp[N+1] = {-1};
    dp[0] = 0;
    int match[9] = {2,5,5,4,5,6,3,7,6};

    for(int i = 0;i<M;i++){
        cin >> num[i];
        cost[i] = match[num[i]-1];
    }

    for(int i =1; i<=N; i++){
        for(int j = 0; j<M; j++){
            if(i-cost[j] == 0) dp[i] = num[j];
            if ((i-cost[j]) > 0){
                chmax(dp[i],hoge(dp[i-cost[j]], num[j]));
            }
            chmax(dp[i],dp[i-1]);
        }
    }
    cout << dp[N] << endl;


}