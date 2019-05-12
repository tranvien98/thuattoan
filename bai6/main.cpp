#include<bits/stdc++.h>
// binh nuoc
using namespace std;
int ucnn(int a,int b){
if(b==0) return a;
    return ucnn(b,a%b);
   }
int pour(int fromCap, int toCap, int d)
{
    int from = fromCap;
    int to = 0;
    int step = 1;
    while(from!=d && to != d){
        int temp = min(from,toCap - to);

        from -= temp;
        to += temp;
        step ++;
        if(from == d || to == d )
            break;
        if(from == 0 )
        {
            from = fromCap;
            step++;
        }
        if(to == toCap){
            to = 0;
            step++;
        }
    }
    return step;
}
int minStep(int m,int n,int d){
    if(m>n) swap(m,n);
        if(d>n) return -1;
        if(d%ucnn(m,n)!=0) return -1;
        return min(pour(m,n,d),pour(n,m,d));

}
int main()
{
    int T;
    cin >> T;
    int a[T][3];
    for(int i=0;i<T;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for(int i=0;i<T;i++){
        cout << minStep(a[i][0],a[i][1],a[i][2]) << endl;
    }
}
