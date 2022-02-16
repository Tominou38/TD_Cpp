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
            elements = new double[dim1];
        };
        vecteur(){
            dim=0;
            elements = NULL; 
        };
        ~vecteur(){
            delete [] elements; 
        }
        void dimension(){cout<<"la dimension est : " << dim<<endl;};
        void elements_tan(){
            for(int i=0; i<=dim;i++ ){
                cout<<elements[i]<<endl;
            };
        }
        void get_dim(){

            cout<<"entrez une dimension : ";
            cin>>dim;
            delete [] elements; 
            elements = new double[dim];
        };
        void get_element(){
            
            for(int i=0; i<dim;i++ ){
                cout<<"valeur de la case "<< i+1 << " : " << endl; 
                cin>>elements[i]; // initialisation elements avec entrée elements 
            };
        };

};

int main(){
    /*vecteur v1;
    vecteur v2(10,1.2);
    vecteur v3(10);
    vecteur v4(v3);
    //v1.dimension();
    v2.dimension();
    v2.elements_tan(); */
    vecteur v3;
    //v3.dimension();
    v3.get_dim();
    v3.dimension();;
    v3.get_element();


    return 0;
}