// Andres Ruiz Velasco-- Braulio Lopez
//String nombres
// 01  09  23


#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre;
    
    cout << "Ingresa tu nombre completo: (usa mayusculas) ";
    getline(cin, nombre); 
    
    int longitud = nombre.length(); // Cuenta la longitud total del nombre
    
    int may = 0;
    for (int i = 0; i < longitud; i++) {
        if (isupper(nombre[i])) {
            may++; // Cuenta las mayÃºsculas en el nombre
        }
    }
    
    cout << "Longitud del nombre: " << longitud << " letras." << endl;
    cout << "Cantidad de mayusculas: " << may << " letras mayusculas." << endl;
    
    return 0;
}