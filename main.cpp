#include <iostream>
#include <stdio.h>
#include <fstream>
#include "graf.h"

using namespace std;


int main()
{
   ifstream f ("COCO.txt");
   ofstream fout ("COCOOUT.txt");

  graf a,b;
  cin>>a;
  f>>b;
  cout<<a+b;



    return 0;
}



