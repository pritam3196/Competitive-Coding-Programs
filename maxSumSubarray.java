import java.util.Scanner;
class maxSumSubarray{
	static int maxSubarray(int a[], int n){
		int ans=a[0],sum=0;
		for(int i=0;i<n;i++){
			sum += a[i];
			if(sum>ans)
				ans = sum;
			if(sum<0)
				sum = 0;
		}
		return ans;
	}
	public static void main(String[] args){
		int n,ans;
		int Nmax = 10000;
		int[] arr = new int[Nmax];
		System.out.println("How many elements does your array have ?");
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();	
		System.out.println("Enter the array elements");
		for(int i=0;i < n; i++){
			arr[i] = sc.nextInt();
		}
		ans = maxSubarray(arr,n);
		System.out.println("The max value of subarrays is "+ans);

	}
}

// try to figure out the positions of the left and the right pointers in the array