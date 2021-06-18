//132 pattern problem
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

bool find123Pattern(vector<int>& nums){
	if(nums.empty()) return false;
	int n = nums.size();
	stack<int> st;
	minVal[0]=nums[0];
	for(int i=1;i<=n;i++)
		minVal[i]=min(minVal[i-1],nums[i]);

	for(int j=n-1;j>0;j--){
		//a[i]=minVal[j-1]
		while(!st.empty() && nums[st.top()]<nums[j]){
			if(nums[st.top()] >minVal[j-1])
				return true;
			st.pop();
		}
		return false;
	}
}

int main(){

	return 0;
}