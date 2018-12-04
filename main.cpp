#include <iostream>
#include <cmath>

using namespace std;

double okr(double X, double eps)
{
	int i = 0;
	while (eps != 1)
	{
		i++;
		eps *= 10;
	}
	int okr = pow(double(10),i);
	X = int(X * okr + 0.5) / double(okr);

	return X;
}

void iterat(double A[10][10], double B[10], int N, double eps)
{


		int k = 0,i,j;
		double X[10], Y[10], g;
		for(i = 0; i < N; i++)
			X[i] = B[i];


			{
				for (i = 0; i < N; i++)
				{
					g = B[i];
					for (j = 0; j < N; j++)
                        k ++;
						g = g + A[i][j] * X[j];
					X[i] = g;
				}

			}

			cout << "Решение системы:" << endl << endl;
			for (i = 0; i < N; i++)
				cout << "X"<< i <<" = "<< okr(X[i],eps) <<"" << endl;
			cout << endl << endl;
			cout << "число итераций" << k << endl;


}

int main()
{
	double eps, A[10][10], B[10];
	int N, i, j;
	cout << "Введите размер квадратной матрицы: ";
	cin >> N;
	cout << "Введите точность вычислений: ";
	cin >> eps;
	cout << "Заполните матрицу А: " << endl << endl;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			cout << "A[" << i << "][" << j << "] = ";
			cin >> A[i][j];
		}
	cout << endl << endl;
		cout << "Ваша матрица А: " << endl << endl;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
				cout << A[i][j] << " ";
		cout << endl;
		}

		cout << endl;

		cout << "Заполните столбец свободных членов: " << endl << endl;
		for (i = 0; i < N; i++)
		{
			cout << "В[" << i+1 << "] = ";
			cin >> B [i];
		}

		iterat(A,B,N,eps);

		return 0;


}
