#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cmath>
# define f1(x,y) (x*x+pow((y-3),2)-22) //Ingreso las componentes de la  funcion f
# define f2(x,y) (5*x+9*y-55)
# define jf11(x,y) (2*x)        // Defino el Jacobiano
# define jf12(x,y) (2*y-6)   
# define jf21(x,y) (5)
# define jf22(x,y) (9)
using namespace std;
int main ()
{float x0,y0,x11,x12;  //Entro la semilla (x0,y0) 
float j11,j12,j21,j22,nj11,nj12,nj21,nj22; //variables auxiliares para calculos del jacobiano 
float det,d1,d2,tol; // variables auxiliares y tolerancia                    
int n;
cout<<"Ingrese x0="; cin>>x0;
cout<<"Ingrese y0="; cin>>y0;
cout<<"Ingrese n="; cin>>n;
cout<<"Ingrese tol="; cin>>tol;
printf("k \t x01    \t x02  \n");	
cout << "===========================================" << endl;	
    for (int k=1;k<=n;k++)    
    {  if((pow(f1(x0,y0),2)+pow(f2(x0,y0),2))<=tol){
		break; }
	
	else {	//Calculo J(x0,y0)
    j11=jf11(x0,y0);j12=jf12(x0,y0);
    j21=jf21(x0,y0);j22=jf22(x0,y0);
    
	//Calculo Inversa de J=  1/det(J) (Adj(J)*T) 
	 
    //1.Calculo determinante
    det=j11*j22-j12*j21;
    
    if (det==0){   		
		cout<<"ERROR,Matriz jacobiana no invertible.Ingrese nueva semilla";
    		break;}  		
    else{
    		//2. Calculo inversa J componente a componente 
    	nj11=j22/det; 	nj12=-j12/det;
    	nj21=-j21/det;	nj22=j11/det;
    
   		 //Calculo inv[J(x0,y0)].f(x0,y0)
    	d1=nj11*f1(x0,y0)+nj12*f2(x0,y0);
    	d2=nj21*f1(x0,y0)+nj22*f2(x0,y0);
    
    		//Hallo siguiente x1
    	x11=x0-d1;
    	x12=y0-d2;
    	
    	//Asigno x1 --->  x0
    	x0=x11;
    	y0=x12;   	
		printf("%d %12.6f %12.6f \n",k,x0,y0);	} 	  
		}				    
	} 
	return 0;
}
