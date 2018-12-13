#include <iostream>

using namespace std;

void input_data(int a[], int n){
    for (int i=0; i<n; i++){
        cout << "Masukkan data ke-" << i << ": ";
        cin >> a[i];
    }
}

void cetak_data(const int a[], int n){
    for (int i=0; i<n; i++){
        cout << "Data ke-" << i << ": " << a[i] << endl;
    }
}

int nilaiMaksimum(apvector<int>&array)
{
    int n;
    int max = array[0];

    for(int i=1; i<n; i++)
    {
        if(array[i] > max)
            max = array(i)
    }
    return max;
}

int nilaiMinimum(apvector<int>&array)
{
    int n;
    int min = array[0];

    for(int i=1; i<jumlah; i++)
    {
        if(array[i] < min)
            min = array(i)
    }
    return min;
}

int main(){
    int n;
    int data[10];

    input_data(data, n);
    nilaiMaksimum();
    cout << max;
    nilaiMinimum();
    cout << min;
    return 0;
}
