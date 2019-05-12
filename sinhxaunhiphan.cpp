#include<bits/stdc++.h>
using namespace std;
void inCauHinh(int a[],int n,int &coun,int k,int j){
	int dem=0;
	int mx = 0;
	for(int i=0;i<n;i++)
	{
			if(a[i] == 0)
			{
				dem++;
				if(dem>mx)
				mx = dem;
			}
			if(a[i]== 1)
			dem = 0;
	}
	if(mx<j){
		coun++;
	}
	if(coun == k){
		for(int i=0;i<n;i++){
			cout << a[i]<<" ";
		}
	}

}
void datKhong(int vt,int a[],int n){
	for(int i=vt+1;i<n;i++){
		a[i]=0;
	}
}
void sinhXau(int a[],int n,int k,int j){
	int coun = 0;
	inCauHinh(a,n,coun,k,j);
	int i=n-1;
	while(i>0){
		if(a[i]==1){
			i--;
		}
		if(a[i]==0){
			a[i]=1;
			datKhong(i,a,n);
			inCauHinh(a,n,coun,k,j);
			i=n-1;
		}
	}
	if(coun < k)
	cout << -1;
}
int main(){
	int n,k,j;
	cin >> n >> k >> j;
	int a[n];
	for(int i=0;i<n;i++){
		a[i]=0;
	}
	sinhXau(a,n,k,j);
	return 0;
}
