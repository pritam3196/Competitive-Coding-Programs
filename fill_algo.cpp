#include<iostream>
using namespace std;

const int Nmax =1005;
char a[Nmax][Nmax];
bool vis[Nmax][Nmax];
// (row,col) --> up:(row-1,col); right:(row,col+1); down:(row+1,col); left:(row, col-1)
const int dx[] = {-1,0,1,0};
const int dy[] ={0,1,0,-1};

bool isValid(int row, int col, int n, int m){
	if(row<1 || row>n || col<1 || col>m)
		return false;
	if(a[row][col] == '#' || vis[row][col])
		return false;
	return true;
}

void fillAlgo(int row, int col, int n, int m, int& cellsCnt){ 
//here we are using the reference because we want to change the value of cellCnt
//we don't just want a copy of the value and do something on it.
	cellsCnt++;
	vis[row][col]= true;
//here we don't want to add four if statements so we define directional arrays globally	
	for(int dir=0;dir<4;dir++)
		if(isValid(row+dx[dir], col+dy[dir], n,m))
			fillAlgo(row+dx[dir], col+dy[dir], n,m, cellsCnt);
}

int main(){
	int islandsCnt = 0, maxCellsCnt = 0, n, m;
	cin>>n>>m;
	for(int i=1; i<=n;i++)
		for(int j=1; j<=m; j++)
			cin>>a[i][j];

	for(int i=1; i<=n; i++)
	 for(int j=1; j<=m; j++)
	 	if(isValid(i,j,n,m)){
	 		islandsCnt++;
	 		int cellsCnt = 0;
	 		fillAlgo(i,j,n,m, cellsCnt);
	 		maxCellsCnt = max(maxCellsCnt , cellsCnt);
	 	}	

	 cout<<islandsCnt<<" "<<maxCellsCnt<<endl;	
	return 0;
}