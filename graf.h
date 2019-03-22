#ifndef GRAF_H_
#define GRAF_H_
#include <iostream>
#include <stdio.h>

using namespace std;


class graf
 {
    int **a;
    int n;


 public:
     graf();
     graf(int c);
     ~graf();
     graf(const graf &ob);
   void DeterminareDrumuri();
   void ComponenteConexe();
   void ETareConex();

    graf operator = (const graf &ob);
    graf operator + (const graf &ob1);
   friend istream & operator >>(istream & in,graf &ob);
   friend ostream & operator <<(ostream & out, const graf &ob);

 };

 #endif // GRAF_H_

