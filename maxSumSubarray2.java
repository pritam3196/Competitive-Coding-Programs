import java.util.Scanner;
class maxSumSubarray2{

	static int Nmax = 1000;

	static int maxSumSubarray(int[] a, int n){
		if(n==0)
			return 0;

		int[] s = new int[Nmax];
		int ans = a[1];
		int minS = 0;

		for(int i=2;i<=n;i++)
			s[i] = s[i-1] + a[i];

		for(int i=1; i<=n;i++){
			if((s[i] - minS) > ans)
				ans = s[i] - minS;
			if(s[i] < minS)
				minS = s[i];
		}
		return ans;
	}

	public static void main(String[] args){
		int n;
		int[] a = new int[Nmax];
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of elements :");
		n = sc.nextInt();
		for(int i=1 ; i<=n;i++)
			a[i] = sc.nextInt();
		System.out.println(maxSumSubarray(a , n));

	}
}