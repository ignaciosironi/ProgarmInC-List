#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int dni;
    float saldo;
    char nombres[20];
	struct lista *sig;
 }nodo;

void crear (nodo *pt);
void mostrar(nodo *pt);
void crear_negativos(nodo *p, nodo* negativos);

int main()
{
    nodo *prin, *negativos;
    

    prin=(nodo*)malloc(sizeof(nodo));
    negativos=(nodo*)malloc(sizeof(nodo));

    crear(prin);
    printf("\nLos datos ingresados son: \n");
    mostrar(prin);

    crear_negativos(prin, negativos); 
    printf("\nLos datos de los saldos negativos son: \n");
    
    mostrar(negativos); 
    return 0;
}


void crear_negativos(nodo *p, nodo* negativos){

    if(p->sig!=NULL){

        if(p->saldo<0){ 

            negativos->saldo = p->saldo; 
            negativos->dni = p->dni; 
            negativos->sig= (nodo*)malloc(sizeof(nodo));
            negativos=negativos->sig; 
        }
        
        p=p->sig;
        crear_negativos(p, negativos);  
        

    } else if(p->saldo<0){ 
        
                negativos->saldo=p->saldo;
                negativos->dni=p->dni;
                negativos->sig =NULL;        
        
        }else{
            negativos->sig =NULL;
        }
    
    return;
}


void crear (nodo *registro)
{
    printf("Ingrese DNI: ");
    scanf("%d",&registro->dni);

    if (registro->dni==0){ 
        registro->sig=NULL;
    }else
	{
        printf("Ingrese saldo: ");
        scanf("%f", &registro->saldo);
        printf("Ingrese nombre: ");
        scanf("%s", registro->nombres); 

        registro->sig= (nodo*)malloc(sizeof(nodo));
        crear(registro->sig);

	}
	return;
}


void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("DNI: %d\n",registro->dni);
        printf("SALDO: %f\n", registro->saldo);
        printf("Nombre: %s\n", registro->nombres);
        mostrar (registro->sig);
	}
	return;
}