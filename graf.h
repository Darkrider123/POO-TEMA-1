#ifndef GRAF_H_
#define GRAF_H_
#include <iostream>
#include <stdio.h>

using namespace std;


class graf
 {
    int a[50][50];
    int n;


 public:
     graf();
     ~graf(){};
    DeterminareDrumuri();
    ComponenteConexe();
    ETareConex();


    graf operator + (const graf &ob1);
   friend istream & operator >>(istream & in,graf &ob);
   friend ostream & operator <<(ostream & out, const graf &ob);

 };

 #endif // GRAF_H_
