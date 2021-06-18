import java.util.Scanner;
class SlidingWindowTechnique{

	static int Nmax = 100000;
	static int[] fr = new int[Nmax];

	static int slidingWindow(int[] a, int n, int k){
		int ans = 0, cnt = 0, Right;
		for(Right=1 ; Right<=n; Right++){
			if(++fr[a[Right]] == 1)
				cnt++;
			if(cnt >k)
				break;
		}
		if(cnt<=k)
			return n;
		/// 1 2 3 4 5 , for left=1 and k=2, right=3, maxR[1] = right -1 =2
		if(--fr[a[Right--]] == 0)
			cnt--;
		for(int Left=2 ; Left <=n; Left++){
			if(--fr[a[Left - 1]] == 0)
				cnt--;
			while(Right < n){
				if(++fr[a[++Right]] == 1)
					cnt++;
				if(cnt > k)
					break;
			}
			if(cnt <= k)
				return Math.max(ans , n-Left+1);
			if(--fr[a[Right--]] == 0)
				cnt--;
			ans = Math.max(ans, Right-Left+1);
		}
		return ans;
		
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int[] a = new int[Nmax];
		int n, k;
		System.out.println("Enter the number of elements : ");
		n = sc.nextInt();
		System.out.println("Enter the number of distinct elements :");
		k = sc.nextInt();
		System.out.println("Enter the array elements :");
		for(int i=1 ; i<=n; i++)
			a[i] = sc.nextInt();
		System.out.println(slidingWindow(a , n ,k));
	}
}