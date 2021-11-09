#include<stdio.h>
int GCD(int num1, int num2);
int extended_Euclid(int num1, int num2, int gcd);
int is_prime(int n);
int mod_Exp(int a, int b, int n);

void main()
{
	int p, q;
	int n,N;
	int M, C;

	
	while (1)
	{
		printf("Enter first prime number : ");
		scanf("%d", &p);
		printf("Enter second prime number : ");
		scanf("%d", &q);

		if (is_prime(p) == 0 || is_prime(q) == 0)
		{
			printf("Enter agin !");
			continue;
		}
		else
		{
			break;
		}
	}
	printf("Enter encrypt message : ");
	scanf("%d", &M);

	n = p * q;
	N = (p - 1) * (q - 1);

	int e = 5;
	int d;

	int dd;
	int i = 1;
	while (1)//find private key d
	{
		dd = (i * N) + 1;
		if (dd % e == 0)
		{
			d = dd / e;
			break;
		}

		i++;
	}
	//calculate Ciphertext 
	C = mod_Exp(M, e, n);
	int D = mod_Exp(C, d, n);

	//output
	printf("\n Public Key = (%d , %d)\n Secret key = (%d ,%d)\n Ciphertext = %d\n Decrypt Ciphertext = %d\n", e, n, d, n, C, D);


}
int mod_Exp(int a, int b, int n)//calculate (a^b)mod n
{
	int c = 0, d = 1;
	int bit[100000];  //store binary number
	int count = 0;

	while (b > 0)	//calculate b's binary number
	{
		bit[count++] = b % 2;
		b = b / 2;
	}

	
	for (int i = count - 1; i >= 0; i--)
	{
		c = 2 * c;
		d = (d * d) % n;
		if (bit[i] == 1)
		{
			c = c + 1;
			d = (d * a) % n;
		}
	}

	return d;
}
int is_prime(int n)//check prime number
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 0;
		else return 1;
	}
}
int GCD(int num1, int num2)//calculate GCD
{
	if (num2 == 0)
	{
		return num1;
	}
	else {
		return GCD(num2, num1 % num2);
	}

}


int extended_Euclid(int num1, int num2, int gcd)
{
	int LCM = 0;
	int numB1 = 0;
	int numB2 = 0;
	int min = 0;
	int num = 0;
	LCM = (num1 * num2) / gcd;
	for (int i = 1; num1 * i <= LCM; i++)
	{
		for (int j = 1; num2 * j <= LCM; j++)
		{
			if (abs(num1 * i - num2 * j) == gcd)
			{
				if (num == 0)
				{
					min = i + j;
					if ((num1 * i - num2 * j) > 0)
					{
						numB1 = i;
						numB2 = -j;
					}
					else
					{
						numB1 = -i;
						numB2 = j;
					}
					num++;


				}

				if (num != 0 && min > i + j)
				{
					if ((num1 * i - num2 * j) > 0)
					{
						numB1 = i;
						numB2 = -j;
					}
					else
					{
						numB1 = -i;
						numB2 = j;
					}
				}

			}
		}
	}
	printf("%d %d %d", numB1, numB2, gcd);
}
