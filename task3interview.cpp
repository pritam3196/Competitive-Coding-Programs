#include<iostream>
#include<vector>
using namespace std;

int maxCoins(vector<int>& nums){
	int n = nums.size();
	if(n==0) return 0;
	vector<int>blns(i,1);
	for(num:nums)
		blns.push_back(num);
	blns.push_back(1);
	vector<vector<int>> dp(n+1, vector<int>(n+1,0));
	for(int Left=n; Left>=1;Left--)
		for(int Right=Left;Right<=n;Right++)
			if(Left==Right)
				dp[Left][Right]=blns[Left-1]*blns[Left]*blns[Left+1];
			else{
				//p=Left
				dp[Left][Right]=dp[Left+1][Right] + blns[Left-1]*blns[Left]*blns[Right+1];
				//p=Right
				dp[Left][Right]=max(dp[Left][Right], dp[Left][Right-1]+blns[Left-1]*blns[Right]*blns[Right+1]);
				//Left<<p<<Right
				dp[Left][Right]=max(dp[Left][Right], dp[Left][p-1]+dp[p+1][Right]+blns[p]*blns[Left-1]*blns[Right+1]);
			}
			return dp[1][n];
}

int main(){

	return 0;
}