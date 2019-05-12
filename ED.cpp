#include<bits/stdc++.h>
using namespace std;
int T = 0;
int S[5001][5001];
int LCS(string a, string b){
    int n = a.length();
    int m = b.length();
    int temp;


    for(int i=0;i<= max(n,m);i++){
        S[i][0] = i;
        S[0][i] = i;
    }
   for(int i=1;i<=n;i++)
   for(int j=1; j<=m; j++)
        {
            if(a[i-1] == b[j-1])
            {
                S[i][j] = S[i-1][j-1] + 0;
            }
            else {
               S[i][j] = min(min(S[i-1][j]+1,S[i][j-1]+1),S[i-1][j-1]+1);
            }
        }
  return S[n][m];
}
int main(){
    string a,b;
    cin >> T ;
    for(int i=0;i<T;i++){
        cin >> a >> b;
        cout << LCS(a,b) << endl;
    }
    return 0;
}
