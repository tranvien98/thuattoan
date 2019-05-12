#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
int A[MAX][MAX];
int n,m, d,c;
int ketqua[MAX];
int dem = 0;
int w = 0;
void minpath(){
    int danhdau[MAX];
    int nhan[MAX];
    int truoc[MAX];
    int xp, minn;
    for(int i=0;i<n;i++){
        danhdau[i] = 0;
        nhan[i] = 999999999;
        truoc[i] = d;
    }
    nhan[d] = 0;
    danhdau[d] = 1;
    xp = d;
    while(xp!=c){
        for(int j=0;j<n;j++){
            if(A[xp][j] > 0 && nhan[j] > A[xp][j] + nhan[xp] && danhdau[j]==0){
                nhan[j] = A[xp][j] + nhan[xp];
                truoc[j] =xp;
            }
        }
        minn = 99999999;
        for(int j=0;j<n;j++){
            if(minn > nhan[j] && danhdau[j] ==0){
                minn = nhan[j];
                xp = j;
            }

        }
        danhdau[xp] = 1;
    }
    ketqua[dem++] = c+1;
    ketqua[dem++] = truoc[c] + 1;
    int i = truoc[c];
    while(i!=d){
        i = truoc[i];
        ketqua[dem++] = i+1;
    }

}
int main(){

    freopen("test.txt","r",stdin);
    cin >> n >> m;
    cout << n << m;
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        cin >> A[a-1][b-1];
    }
    cin >> d >> c;
    d-- ;
    c-- ;
    minpath();
    for(int i=dem-2;i>=0;i--){
        w += A[ketqua[i+1]-1][ketqua[i]-1];
    }
    cout << w << endl;
    for(int i=dem-1;i>=0;i--){
        cout << ketqua[i] << " ";
    }

    return 0;
}
