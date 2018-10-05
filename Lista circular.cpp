#include <stdlib.h>
#include <stdio.h>


typedef struct _nodo{
	int valor;
	struct _nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;


void Insertar(Lista *l,int v);
void Borrar(Lista *l,int v);
void BorrarLista(Lista *);
void MostrarLista(Lista l);
void BuscarLista(Lista *, int v);
void ordenar(Lista lista);
int contador =0,vec[100];

int main(){
	Lista lista = NULL;
	pNodo p;
	int c,d,opcion;
	
	do{
        system("cls");
      
        printf("\n\tMenu lista circular                   \n");
        printf("\n\t1. INGRESAR UN DATOS                  \n");
        printf("\n\t2. MOTRAR DATOS                       \n");
        printf("\n\t3. BUSCAR DATO                        \n");
        printf("\n\t4. ELIMINAR DATO                      \n");
        printf("\n\t5. ORDENAR ELEMENTOS DE MAYOR A MENOR \n");
        printf("\n\t6. BORRAR TODA LA LISTA               \n");
        printf("\n\t0. Menu Principal                     \n");
        printf("\n\tIngrese una opcion:                   \n");
       scanf("%d",&opcion);
        system("cls");
        switch(opcion){
            case 1: system("cls");
					printf("ingrese cuantos valores va a listar: \n");
					scanf("%d",&c);
					for(int i = 0 ; i < c ;i++){
					printf("ingrese el el numero %d \n",i+1);
					scanf("%d",&d);
					Insertar( &lista, d);
					contador++;
						}
           			 break;
            case 2: system("cls");
					MostrarLista(lista);
					
           			 break;
            case 3:	system("cls");
					printf("ingrese el el numero a buscar \n");
					scanf("%d",&d);
					BuscarLista(&lista,d);
            break;
            case 4:	system("cls");
            	
					printf("que numero desea borrar: \n");
					scanf("%d",&d);
					Borrar(&lista,d);
            		break;
            case 5: system("cls");
           			ordenar(lista);
            
            	break;
            case 6: system("cls");
           			BorrarLista(&lista);
            
            	break;
            default: printf("Opcion invalidad\n");
        }
    }while(opcion != 0);
	

	system("pause");
	
	return 0;
	
}

void Insertar(Lista *lista,int v){
	pNodo nodo;
	
	nodo = (pNodo)malloc(sizeof(tipoNodo));
	nodo->valor = v;
	vec[contador]=v;
	if (*lista == NULL){
		*lista = nodo;
	}else{
		nodo->siguiente = (*lista)->siguiente;
	}
	(*lista)->siguiente = nodo;
}

void Borrar(Lista *lista, int v){
	
	pNodo nodo;
	
	nodo = *lista;
	
	do{
		if((*lista)->siguiente->valor != v) *lista = (*lista)->siguiente;
	}while((*lista)->siguiente->valor != v && *lista != nodo);
	
	if((*lista)->siguiente->valor == v){
		if (*lista == (*lista)->siguiente){
			free(*lista);
			*lista = NULL;
		}else{
			nodo = (*lista)->siguiente;
			(*lista)->siguiente = nodo->siguiente;
		}
	}
	system("pause");
}

void BorrarLista(Lista *lista){
	
	pNodo nodo;
	
	while((*lista)->siguiente != *lista){
		nodo = (*lista)->siguiente;
		(*lista)->siguiente = nodo->siguiente;
		free(nodo);
	}
	
	free(*lista);
	*lista = NULL;
	system("pause");
}

void MostrarLista(Lista lista){
	
	pNodo nodo = lista;
	
	do{
		printf("%d ->",nodo->valor);
		nodo = nodo->siguiente;
	}while(nodo != lista);
	
	printf("\n");
	system("pause");
}


void BuscarLista(Lista *lista, int v){
	
	pNodo nodo;
	
	nodo = *lista;
	
	do{
		if((*lista)->siguiente->valor != v) *lista = (*lista)->siguiente;
	}while((*lista)->siguiente->valor != v && *lista != nodo);
	
	if((*lista)->siguiente->valor == v){
			printf("se encontro el elemento %d\n",v);
		}else{
				printf("no se encontro el elemento %d \n",v);
		}
		system("pause");
	
}


void ordenar(Lista lista){
	int temp,d;
	
	BorrarLista(&lista);
	
		for (int i=1;i<contador;i++)
			{
      	 for (int j=0; j < contador-i ;j++) 
       		{
         	 if (vec[j] < vec[j+1])
          	{
            temp=vec[j];
            vec[j]=vec[j+1];
            vec[j+1]=temp;
          		}
       		}
    	}
    	
    	for(int j =0 ; j < contador ; j++){
				d=vec[j];
				Insertar(&lista, d);
			}
			
			printf("Se ordeno de mayor a menor\n");
			system("pause");
}
