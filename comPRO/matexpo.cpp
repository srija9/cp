#include <bits/stdc++.h>
using namespace std;

#define fast_io                       \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
#define ll long long int
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define mid(l, r) (l + (r - l) / 2)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)

void init_code()
{
	fast_io;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

const int modd = (int)1e9 + 7;

typedef vector<vector<int>> matrix;

matrix matrix_mul(matrix A, matrix B)
{
	int n = A.size();
	matrix ans(n, vector<int>(n));
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			for (int i = 0; i < n; ++i)
			{
				ans[r][c] += A[r][i] * B[i][c];
			}
		}
	}
	return ans;
}

matrix matrix_expo(matrix M, int n)
{
	int r = M.size(); // dimension of the matrix
	matrix ans(r, vector<int>(r));

	for (int i = 0; i < r; ++i)
	{
		ans[i][i] = 1;
	}

	while (n > 0)
	{ // O(log n)
		if (n % 2 == 1)
		{
			ans = matrix_mul(ans, M); // O(r^3)
		}
		n >>= 1;
		M = matrix_mul(M, M);
	}

	// over all: O(r^3 * log n)

	return ans;
}

int main()
{
	init_code();

	int k = 11;

	while (k--)
	{

		// fibonanci series:

		int n;
		matrix M(2, vector<int>(2));

		M[0][0] = M[0][1] = M[1][0] = 1;
		M[1][1] = 0;

		matrix b1(2, vector<int>(1));
		b1[0][0] = 1;
		b1[1][0] = 0;

		cin >> n;

		matrix M_pow_n_1 = matrix_expo(M, n - 1);

		matrix bn(2, vector<int>(1));
		for (int r = 0; r < 2; ++r)
		{
			for (int c = 0; c < 1; ++c)
			{
				for (int i = 0; i < 2; ++i)
				{
					bn[r][c] += M_pow_n_1[r][i] * b1[i][c];
				}
			}
		}

		// cout<< bn[0][0]<<endl;
		cout << M_pow_n_1[0][0] << endl;

		// general mat exponential

		// int r,n;
		// cin>>r>>n;
		// cout<<r<<"\n";
		// matrix M(r, vector<int> (r));
		// for(int i = 0; i < r; ++i){
		// 	for(int j = 0; j < r; ++j){
		// 		cin>> M[i][j];
		// 	}
		// }

		// matrix ans = matrix_expo(M, n);
		// for(int i=0;i<r;i++){
		// 	for(int j=0;j<r;j++){
		// 		cout<< ans[i][j] <<" ";
		// 	}
		// 	cout<<"\n";
		// }
	}

	return 0;
}