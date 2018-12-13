#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

void main(){
    int a[20], f[20], frek, jml, fm, m;

    start:
    clrscr();
    cout<<"Masukkan jumlah data : ";cin>>jml;
    randomize();
    cout<<"\nAcak : ";
    for(int i=0;i<jml;i++)
    {
        a[i]=random(10);
        cout<<a[i]<<" ";
    }

    cout<<endl<<"Diurutkan : ";

    //proses pengurutan data ascending(jika perlu)
    for (int i=0;i<(jml-1);i++)
        for (int j=(i+1);j<jml;j++)
            if (a[i]>a[j])
            {
            int tmp;
            tmp = a[i];
            a[i]=a[j];
            a[j]=tmp;
            }

        for (int i=0;i<(jml);i++)
            {
            cout<<a[i]<<" ";
            }

    cout<<endl;

    //menentukan frekuensi kemunculan
    for(int i=0;i<jml;i++)
    {
    frek=0;
    for(int j=0;j<jml;j++)
        if(a[j]==a[i])
            {
            frek++;
            f[i]=frek;
            }
    } cout<<endl;

    //mencegah cout data sama dengan frekuensi sama
    for(int i=0;i<jml;i++)
        {
        if(i>0)
            {for(int j=0;j<i;j++)
            if(a[i]==a[j]&&f[i]==f[j])goto stop;
            }
        cout<<"Frekuensi "<<a[i]<<" = "<<f[i]<<" kali"<<endl;
        stop:
    }cout<<endl;


    //menentukan modus
    fm=0;
    for(int i=0;i<jml;i++){
        if(f[i]>fm){
            fm=f[i];
            m=a[i];
        }
    }

    //bila tak ada modus
    int x=1;
    for(int i=1;i<jml;i++)
    {
        if(f[0]==f[i])x++;
    }
    if(jml<3||x==jml)cout<<"TIDAK ADA MODUS";

    //modus lebih dari 1
    else
    {
    cout<<"MODUS = "<<m;
    for(int i=0;i<jml;i++)
        {
        if(a[i-1]==a[i])goto ex;
        if(a[i]!=m && f[i]==fm)cout<<", "<<a[i];
        ex:
        }
    }

    char ans;
    cout<<"\n\nCoba Lagi [y/n]?";cin>>ans;
    if(ans=='y')goto start;
    else if(ans=='n')goto end;

    getch();
    end:
}
