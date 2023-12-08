// Andres Ruiz Velasco - Braulio Lopez 
// Operadores
// https://www.zator.com/Cpp/E4_9_19.htm
// http://profesores.fi-b.unam.mx/carlos/lcpi/p09/OPERADORES%20EN%20%20C++.pdf

#include <iostream>
using namespace std;


namespace progra{

   int calificacion=35;  
};

int x=17; //variable global
int main() {
int x=3; // variable local
  int arreglo[10];// declarar el arreglo con su tamaño

  int a,b,c,d; // operador coma
  int a1;
  int b1;
  
  cout << "Esta es la variable local: " <<x<< endl;
     cout << "Esta es la variable Global: "<< ::x<< endl; // resolucion de ambito global

  
   progra::calificacion =10; //resolucion de ambito de clase


  cout<<" se imprime calificación "<< progra::calificacion<< endl;

  arreglo[1]=15;
  
  cout<<" se imprime la posicion 2 del arreglo: "<< arreglo[1]<< endl;

  
}