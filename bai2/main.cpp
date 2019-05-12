#include <iostream>
// tinh tong 
using namespace std;
void sum(int a[], int n){
    int maxsum = 0;
    int sum = 0;
    for(int i=0; i<n;i++){
        sum += a[i];
        if(sum<0) sum = 0;
        if(sum > maxsum) maxsum = sum;
    }
    cout << maxsum;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sum(a,n);
    return 0;

}
