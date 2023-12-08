/* RA1000
Sobrecarga de Operadores (mas operadores)
- Fuentes: Actividad de clase, Programaci√≥n Avanzada UP,
           Notas de Asignatura PROGRAMACI√ìN AVANZADA en C/C++ - Dra. Claudia S√°nchez (Profesora UP Aguascalientes)
- Editado / modificado por: Eduardo Rodr√≠guez
- Editado por : Andres Ruiz - Braulio Lopez
- Fecha: 20/10/2023
Fuente: https://programacionenc.net/index.php?option=com_content&view=article&id=72:sobrecarga-de-operadores-en-c&catid=37:programacion-cc
*/

#include<bits/stdc++.h>

using namespace std;

class NumeroComplejo{
    float re, im;
    void copiar(const NumeroComplejo& otro){
        this->im = otro.im; 
        this->re = otro.re;
    }

public:
    NumeroComplejo(float real=0, float imaginario=0){
        this->re = real;
        this->im = imaginario;
        cout<<endl<<"Constructor...";
    }

    NumeroComplejo(const NumeroComplejo& original){
        cout<<endl<<"Constructor por copia...";
        copiar(original); // Llama a la funcion copiar() que basicamente hace lo mismo que haria el constructor copia.
    }

    void operator=(const NumeroComplejo& original){
        cout<<endl<<"Operador = ";
        if(&original == this) return;
        copiar(original);
    }

    NumeroComplejo operator+(const NumeroComplejo& n){
        cout<<endl<<"Operador + ";
        NumeroComplejo r(this->re + n.re, this->im + n.im);
    return r;
    }

    NumeroComplejo operator++(){ //prefijo ++n
        cout<<endl<<"Operador ++n";
        this->re++; 
        this->im++;
        return *this;
    }
    NumeroComplejo operator++(int){ //postfijo n++
        cout<<endl<<"Operador n++ ";
        NumeroComplejo r(*this);
        ++(*this);
        return r;
    }

    friend ostream& operator<<(ostream &cout,const NumeroComplejo& n);
    friend istream& operator>>(istream& cin, NumeroComplejo& n);

    void print(){
        if(im>=0) cout<<re<<"+ i"<<im;
        else cout<<re<<"- i"<<im;
    }
};

// Sobrecargando el cout
ostream& operator<<(ostream& cout, const NumeroComplejo& n){
    if(n.im>=0) cout<<n.re<<"+i"<<n.im;
    else cout<<n.re<<"-i"<<n.im;
    return cout;
}

// Sobrecargando el cin
istream& operator>>(istream& cin, NumeroComplejo& n){
    cin >> n.re >> n.im;
    return cin;
}

