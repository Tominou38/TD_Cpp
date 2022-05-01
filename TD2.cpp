#include <iostream> 
using namespace std;  

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
        };
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
            }
        };

        double& operator[] (const int i){
            if (i>(dim-1) || i<0){
                cout << "erreur d'indice\n";
                exit(2);
            }
            return(elements[i-1]);
        };

        vecteur & operator= (const vecteur & oper){
            if(dim != oper.dim){
                cout << "dimension incompatible \n";
                exit(1) ; 
            }
            for (int i=0;i<dim+1;i++) elements[i]=oper.elements[i];
            return(*this);

        };
        // +=
        vecteur & operator+= (const vecteur & operande){
            int i;
            if (dim != operande.dim){
                cout << "dimension incompatible\n";
                exit(0);
            }
            for (i=0;i<=dim+1;i++) elements[i]+=operande.elements[i];
            return (*this);
        };

};

vecteur operator + (const vecteur & operande1,const vecteur & operande2){
 vecteur temp_vect(operande1);
 temp_vect+=operande2;
 return(temp_vect);
}

int main(){
    cout<<"alo1 ??"<<endl;
    vecteur v3(3,1.0);
    vecteur v2(3); 
    vecteur v1(3);
    cout<<"alo ??"<<endl;
    v2=v3; 
    cout<<"elements de v2"<<endl;
    v2.elements_tan();
    cout<<"elements de v3"<<endl;
    v3.elements_tan();
    v1=v2+v3;
    v1.elements_tan(); 
    
    return 0;
};