
4*n^3 + n + 1 => n^3

f(n) => total time complexity of algorithm 
g(n) => hightest time taken by the algorithm. 

n=100, 

4*n ==> n 


int main(){
	
	int n;
	int a = 0;  -> 1
	cin>>n;     -> 1  

	for(int i=0;i<n;i++)  -> 3*n
	{
	   //if(i==n+1) break;

	}
}

== 3*n + 2 = f(n)  

g(n) =  n;

o - f(n) <= cg(n)  =>  3n+2 <= cn  c=4 and n>2 

omega - f(n) >= cg(n)  =>  3n+2 >= cn  c=1 and n>1

theta - c1*g(n) <= f(n) <= c2*g(n) => c1=1, c2= 4 n>=2


algorithm :

loops(iterative) or recursion  => O(in terms of n) => n / n^2 / n^3 / logn / 2^n / nlogn / n! / squt(n) ... 

o(1)

loops: 

for(int i=0;i<n;i++)  n      i=0 => j=0 to n ;i=n  n+n = n^2
{
	for(int j=0;j<n;j++) n     n(1+2+3+...+ n-1)
}

i=0 -> n
i=1 -> n
i=2 -> n 
.
.
i=n-1 -> n n+n+....ntimes = n*n => n^2


for(int i=0; i<n;i++)
{
	for(int j=i;j<n;j++)
}

i=0 -> ntimes
i=1 -> n-1
i=2 -> n-2
.
.
i=n-1 -> n-(n-1) = 1   => n + n-1 + n-2 + ....1 = n(n+1)/2 = O(n^2)

for(int i=1;i<=n;i++)
{
	for(int j=i;j<=n;j*=2)     
}

i=1 ->  (1,2,4,8 ... 2^k <= n k=log(n)
i = 2-> (2,4,8,......logn logn
i=3-> (3,6,12,...)   < logn



recursion:

int fact(n)
{
	if(n==1)     -1
	   return 1;  -1

	return n*fact(n-1);  -> 1+1 = O(1)   O(3)=O(1)
	   
}

fact(5) => 5*fact(4)
fact(4) => 4*fact(3)
fact(3) => 3*fact(2)
fact(2) => 2*fact(1)
fact(1) => 1

n=5 => O(5) 


int fib(n)
{
	if(n==0 || n==1)   1+1+1 = 3
	{
	  return n;        1
	}

	return fib(n-1)+f(n-2);         1+1 = O(3+1+2) =O(1)
}

n=5;


                                    fib(5)                                     1  =2^0
                               /             \
                       fib(4)                   fib(3)                         2  =2^1
                     /       \                  /     \
               fib(3)         fib(2)          fib(2)    fib(1)                 4  =2^2
              /   \          /   \           /    \      /  \
          fib(2)   fib(1) fib(1) fib(0)  fib(1) fib(0)                         .  = 2^3
           /    \    /\    /\      /\      /\     /\    
        fib(1) fib(0)                                                          .  = 2^4 


        = 2^5 -1  => 2^n


                           
      1 sec --> 10^8

      1 <= N <= 10^5

      O(nlogn)