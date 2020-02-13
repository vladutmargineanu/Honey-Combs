#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCHAR 32678
#define MAXSIR 1024
#define MAXCOL 50
#define LINMAX 1024
#define COLMAX 1024

int Numero[MAXCHAR];
char sir[MAXSIR][MAXCHAR];  //toate sirurile de caractere intr-un vector de siruri de caractere
char fisier[MAXCHAR];     //sirurile de caractere din fisiere
int numar;              //indexul vectorului de siruri de caractere
int vector[MAXCOL];         //vector cu numarul celulelor pe coloane
int nr_coloane;         //numaram cate coloane avem
char fagure[LINMAX][COLMAX]; //construirea fagurelui
int maxim;                   //coloana cu cele mai multe celule

typedef struct Regina {int x,y;} regina;
 //tablou de inregistrare in care stocam coordonatele reginelor in fagure

regina coordonate[3*MAXCOL];

void citire(){

while(fgets(fisier , MAXCHAR , stdin) != NULL){

	if(fisier[0] == '\n') break;  //citim fiecare sir de caractere  
    strcpy(sir[numar++] , fisier);//copiem intr-un vector de siruri de caractere fiecare sir

    }


}




void matrice( char x , int nr1 , int nr2, int tip);

void resetare(int a,int b);

void prelucrare (){

	char litera;       //pentru pastrarea literei R sau C
	char *p;           //pentru parcurgerea fiecarui sir de caractere,pointer de tip char
	int i=0;
	int nr1=0;         //pentru parcurgerea lui vector => nr1 elemente
    int nr2=0;         //pentru parcurgerea lui coordonate => nr2 elemente

    citire();

    while(i < numar){
        maxim = 0;
        p=sir[i];  //parcurgem fiecare sir de caractere cu ajutorul unui pointer  si ii prelucram elementele
        nr1 = 0;
        nr2 = 0;
        while (( *p <= '9' &&  *p >= '0') || *p == ' ') {

            if( *p == ' ') {
                p++;            //prelucram elementele sirului pana la intalnirea literei R sau C in vector
            }else{
                vector[nr1] = 0; //
                while( *p <= '9' && *p >= '0'){
                    vector[nr1] = vector[nr1] * 10 + ( *p - '0');
                    p++;
                }
                if(maxim < vector[nr1]) maxim = vector[nr1]; //retinem numarul maxim de celule
                nr1++;
            }
        }
        Numero[i] = nr1;  //retinem numarul de elemente din vector in Numero
        litera = *p;
        p++;
        while (( *p <= '9' &&  *p >= '0') || *p == ' '){
            if( *p == ' ') //parcurgem sirul de caractere dupa trecerea de caracterul R sau C
                p++; 
            else {           //retinem coordonatele matcilor pentru fiecare fagure
                coordonate[nr2].x=0; 

             while( *p <= '9' && *p >= '0'){
                   coordonate[nr2].x = coordonate[nr2].x * 10 + ( *p - '0');
                   p++;
                }
            p++;
            coordonate[nr2].y = 0;
            while( *p <= '9' && *p >= '0'){
                coordonate[nr2].y = coordonate[nr2].y * 10 + ( *p - '0');
                p++;
             }
            nr2++;
          }
        }
        matrice(litera , nr1 , nr2 , Numero[i]);
        resetare(LINMAX-1,COLMAX-1);
        i++;
    }

}



void afisare(int a , int b);

void matrice( char x , int nr1 , int nr2, int tip){

  int pozitie;
  int i,j;
  int LINIE ;
  int COLOANA ;
  int nr=0;
    int maxOfLines = 0;
  if(x == 'C') {pozitie=1 ; maxOfLines = 0;       //daca este C o coboram
    }
   
  else {pozitie = 0 ; maxOfLines = 0;           //daca este R o ridicam
    }       
  
  for (i = 0; i < LINMAX; i++ )    //setam matricea cu spatii
     for (j = 0; j < COLMAX; j++)
        fagure[i][j] = ' '; 

    maxOfLines += maxim*2;
    maxOfLines++;

  while( nr1 != 0){

    int nr_cel=0;

    while (nr_cel < vector[nr] ) {   //construim celulele pe coloane

  fagure [nr_cel * 2 + pozitie][ nr * 2 + 1] = '_';
  fagure [nr_cel * 2 + pozitie + 1][nr * 2] = '/';
  fagure [nr_cel * 2 + pozitie + 1][nr * 2 + 2] = '\\';
  fagure [nr_cel * 2 + pozitie + 2][nr * 2] = '\\';
  fagure [nr_cel * 2 + pozitie + 2][nr * 2 + 2] = '/';
  fagure [nr_cel * 2 + pozitie + 2][nr * 2 + 1] = '_';

    for ( i = 0; i < nr2; i++)       //verificam daca se afla matca pe coloana respectiva
      if ( coordonate[i].x  == (nr + 1) && coordonate[i].y == (nr_cel + 1) )
       fagure [nr_cel * 2 + pozitie + 1][nr * 2 + 1] = 'Q';



LINIE = maxOfLines;   //numarul maxim de linii
COLOANA = (tip)*2 ;   //numarul maxim de celule

nr_cel++;

    }
 nr++;

 nr1--;

 if(pozitie==0) pozitie=1; //setam pozitia pentru coloana urmatoare
   else pozitie=0;




  }

  afisare(LINIE , COLOANA);



}


void afisare(int a , int b){
  int i,j;
  for ( i = 0 ; i <= a; i++) {   //afisarea matricei cu fagurele
    for( j = 0; j <= b; j++)
    printf("%c" , fagure[i][j]);

         printf("\n");
    }
}

void resetare(int a,int b)
{

int i,j;     //setam matricea cu spatii dupa fiecare prelucrare

  for ( i = 0 ; i <= a; i++) {
    for( j = 0; j <= b; j++)
fagure[i][j] = ' ';

    }
}


int main(){
  
  prelucrare();

    return 0;
}
