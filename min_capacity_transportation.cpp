#include<iostream>
using namespace std;

const int Nmax = 100005;

int maxVal(int a[], int n){
	int maxVal = a[1];
	for(int i=2;i<=n;i++)
		maxVal=max(maxVal, a[1]);
	return maxVal;
}

int sumOf(int a[], int n){
	long long sum = 0;
	for(int i=1;i<=n;i++)
		sum += a[i];
	return sum;
}

int numOfRides(int a[], int n, long long C){
	int ans=1;
	long long sum = 0;
	for(int i =1;i<=n;i++)
		if(sum + a[i] <= C)
			sum +=a[i];
		else{
			ans++;
			sum = a[i];
		}
		return ans;
}

long long bSearch(int a[], int n , int k){
	long long Left = maxVal(a, n), Right = sumOf(a,n), ans;
	while(Left <= Right){
		long long Mid = (Left + Right)/2;
		if(numOfRides(a,n,Mid) > k)
			Left = Mid+1;
		else{
			ans=Mid;
			Right=Mid -1;
		}
	}
	return ans;
}

int main(){
	int n, k ,a[Nmax];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<bSearch(a,n,k);
	return 0;
}