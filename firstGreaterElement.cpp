#include<iostream>
#include<stack>
using namespace std;

const int Nmax=100005;

void buildAns(int a[], int n, int ans[]){
	stack<int> s;
	for(int i=1;i<=n;i++){
		while(!s.empty() && a[s.top()] < a[i]){
			ans[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
}

int main(){
	int a[Nmax], ans[Nmax], n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	buildAns(a,n,ans);
	for(int i =1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}