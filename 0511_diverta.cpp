#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int counter = 0;
    vector<int> rgb(3);
    for (int i = 0;i<3;i++){
        cin >> rgb[i];
    }
    sort(rgb.begin(),rgb.end());
    reverse(rgb.begin(),rgb.end());
    cin >> N;

    int a,b,c;
    for(int i = 0;i < 5000;i++){
        //cout << i << endl;
        a = N - rgb[0]*i;
        if (a < 0) break;
        if (a == 0) {counter ++; break;}

        for(int j = 0;j < 4000;j++){
            b = a - rgb[1]*j;
            if(b < 0) break;
            if (b == 0) {counter++; break;}

            for(int k = 0;k<4000;k++){
                c = b - rgb[2]*k;
                if (c == 0) {counter++;break;}
                if (c < 0) break;
            }
        }
    }
    cout << counter<< endl;
}


#include <bits/stdc++.h>
using namespace std;


int find_ab(string s){
    int abnum = 0;
    for(int i = 0;i<s.size();i++){
        if (s[i] == 'A'){
            if (s[i+1] == 'B') abnum ++;
        }
    }
    return abnum;
}

int main(){
    int N,last;
    string str;
    cin >> N;
    vector<string> vec(N);
    for(int i = 0;i<N;i++) cin >> vec[i];

    int ab = 0;
    int a = 0;
    int b = 0;
    int AB = 0;
    for(int i = 0;i<N;i++){
        str = vec[i];
        AB += find_ab(str);

        last = str.size()-1;
        if (str[0] == 'B' && str[last] == 'A') ab++;
        else if (str[0] == 'B') b++;
        else if (str[last] == 'A') a++;
    }

    if (ab == 0) cout << min(a,b) + AB << endl;
    else if (a == 0 && b == 0) cout << ab - 1 + AB << endl;
    else if (a == 0 || b == 0) cout << ab + AB << endl;
    else cout << min(a,b) + ab + AB<< endl;
}





#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, rootN;
    int fav = 0;
    cin >> N;
    rootN = sqrt(N) ; //root N 以下の最大の整数
    cout << rootN;
    for(int x = 1; x<rootN; x++){
        if (N % (x+1) == 0 &&  N/(x+1) > x) fav += (N/(x+1));
    }
    cout << fav << endl;
}