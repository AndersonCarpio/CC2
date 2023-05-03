#include "Personaje.h"
#include "DynamicPersonajeArray.h"

using namespace std;

int main(){
    Personaje p1("Anderson","magico","humano",100,21);
    Personaje p2,p3; 
    p2.setNombre("Mario");
    Personaje p4("Samuel", "fisico" , "Alien", 200, 30);
    Personaje p5("Alan", "Legendario", "Demonio", 500, 40);
    Personaje arr[] ={p1,p2,p3};

    DynamicPersonajeArray dArr(arr,3);
    dArr.insert(p4,2);
    dArr.remove(1);
    dArr.remove(0);
    dArr.remove(0);
    dArr.remove(0);
    dArr.pushBack(p1);
    dArr.insert(p5,0);
    dArr.print();
    
    return 0;


}