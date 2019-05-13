#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("test.txt", "r", stdin);
    int T,n;
    pair<int, int> P[10000];
    cin >> T;
    while(T--){
    cin >> n;
    int f,s;
    for(int i=0;i<n;i++){
            cin >> f >> s;
            P[i] = make_pair(s,f);
        }
    sort(P, P+n);

    int ed = -1;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(P[i].second >= ed){
            ed = P[i].first;
            ans++;
            }
        }
        cout << ans << endl;
   }
   return 0;
}
