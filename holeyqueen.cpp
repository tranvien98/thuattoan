#include<bits/stdc++.h>

using namespace std;
// danh dau vi tri
int x[1000];
int dt[1000];
int td[1000];
int a[1000];
int n,m;
int dem = 0;
int holey[1000][1000];
void init(){
    for(int i=0;i<=n;i++){
        a[i] = 1;
    }
    for(int i=0;i<=n;i++){
        x[i] = 0;
    }
    for(int i=2;i<=2*n;i++)
        {
            dt[i] = 1;
        }
    for(int i=1-n;i<=n-1;i++)
        {
            td[i] = 1;
        }
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++){
        holey[i][j] = 0;
    }
}

void Try(int i){

    for(int j=1;j<=n;j++){
            if(holey[i][j] == 1){
                continue;
            }
            if(a[j]&&dt[i+j]&&td[i-j]){
                x[i] = j;
                if(i!=n){
                    a[j] = 0;
                    dt[i+j] = 0;
                    td[i-j] = 0;
                    Try(i+1);
                    a[j] = 1;
                    dt[i+j] = 1;
                    td[i-j] = 1;
                     }
                else {

                        dem ++;


                }

            }

    }
}
int main(){

    init();
    do {
        cin >> n >> m;
        init();
        dem = 0;
        for(int i=0;i<m;i++){
            int x,y;
            cin >> x >> y;
            holey[x][y] = 1;
        }
        Try(1);
        if (n != 0 || m != 0)
            cout << dem << endl;;


    }while(n!=0||m!=0);

}
