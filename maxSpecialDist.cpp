#include<iostream>
#include<vector>
#include<bits/stdc++.h> //this is required for the sort function to work
using namespace std;

bool isValidDist(vector<pair<int,int>> points, int Dist){
	int n=points.size();
	int p=-1,minY,maxY;
	for(int j=0;j<=n;j++){
		while(p!= -1 && points[j].first - points[p+1].first >= Dist){
			p++;
			minY=min(minY,points[p].second);
			maxY=max(maxY,points[p].second);
		}
		if(p!=-1 && abs(minY-points[j].second) >=Dist)
			return true;
		if(p!=-1 && abs(maxY-points[j].second) >=Dist)
			return true;
	}
	return false;
}


int bSearch(vector<pair<int,int>>points){
	int Left=0, Right=1000000, ans;
	std::sort(points.begin(), points.end());
	while(Left<=Right){
		int Mid=(Left+Right)/2;
		if(isValidDist(points, Mid)){
			ans=Mid;
			Left=Mid+1;
		}
		else
			Right=Mid-1;
	}
	return ans;
}

int main(){
	vector<pair<int,int>> points;
	int n;
	cout<<"How many points do you wish to enter? "<<endl;
	cin>>n;
	cout<<"Enter the points in the following sequence > x1 y1 x2 y2"<<endl;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		points.push_back({a,b});
	}
	cout<<bSearch(points);
	return 0;
}