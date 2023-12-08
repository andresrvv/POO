//Andres Ruiz Velasco--Braulio Lopez 
//Ulam
// agosto 2023


#include <iostream>
using namespace std;
int main() {
  int numero;
  cout<< "Ingresa un numero positivo" << endl;//Se le pide un numero para empezar la sucesion 
  cin>>numero;
  if(numero>0){
  
    do{
    if(numero%2==0){
    numero=numero/2;
    }
    else{
    numero=numero*3+1;
        }
      cout << numero << "  ";
    }while(numero>1);
  } else{
    cout << "Opcion no disponible" << endl;
  }  
}
