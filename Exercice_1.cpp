#include <iostream>

using namespace std ;

class Figure {
    protected : 
        static int compteur;

    public :
        virtual int perimetre()=0;
        virtual void afficherCaracteristiques()=0;  
        
        
        Figure() {compteur++;} 
        

        static int getCompteur(){
            return compteur ;
        }    
        
};

class Polygone : public Figure { 
    protected :
        int nbCote;   
    public : 
        Polygone(int n):Figure(){
            nbCote=n; 
        };
        Polygone():Figure(){
            nbCote=4;
        };
        void afficherCaracteristiques(){
            cout << "nombre de coté du polygone : " << nbCote << endl;
        }
};

class Rectangle : public Polygone { 
    protected:
        int longueur ;
        int largeur ; 
    
    public : 
        Rectangle():Polygone(4){
        };
        Rectangle(int la, int lo):Polygone(4){
            longueur = lo; 
            largeur = la; 
        };

        int getLongueur(){
            return longueur ;
        }

        int getLargeur(){
            return largeur; 
        }

        void setLongueur(int lo){
            longueur=lo;
        }
        void setLargeur(int la){
            largeur=la;
        }    

        int perimetre(){
            int perim = 0;
            perim = 2*largeur+2*longueur; 
            return perim;
        }    
        void afficherCaracteristiques(){
            Polygone::afficherCaracteristiques() ; 
            cout << "largeur : " << largeur << endl ;
            cout << "longueur : " << longueur << endl;
            cout << "perimetre : "<< perimetre()<<endl; 
        }

};
class Carre : public Rectangle {
    public :
        Carre(int cote):Rectangle(cote, cote) {
        }
        int perimetre(){
            return Rectangle::perimetre();
        }

        void afficherCaracteristiques(){
            cout << "Je suis un carré " <<endl;
            Rectangle::afficherCaracteristiques();
        }
};

//TRIANGLE 

class TriangleEquilateral : public Polygone { 
    protected:
        int cote ;
    
    public : 
        TriangleEquilateral():Polygone(3){
        };
        TriangleEquilateral(int co):Polygone(3){
            cote = co; 
        };

        int getcote(){
            return cote;
        };

        void setCote(int co){
            cote=co;
        };

        int perimetre(){
            int perim = 0;
            perim = 3*cote; 
            return perim;
        };
        void afficherCaracteristiques(){
            Polygone::afficherCaracteristiques() ; 
            cout << "longeur coté: " << cote << endl ;
            cout << "perimetre : "<< perimetre()<<endl ; 
        };

};


class Coloriable 
{
    protected :
        string couleur;
    public :
        Coloriable(string coul){
            couleur=coul;
        }
        string getCouleur(){
            return couleur;
        }
        void setCouleur(string coul){
            couleur=coul;
        }
};

class Cercle : public Figure, public Coloriable{ 
    protected:
        int rayon ;
    
    public : 
        Cercle(int ra,string co):Figure(),Coloriable(co){
            rayon = ra; 
            
        };

        int getRayon(){
            return rayon;
        };

        void setRayon(int ra){
            rayon=ra;
        };

        int perimetre(){
            int perim = 0;
            perim = 2*3.14*rayon; 
            return perim;
        };
        void afficherCaracteristiques(){
            cout<<"je suis un ptn de cercle" << endl ;
            cout << "rayon" << rayon << endl ;
            cout << "perimetre : "<< perimetre()<<endl; 
            cout << "et de couleur : "<< getCouleur()<<endl;
        };

};





int Figure::compteur=0;





int main(){
    
    Figure *tab[4];
    tab[0] = new Carre(4);
    cout<<"nombre de figure : "<< Figure::getCompteur() <<endl;
    tab[1] = new Cercle(20,"bleu");
    cout<<"nombre de figure : "<< Figure::getCompteur() <<endl;
    tab[2] = new TriangleEquilateral(4);
    cout<<"nombre de figure : "<< Figure::getCompteur() <<endl;
    tab[3] = new Rectangle(4,18);
    cout<<"nombre de figure : "<< Figure::getCompteur() <<endl;


    for (int i = 0; i < 4; i++)
    {
        cout<<"figure n° "<<i+1<<" : "<<endl; 
        tab[i]->afficherCaracteristiques();
        cout<<endl;
        cout<<endl;
    }

    cout<<"nombre de figure : "<< Figure::getCompteur() <<endl;
    


    return 0; 
} 