#include<bits/stdc++.h>
using namespace std;
int T;
string a,b;
int f[10000][10000];
void LCS(string a, string b){
        int lena = a.length();
        int lenb = b.length();

        for(int i=0;i<=max(lena, lenb);i++){
            f[i][0] = 0;
            f[0][i] = 0;
        }
        for(int i=1 ; i<=lena;i++)
            for(int j=1;j<=lenb;j++){
                    if(a[i-1] == b[j-1])
                        f[i][j] = f[i-1][j-1] + 1;
                    else
                        f[i][j] = max(f[i-1][j],f[i][j-1]);
        }
        cout << f[lena][lenb];
}
int main(){

    cin >> T;
    while(T){
        cin >> a >> b;
        LCS(a,b);
        T--;
    }
}
