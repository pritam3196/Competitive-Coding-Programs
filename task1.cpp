#include<iostream>
using namespace std;

const int Nmax=100005;
int n, a[Nmax], maxLeft[Nmax], maxRight[Nmax];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	for(int i=1;i<=n;i++)
		if(i==n || a[i] < a[i-1])
			maxLeft[i]=1;
		else
			maxLeft[i] = 1 + maxLeft[i-1];

	for(int i=n;i>=1;i--)
		if(i==n || a[i]>=a[i+1])
			maxRight[i]=1;
		else
			maxRight[i]=1+maxRight[i+1];

	int ans=0;
	for(int p=1;p<=n;p++){
		ans=max(ans, 1+maxLeft[p-1]);
		ans=max(ans, 1+maxRight[p+1]);
		if(a[p-1]-a[p+1]>=2)
			ans=max(ans, 1+maxLeft[p-1]+maxRight[p+1]);
	}

	cout<<ans;
	return 0;
	}
