#include <iostream>

#define n 4
#define m 5

int maxRect(int a[n][m])
{
	int i, j;
	int p, q;
	int col = 0;
	int temp, temp1;

	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
		{
			if (a[i][j] != 0)
			{
				temp = 0;

				for (q = j; q < m && a[i][q] != 0; ++q)
				{
					temp1 = 0;

					for (p = i; p < n && a[p][q] != 0; ++p)
						temp1++;
					if (!temp)
						temp = temp1;
					else
					{
						if (temp > temp1)
							temp = temp1;
					}
					if (col < temp * (q - j + 1))
						col = temp * (q - j + 1);
				}
			}

		}
	return col;
}

int main()
{
	int a[n][m] = { {1, 0, 1, 0, 0},
				    {1, 0, 1, 1, 1},
				    {1, 1, 1, 1, 1},
				    {1, 0, 0, 1, 0}, };

	std::cout << maxRect(a);
}