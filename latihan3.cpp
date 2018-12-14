#include <iostream>
using namespace std;

void input_data(int matrix1[][10], int matrix2[][10], int baris1, int kolom1, int baris2, int kolom2);
void perkalian_matriks(int matrix1[][10], int matrix2[][10], int hasil_kali[][10], int baris1, int kolom1, int baris2, int kolom2);
void cetak_data(int kali[][10], int baris1, int kolom2);

int main()
{
	int matrix1[10][10], matrix2[10][10], kali[10][10], baris1, kolom1, baris2, kolom2, i, j, k;

	cout << "Masukkan baris dan kolom untuk matriks 1: ";
	cin >> baris1 >> kolom1;

	cout << "Masukkan baris dan kolom untuk matriks 2: ";
	cin >> baris2 >> kolom2;

	while (kolom1 != baris2)
	{
		cout << "Error! Kolom dari matriks pertama tidak sama dengan matriks kedua." << endl;
		cout << "Masukkan baris dan kolom untuk matriks 1: ";
		cin >> baris1 >> kolom1;
		cout << "Masukkan baris dan kolom untuk matriks 2: ";
		cin >> baris2 >> kolom2;
	}

        input_data(matrix1, matrix2, baris1, kolom1, baris2, kolom2);

        perkalian_matriks(matrix1, matrix2, kali, baris1, kolom1, baris2, kolom2);

        cetak_data(kali, baris1, kolom2);

	return 0;
}

void input_data(int matrix1[][10], int matrix2[][10], int baris1, int kolom1, int baris2, int kolom2)
{
	int i, j;
	cout << endl << "Masukkan isi dari matriks 1:" << endl;
	for(i = 0; i < baris1; ++i)
	{
		for(j = 0; j < kolom1; ++j)
		{
			cout << "Isi kolom a"<< i + 1 << j + 1 << ": ";
			cin >> matrix1[i][j];
		}
	}

	cout << endl << "Masukkan isi dari matriks 2:" << endl;
	for(i = 0; i < baris2; ++i)
	{
		for(j = 0; j < kolom2; ++j)
		{
			cout << "Isi kolom b" << i + 1 << j + 1 << ": ";
			cin >> matrix2[i][j];
		}
	}
}

void perkalian_matriks(int matrix1[][10], int matrix2[][10], int kali[][10], int baris1, int kolom1, int baris2, int kolom2)
{
	int i, j, k;

	for(i = 0; i < baris1; ++i)
	{
		for(j = 0; j < kolom2; ++j)
		{
			kali[i][j] = 0;
		}
	}

	for(i = 0; i < baris1; ++i)
	{
		for(j = 0; j < kolom2; ++j)
		{
			for(k=0; k<kolom1; ++k)
			{
				kali[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
}

void cetak_data(int kali[][10], int baris1, int kolom2)
{
	int i, j;

	cout << "Output Matriks:" << endl;
	for(i = 0; i < baris1; ++i)
	{
		for(j = 0; j < kolom2; ++j)
		{
			cout << kali[i][j] << " ";
			if(j == kolom2 - 1)
				cout << endl << endl;
		}
	}
}
