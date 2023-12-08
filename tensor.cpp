//Andres Ruiz Velasco--Braulio Lopez
//Tensor tres dimensiones
// 30 08 2023


#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(time(NULL));
  int ten[4][4][4];

  int x=sizeof (ten)/sizeof (ten [0]); 
  int y=sizeof (ten [0])/sizeof (ten [0][0]); 
  int z=sizeof (ten [0][0])/sizeof (ten [0][0][0]);

  for(int i=0; i<x; i++){
      for (int j=0; j<y; j++){
          for(int k=0; k<z; k++){
      ten[i][j][k] = rand()%100;
    cout << ten[i][j][k]<<"  ";
} 
        cout<< endl;
  }
    cout<< endl<< endl<< endl;
  }

  cout<<endl<<endl<<"X: "<<sizeof (ten)/sizeof (ten [0]); 
  cout<<endl<<"Y: "<<sizeof(ten [0])/sizeof (ten [0][0]); 
  cout<<endl<<"z: "<<sizeof(ten [0][0])/sizeof(ten [0][0][0]);

  
}
