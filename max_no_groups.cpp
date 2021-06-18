#include<iostream>
using namespace std;

const int Nmmax=100005;

int sumOf(int a[], int n){
	long long sum = 0;
	for(int i=1;i<=n;i++)
		sum += a[i];
	return sum;
}

bool isValid(int a[], int n, int k, int x){
	long long cnt = 0;
	for(int i=0;i<=n;i++)
		cnt+=min(x,a[i])

	return cnt > (1LL*x*k);
}

int bSearch(int a[], int n, int k){
	int Left=0; Right=sumOf(a,n)/k, ans;
	while(Left<=Right){
		int Mid = (Left+Right)/2;
		if(isValid(a,n,k,Mid)){
			ans=Mid;
			Left = Mid + 1;
		}
		else
			Right = Mid-1;

	}
	return ans;
}

int main(){
	int n, k,a[Nmax];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		a[i]=i;

	cout<<bSearch(a,n,k);	 
	return 0;
}