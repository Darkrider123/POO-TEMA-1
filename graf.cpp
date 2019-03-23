#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "graf.h"
using namespace std;

graf graf::operator =(const graf &ob)
{ if (this==&ob) return *this;
     int i,j;
    if (n<=0&&ob.n>0)
    {

    n=ob.n;
     a=new int* [n+1];
     for (i=0;i<n+1;i++)
        a[i]=new int [n+1];

        for (i=0;i<n+1;i++)
            for (j=0;j<n+1;j++)
             a[i][j]=ob.a[i][j];
             return *this;
    }
    if (ob.n<=0)
    {
         for (i=0;i<n+1;i++)
    delete[] a[i];
     delete[] a;
        n=0;
        return *this;
    }


    for (i=0;i<n+1;i++)
    delete[] a[i];
     delete[] a;

      n=ob.n;
     a=new int* [n+1];
     for (i=0;i<n+1;i++)
        a[i]=new int [n+1];

        for (i=0;i<n+1;i++)
            for (j=0;j<n+1;j++)
             a[i][j]=ob.a[i][j];
             return *this;
}

graf graf::operator + (const graf &ob1)
 {
      int i,j;



    graf z(ob1.n);
    if (ob1.n!=n) return z;
    if (ob1.n<=0) return z;

     for (i=1;i<=z.n;i++)
        for (j=1;j<=z.n;j++)
        {
            if (ob1.a[i][j]==1||a[i][j]==1)
            z.a[i][j]=1;
        }


          return z;
 }

graf::graf ()
 {
        n=0;
        a=NULL;
 }

graf::graf(const graf &ob)
{  if (ob.n==0)
{
    n=0;
}
else{


    int i,j;
    n=ob.n;
     a=new int* [n+1];
     for (i=0;i<n+1;i++)
        a[i]=new int [n+1];

        for (i=0;i<n+1;i++)
            for (j=0;j<n+1;j++)
             a[i][j]=ob.a[i][j];
}
}

graf::graf(int c)
{int i,j;
if (c<=0)
{
    n=0;

}
else {
    n=c;
     a=new int* [n+1];
     for (i=0;i<n+1;i++)
        a[i]=new int [n+1];

        for (i=0;i<n+1;i++)
            for (j=0;j<n+1;j++)
             a[i][j]=0;
}
}

 graf::~graf()
 {
    int i;
    if (n<=0) return;
    for (i=0;i<n+1;i++)
    delete[] a[i];
     delete[] a;
     n=0;
 }



ostream & operator <<(ostream & out,const graf &ob)
{int i,j;
if (ob.n<=0) return out;
    for (i=1;i<=ob.n;i++)
    {
        for (j=1;j<=ob.n;j++)
        out<<ob.a[i][j]<<" ";
    out<<"\n";
    }
     return out;
}

istream & operator >>(istream &in, graf &ob)
{int x;
int i,j;

if (ob.n>0)
    ob.~graf();

cout<<"Introdu numarul de noduri: ";
     in>>ob.n;
     cout<<"\n";
     if (ob.n<=0) return in;

     ob.a=new int* [ob.n+1];
     for (i=0;i<ob.n+1;i++)
        ob.a[i]=new int [ob.n+1];

     cout<<"\n Introdu un graf sub forma de matrice de adiacenta de marime "<<ob.n<<"x"<<ob.n<<"\n\n";


      for (i=0;i<ob.n+1;i++)
                    for (j=0;j<ob.n+1;j++)
                        ob.a[i][j]=0;

    for (i=1;i<=ob.n;i++)
        for (j=1;j<=ob.n;j++)
    {
    in>>x;
            if (x!=0&&x!=1)
                   {
                       cout<<"\n Graful nu are costuri, deci valorile introduse trebuie sa fie cuprinse intre 0 si 1\n\n";

                    for (i=0;i<ob.n+1;i++)
                    for (j=0;j<ob.n+1;j++)
                        ob.a[i][j]=0;
                        i=1;
                        j=1;
                        return in;
                    }
    else
    ob.a[i][j]=x;
    }
   cout<<"\n";
    return in;
}


int recursie (int **a,int &n,int &cautat,int curent,int &c)
{int i;
     if (c==0) return 0;
     c--;
        if (a[curent][cautat]==1) return 1;
          else
            for (i=1;i<=n;i++)
                if (a[curent][i]==1)
               if(recursie(a,n,cautat,i,c)==1) return 1;

          return 0;

}

void graf::DeterminareDrumuri()
{

   int i,j,c;
   graf b(n);

   for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      b.a[i][j]=a[i][j];

    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        { c=5000;
          if (recursie(a,n,j,i,c)==1)b.a[i][j]=1;
        }
     for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      a[i][j]=b.a[i][j];

      cout<<*this;
}


void graf::ComponenteConexe()
{
       int i,j,c,*v,*vizitate,ok;
       v= new int [n+2];
       vizitate= new int [n+2];
        for (c=0;c<n+2;c++)vizitate[c]=0;

    for (i=1;i<=n;i++)
    {
        for (c=0;c<n+2;c++)v[c]=0;

        for (j=1;j<=n;j++)
        { c=5000;
          if (recursie(a,n,j,i,c)==1)

            {
                c=5000;
                if (recursie(a,n,i,j,c)==1)
                    v[j]=1;
            }
        }
        v[i]=1;


        ok=0;
        for (c=1;c<=n;c++)
            if (vizitate[c]==1||v[c]==0);

                else
                {
                    cout<<"(";

                    for (c=1;c<=n;c++)
                      if (v[c]==1&&vizitate[c]==0)cout<<c<<" ";

                    cout<<")";
                         ok=1;

                        for (c=1;c<=n;c++)
                            if (v[c]==1) vizitate[c]=1;
                        break;
                }
                if (ok==0&&vizitate[c]!=0) cout<<"("<<i<<")";


    }
delete[] v;
delete[] vizitate;
}

void graf::ETareConex()
{

int i,j,c,ok=1;


    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        { c=5000;
          if (recursie(a,n,j,i,c)==1);
            else ok=0;
          }

        if (ok==0) cout<<"Nu e tare conex";
          else cout<<"E tare conex";
}

/* Incercare cu vectori de vizitati
int recursie (int a[50][50],int n,int cautat,int curent,int c[])
{int i;
     if (c[curent]!=0) return 0;
     c[curent]++;
        if (a[curent][cautat]==1) return 1;
          else
            for (i=1;i<=n;i++)
                if (a[curent][i]==1)
               if(recursie(a,n,cautat,i,c)==1) return 1;
          return 0;
}
graf::DeterminareDrumuri()
{
   int b[50][50],i,j,c[60]={0};
   for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      b[i][j]=a[i][j];
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
          if (recursie(a,n,j,i,c)==1)b[i][j]=1;
     for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      a[i][j]=b[i][j];
      cout<<*this;
}
*/
