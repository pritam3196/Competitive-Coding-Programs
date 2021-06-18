import java.util.Scanner;
class LongestConsecNumbersSubarray{
	static int Nmax = 1000;
	static int[] a = new int[Nmax];
	static int n;
	static boolean[] fr = new boolean[Nmax];

	static int longestConsecNumsSubarray(){
		int ans = 0;
		for(int Left = 1 ; Left <= n ; Left++){
			for(int i = 1; i<=n;i++)
				fr[i] = false;
			int Min = a[Left] , Max = a[Left];
			for(int Right = Left ; Right <= n ; Right++){
				if(fr[a[Right]] == true)
					break;
				fr[a[Right]] = true;
				Min = Math.min(Min, a[Right]);
				Max = Math.max(Max, a[Right]);
				if(Right - Left == Max - Min)
					ans = Math.max(ans, Right-Left+1);
			} 
		}
		return ans;
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		for(int i =1; i<=n;i++){
			a[i] = sc.nextInt();
		}
		System.out.println(longestConsecNumsSubarray());
	}
}