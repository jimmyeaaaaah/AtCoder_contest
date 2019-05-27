//A

#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,D,x;
    cin >> r >> D >> x;
    for(int i = 0;i<10;i++){
        x = r*x -D;
        cout << x << endl;
    }

}



//B
#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B,ans;
    cin >> A >> B;
    if(A >= 13) ans = B;
    if(6 <= A && A<= 12) ans = B/2;
    if(A <6) ans = 0;

    cout << ans << endl;
}


//C
#include <bits/stdc++.h>
using namespace std;
vector<int> L(10010);
vector<int> R(10010);

int main(){
    int N,M;
    cin >> N >> M;
    for(int i = 0;i<M;i++){cin >> L[i]; cin >> R[i];}
    int maxL, minR;
    maxL = L[0]; minR = R[0];
    for(int i = 0;i<M;i++){
        if(L[i] > maxL) maxL = L[i];
        if(R[i] < minR) minR = R[i];
    }
    int ans = 0;
    if(maxL>minR){ ans = 0;}
    else {
        for(int i = maxL;i<=minR;i++) ans++;
    }
    cout << ans << endl;
}


//D

#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M;cin >> N >> M;
    vector<long long> A(N);
    vector<int>  B(M);
    vector<long long> C(M);
    for(int i= 0;i<N;i++) cin >> A[i];
    for(int i=0;i<M;i++) cin >> B[i]>>C[i];
    
    sort(A.begin(), A.end());
    for(int i = 0;i<M;i++){
        int  b = B[i]; long long c = C[i];
        int j = 0;
        while(c > A[j] && j < b){
            A[j] = c;
            j++;
        }
        if(c > A[b]){
            int k = b;
            while(A[k] < A[k-1] && k<N){
                swap(A[k], A[k-b]);
                //for(long long  a : A) cout << a << ' ';
                k++;
            }
        }
    }

    long long  ans = 0;
    for(int i = 0;i<N;i++) {ans += A[i];}
    cout << ans << endl;

}
