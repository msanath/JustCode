/* Given a set of integers W1, W2... Wi, is there a subset of integers which add up to 
 the sum? */

 #include <iostream>
using namespace std;

/* Recursive */
int SubsetSum(int *a, int n, int Sum)
{
	if (Sum > 0 && n == 0)
		return 0;

	if (Sum == 0)
		return 1;

	return SubsetSum(a, n - 1, Sum) || SubsetSum(a, n - 1, Sum - a[n - 1]);
}


/* DP */

int SubsetSumDP(int *a, int n, int sum)
{
	int opt[n][sum];
	for (int i=0; i<n; i++)
	{
		opt[i][0] = 1;
	}

	for (int i=0; i<sum; i++)
	{
		opt[0][sum] = 0;
	}

	for (int i=1; i <= sum; i++)
	{
		for (int j=1; j<=n; j++)
		{
			opt[i][j] = min(opt[i + 1][j], opt[i + 1][j - a[j]]);
		}
	}
}
