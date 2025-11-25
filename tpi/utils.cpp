#include <iostream>
#include "utils.h"

using namespace std;



/// Utils
void dibujarBordeXGrueso(){
    char bordeX = 'Í';
    for (int i = 0; i <= 31; i++){
        cout << bordeX;
    }
    cout << "" << endl;
}

void dibujarBordeXFino(){
    char bordeX = '-';
    for (int i = 0; i <= 31; i++){
        cout << bordeX;
    }
    cout << "" << endl;
}
///
