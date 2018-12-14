# Praktikum 8

## Latihan 1 : Nilai Maksimum dan Minimum dari Sebuah Array

**Alur algoritma**
1. Mendeklarasikan variabel `int nilai[3],a,min,maks;` sebagai variable input.
2. Membaca input dari keyboard `else if(nilai[a] > maks)`
3. Membandingkan nilai variable //output minimum dan maksimum

**Flowchart Program**

[!flowchart1](https://github.com/rumiumi/praktikum8/blob/master/Flowchart1.png)

**Code program** 
```
/*Program mancari nilai minimum dan maksimum*/
#include <iostream>
#include <conio.h>
using namespace std;
main()
{
   //deklarasi
    int nilai[3],a,min,maks;

   //input-output array
    for(a=1;a<=5;a++){
   cout<<"Masukkan nilai ke-"<<a<<":";
   cin>>nilai[a];
    }

   //proses looping array
   min = nilai[1];
   maks = nilai[1];
   for(a=1;a<=5;a++){
   if(nilai[a] < min){
   min = nilai[a];
   } else if(nilai[a] > maks){
   maks = nilai[a];
   }
   }

   //output minimum dan maksimum
   cout<<"nilai minimum adalah : "<<min<<endl;
   cout<<"nilai maksimum adalah : "<<maks<<endl;

getch();
return 0;
}
```

**hasilnya**

[!hasil1](https://github.com/rumiumi/praktikum8/blob/master/hasil1.png)


## Latihan2 : Modus dari Array

**Alur algoritma**
1. Mendeklarasikan variabel `class HitungStatistik` sebagai variable input.
2. Membaca input dari keyboard `for (int i=0; i<20; i++) f[i] = 0;`
3. Membandingkan nilai variable HitungStatistik run;

**Flowchart Program**
[!flowchart2](https://github.com/rumiumi/praktikum8/blob/master/Flowchart2.png)

**Code program** 
```
#include <iostream>
#include <math.h>

using namespace std;

class HitungStatistik {
friend ostream& operator<<(ostream&, HitungStatistik&);
friend istream& operator>>(istream&, HitungStatistik&);
public:
HitungStatistik();
void hitung_modus();
private:
void maksimum();
void frekuensi();
int maks, item;
int n;
int A[20];
int f[11];
};

HitungStatistik::HitungStatistik()
{ for (int i=0; i<20; i++) f[i] = 0; }

istream& operator>>(istream& in, HitungStatistik& a) {
cout << "Banyaknya data : ";
cin >> a.n;
for (int i = 0; i < a.n; i++) {
cout << "Data ke- : " << i+1 << " > ";
cin >> a.A[i];
}
return in;
}

void HitungStatistik::maksimum()
{
maks = f[0];
item = 1;
for (int i=0; i<n; i++)
if (f[i] > maks) {
maks = f[i];
item = i;
}
cout << "Modus = " << item;
}

void HitungStatistik::frekuensi()
{
for (int i=1; i<n; i++) ++f[A[i]];
}

void HitungStatistik::hitung_modus() {
cout << "Frekuensi running\n";
frekuensi();
maksimum();
}

ostream& operator<<(ostream& out, HitungStatistik& a) {
cout << "Mulai ...\n";
a.hitung_modus();
cout << "Nilai modus : " << a.item;
return out;
}

main() {
HitungStatistik run;
cin >> run;
cout << run;
return 0;
}
```

**Pict program**
[!hasil2](https://github.com/rumiumi/praktikum8/blob/master/hasil2.png)

## Latihan3 : Perkalian 2 Matriks

**Alur algoritma**
1. Mendeklarasikan fungsi `void input_data; void perkalian_matriks, void cetak_data`
2. Membaca input dari keyboard `cin >> baris1 >> kolom1; cin >> baris2 >> kolom2`
3. Jika `kolom1 != baris2` maka muncul pesan error serta input ulang
4. Panggil fungsi untuk menginput data dari kedua matriks
5. Panggil fungsi untuk mengkalikan kedua matriks
6. Tampilkan hasil perkalian

**Flowchart Program**
[!flowchart3](https://github.com/rumiumi/praktikum8/blob/master/Flowchart3.png)

**Code program** 
```
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
		cout << "Error! Kolom dari matriks pertama tidak sama dengan baris dari matriks kedua." << endl;
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

```

**Pict program**
[!hasil3](https://github.com/rumiumi/praktikum8/blob/master/hasil3.png)

## Latihan 4 : Transpose Matriks

**Alur algoritma**
1. Deklarasikan array dan variabel `int a[10][10], trans[10][10], r, c, i, j`
2. Membaca input dari keyboard `cin >> r >> c` lalu isi dari matriks
3. Membalikkan isi dari matriks
4. Tampilkan hasil transpose matriks

**Flowchart Program**
[!flowchart4](https://github.com/rumiumi/praktikum8/blob/master/Flowchart4.png)

**Code program** 
```
#include <iostream>
using namespace std;

int main(){
    int a[10][10], trans[10][10], r, c, i, j;

    cout << "Masukkan baris dan kolom dari matriks: ";
    cin >> r >> c;
    cout << endl;

    for(i=0; i<r; ++i)
    for(j=0; j<c; ++j)
    {
        cout << "Masukkan isi a" << i + 1 << j + 1 << ": ";
        cin >> a[i][j];
    }

    cout << endl << "Isi dari matriks:" << endl;
    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            cout << " " << a[i][j];
            if(j == c - 1)
                cout << endl << endl;
        }

    for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            trans[j][i]=a[i][j];
        }

    cout << endl << "Hasil transpose matriks" << endl;
    for(i=0; i<c; ++i)
        for (j=0; j<r; ++j)
        {
            cout << " " << trans[i][j];
            if(j == r - 1)
                cout << endl << endl;
        }

    return 0;
}
```

**Pict program**
[!hasil4](https://github.com/rumiumi/praktikum8/blob/master/hasil4.png)