int main(){
    NumeroComplejo n1(4,6);
    NumeroComplejo n2(2,3);
    // NumeroComplejo r1 = ++n1;
    NumeroComplejo r1 = n1++;
    NumeroComplejo r2;
    n2++;
    r2 = n1 + n2;
    cout << endl << "Resultados ---------------"<<endl;
    cout << endl << "n1: "<<n1;
    cout << endl << "n2: "<<n2;
    cout << endl << "r1: "<<r1;
    cout << endl << "r2: "<<r2;
    cout << endl;
    cin >> n2;
    cout << "Nuevo valor de n2: " << n2;
}

	class string {
		int size;
		char *ptr;
	public:
		string (char []="");    //constructor predeterminado
		string (string &);     //constructor por copia
		~string();             //destructor
		string & operator= (string &);   //asignaci¢n
		bool operator== (string &);      //prueba si s1=s2
		bool operator!= (string &);      //prueba si s1!=s2
		bool operator! ();               //prueba si string esta vacia
		bool operator< (string &);       //prueba si s1<s2
		bool operator> (string &);       //prueba si s1>s2
		bool operator<= (string &);      //prueba si s1<=s2
		bool operator>= (string &);      //prueba si s1>=s2
		string & operator+= (string &);  //concatenaci¢n
		char operator[] (int);           //operador de sub°ndice
		string operator() (int, int);    //devuelve una subcadena
		int longitud (void);             //devuelve longitud de la cadena
		
		friend ostream & operator<< (ostream &, string &);
		friend istream & operator>> (istream &, string &);
		
	};
	
	string :: string (char * cadena){
		size=strlen(cadena);
		ptr=new char[size+1];
		if(ptr==NULL){ cout<<"No hay memoria"; exit(0); }
		strcpy(ptr, cadena);
	}
	
	string :: string (string & copia){
		size=strlen(copia.ptr);
		ptr=new char[size+1];
		if(ptr==NULL){ cout<<"No hay memoria"; exit(0); }
		strcpy(ptr, copia.ptr);
	}
	
	string :: ~string(){
		delete [] ptr;
	}
		
		string & string :: operator= (string & s){
			if(&s != this){          //evita la autoasignaci¢n
				delete [] ptr;        //evita fugas de memoria
				size=s.size;
				ptr=new char[size+1];
				strcpy(ptr, s.ptr);
			}
			else cout<<"Intento de asignar un objeto a si mismo";
			
			return (*this);          //habilita asignaciones en cascada
		}
		
		bool string :: operator== (string & s){
			if(!strcmp(ptr, s.ptr)) return (true);
			return (false);
		}
		
		bool string :: operator!= (string & s){
			if(!(*this==s)) return(true);    //usa sobrecarga de ==
			return(false);
		}
		
		bool string :: operator! (){
			if (size==0) return true;
			return false;
		}
		
		bool string :: operator< (string & s){
			if (strcmp(ptr, s.ptr)< 0) return true;
			return false;
		}
		
		bool string ::  operator> (string & s){
			if (s < *this) return true;
			return false;
		}
		
		bool string :: operator<= (string & s){
			if( !( s < *this) ) return true;
			return false;
		}
		
		bool string :: operator>= (string & s){
			if( !(s > *this) ) return true;
			return false;
		}
		
		string & string :: operator+= (string & s){
			char *temps=ptr;
			size+=s.size;
			ptr=new char[size+1];
			if(ptr==NULL){ cout<<"No hay memoria"; exit(0); }
			strcpy(ptr, temps);
			strcat(ptr, s.ptr);
			delete [] temps;
			return (*this);           //habilita llamadas en cascada
		}
		
		char string :: operator[] (int num){
			assert(num>=0 && num<size);   //prueba si num est  en el rango
			return (ptr[num]);
		}
		
		//Devuelve subcadena que comienza en: inicio y de longitud: subsize
		string string :: operator() (int inicio, int subsize){
			//asegura que inicio este en el rango y que subsize sea >=0
			assert(inicio>=0 && inicio<size && subsize >=0);
			
			string *subptr= new string;      //string vac°a
			if(subptr==0){ cout<<"No hay memoria"; exit(0); }
			
			//determina la longitud de la subcadena
			if((subsize==0) || (inicio+ subsize> size))
			   subptr->size= size- inicio+ 1;
			else
				subptr->size= subsize+1;
			
			//asigna memoria para la subcadena
			delete subptr->ptr;        //borra el arreglo de caract?res
			subptr->ptr= new char[subsize];
			if(subptr->ptr==NULL){ cout<<"No hay memoria"; exit(0); }
			
			//copia la subcadena a la nueva string
			strncpy(subptr->ptr, & ptr[inicio], subptr->size);
			subptr->ptr[subptr->size]='\0';    //termina string
			
			return (*subptr);   //devuelve la nueva string
		}
		
		int string :: longitud (void){
			return (size);
		}
		
		ostream & operator<< (ostream & salida, string & s){
			salida<< s.ptr;
			return (salida);    //habilita el proceso en cascada
		}
		
		istream & operator>> (istream & entrada, string & s){
			entrada>> s.ptr;
			return (entrada);   //habilita proceso en cascada
		}
		
		void main(void){
			textcolor(BLACK);
			textbackground(WHITE);
			clrscr();
			string s1("hola"), s2(" amigos"), s3;
			
			
			//probando operadores de igualdad y relacionales
			cout<<"s1: " <<s1 <<" , s2: " <<s2  <<" , s3: " <<s3;
			
			cout<<endl<<endl<<"Resultados al comparar s1 y s2: "
				<<endl<<"Resultado de s1==s2: " << (s1==s2 ? "verdadero" : "falso")
				<<endl<<"Resultado de s1!=s2: " << (s1!=s2 ? "verdadero" : "falso")
				<<endl<<"Resultado de s1> s2: " << (s1> s2 ? "verdadero" : "falso")
				<<endl<<"Resultado de s1< s2: " << (s1< s2 ? "verdadero" : "falso")
				<<endl<<"Resultado de s1>=s2: " << (s1>=s2 ? "verdadero" : "falso")
				<<endl<<"Resultado de s1<=s2: " << (s1<=s2 ? "verdadero" : "falso");
			
			//prueba operador sobrecargado (!)
			cout<<endl<<endl<<"Probando !s3: ";
			if(!s3){
				cout<<"s3 esta  vacio, asignando s1 a s3";
				s3=s1;
				cout<<"ns3: " << s3;
			}
			
			//probando operador sobrecargado de concatenacion
			cout<<endl<<endl<<"Resultado de s1+=s2: "<<endl;
			s1+=s2;
			cout<<"s1: " <<s1;
			//probando operador sobrecargado []
			cout<<", s1[8]= " <<s1[8];
			
			//prueba del operador sobrecargado ()
			cout<<endl<<endl<<"Cadena resultante de s1(5,6): " <<s1(5,6) ;
			
			//prueba el constructor de copiado
			string *s4= new string(s1);
			cout<<endl<<endl<<"Constructor copia para *s4: " <<*s4;
			
			//prueba del operador de asignacion =
			cout<<endl<<endl<<"Asignando s3 a *s4, *s4: ";
			*s4=s3;
			cout<< *s4
				<<endl<<"Longitud de *s4: " <<s4->longitud();
			
			getch();
		} 
