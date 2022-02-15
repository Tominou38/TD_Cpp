
#include <iostream> 
using namespace std; 

class vecteur {
    private : 
        double * elements;

        int dim ; 

        public : 

 vecteur(int dim1, double elements1){

 dim=dim1;

 elements = new double[dim1]; // allocation du tableau d'elements

 for(int i=0; i<=dim1;i++ ){

 elements[i]=elements1; // initialisation elements avec entrée elements 

 };

 };

 vecteur(int dim1){

 dim=dim1;

 };

 vecteur(){};



};


//test
int main(){

 vecteur v1;

 vecteur v2(10,1.2);

 vecteur v3(10);

 vecteur v4(v3);

 return 0;

}