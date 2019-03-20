#include <iostream>
#include <stdio.h>
#include "graf.h"
using namespace std;

graf graf::operator + (const graf &ob1)
 {
      int i,j;

    graf z;

    if (ob1.n!=n) return z;

    z.n=n;
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
    int i,j;
    for (i=0;i<=49;i++)
      for (j=0;j<=49;j++)
        a[i][j]=0;
        n=0;
 }



ostream & operator <<(ostream & out,const graf &ob)
{int i,j;
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

cout<<"Introdu numarul de noduri: ";
     in>>ob.n;
     cout<<"\n";


     cout<<"\n Introdu un graf sub forma de matrice de adiacenta de marime "<<ob.n<<"x"<<ob.n<<"\n\n";
     int i,j;

      for (i=0;i<50;i++)
                    for (j=0;j<50;j++)
                        ob.a[i][j]=0;

    for (i=1;i<=ob.n;i++)
        for (j=1;j<=ob.n;j++)
    {
    in>>x;
            if (x!=0&&x!=1)
                   {
                       cout<<"\n Graful nu are costuri, deci valorile introduse trebuie sa fie cuprinse intre 0 si 1\n\n";

                    for (i=0;i<50;i++)
                    for (j=0;j<50;j++)
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


int recursie (int a[50][50],int &n,int &cautat,int curent,int &c)
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

graf::DeterminareDrumuri()
{

   int b[50][50],i,j,c;

   for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      b[i][j]=a[i][j];

    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        { c=5000;
          if (recursie(a,n,j,i,c)==1)b[i][j]=1;
        }
     for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      a[i][j]=b[i][j];

      cout<<*this;
}


graf::ComponenteConexe()
{
       int i,j,c,v[60],vizitate[60]={0},ok,k;



    for (i=1;i<=n;i++)
    {
        for (c=0;c<60;c++)v[c]=0;

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

}

graf::ETareConex()
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
