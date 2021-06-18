//longest palindromic substring
#include<iostream>
#include<vector>
using namespace std;

string longestPlaindrome(string s){
	int n=s.size(), maxLen=0, ansLeft, ansRight;
	if(n==0) return "";
	vector<vector<bool>> dp(n, vector<bool>(n,false));
	for(int i=n-1;i>=0;i--)
		for(int j=i;j<n;j++)
			if(i==j) dp[i][j]=true;
			else
				if(j==i+1)
					dp[i][j] = (s[i]==s[j]);
				else
					dp[i][j]= (s[i]==s[j] && dp[i-1][j+1]);

			if(dp[i][j] && j-i+1 > maxLen){
				maxLen = j-i+1;
				ansLeft=i;ansRight=j;
			}	
	return s.substr(ansLeft,maxLen);
}

int main(){

	return 0;
}