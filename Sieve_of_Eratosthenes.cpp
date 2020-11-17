#include <bits/stdc++.h>

using namespace std;

const int Nmax=100001;
bool isPrime[Nmax];  //here the default value of the bool is false so we have to turn them all to true

void sieveOfEratosthenes(int n){
    for(int i=2; i<=n;i++)
        isPrime[i]=true; // here we are making the default value of the array to true9
    for(int i=2; i<=n/2;i++)
        if(isPrime[i]==true)
            for(int j=i*2;j<=n;j+=i)
                isPrime[j]=false;
}


int main()
{
    sieveOfEratosthenes(1);
    for(int i=2; i<100; i++)
        if(isPrime[i]==true)
            cout<< i <<" ";
    return 0;
}
