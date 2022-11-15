#include <stdio.h> 
#include <stdlib.h> 
#define MAX 10

//Lucas Deodato 

typedef struct { 	
	int fim; 	
	int vetor [MAX]; 
} lista; 

void libera ( lista*l ) { 	
	free(l); 
}
 
lista*cria () { 	
	lista*l; 	
	l = ( lista* ) malloc ( sizeof ( lista ) ); 
	l->fim = 0; 	
	return l; 
}
 
int vazia ( lista *l ) { 	
	if(l->fim == 0){ 		
		return 1;
	} 	
	else { 		
		return 0; 	
	} 
}
 
int cheia ( lista*l ) {
	if(l->fim == MAX){ 		
		return 1; 	
	} else { 		
		return 0; 	
	} 
} 

void listar ( lista*l, int v) { 	
	l->vetor[l->fim] = v; 
	l->fim++;
}

void inserirporpos ( lista*l, int v, int chave ) {
	int i;
	for ( i=0; i<l->fim; i++ ){
		if (chave == l->vetor[i]) {
			l->vetor[i] = v; 
			l->fim++;	
		}
	}	
}

int desenlistar ( lista*l ) { 	
	int aux; 
	l->fim--; 	
	aux = l->vetor[l->fim]; 		
	return aux; 
} 


int recuperaPOS ( lista*l, int v, int chave ) {
	int i;
	for ( i=0; i<l->fim; i++ ){
		if (chave == l->vetor[i]) {
			l->vetor[i] = v; 
   return 1;
   }
     else {
     return 0;
    }
  }
}

int recuperarchave ( lista*l, int v, int chave ) {
	    int i;
	    for(i = 0; i < l->fim; i++){ 
        if(l->vetor[i] == chave){ 
         return i;
        }
      }
    return -1;
}

void imprime ( lista*l ){
	int i;
	for (i = 0; i < l->fim; i++){
		printf ("l->vetor[%d] = %d\n",i,l->vetor[i]);
	}	
}

int quantidade ( lista*l ) {
	int i, cont = 0;
	for ( i=0; i< l->fim; i++) {
		cont ++;
	}
	return cont;
}

int main () { 	 	
	lista*l; 	
	l = cria();

	int x, op, q, pos, chave, r; 
		 		
	do { 
	
		printf(" ___________________________________________________\n");
		printf("|                                                   |\n");
		printf("|           1 - listar                              |\n");
		printf("|           2 - desenlistar                         |\n"); 	
		printf("|           3 - imprime lista                       |\n");
		printf("|           4 - quantidade de elementos na lista    |\n");
		printf("|           5 - listar por posicao                  |\n");
		printf("|           6 - recuperar por posicao               |\n");
		printf("|           7 - recuperar por chave                 |\n");
		printf("|           8 - sair                                |\n");
		printf("|___________________________________________________|\n");
		printf("-------------->>ESCOLHA : ");
		scanf("%d", &op);	 		
		 			 		
		switch ( op ) { 			 			
		case 1: 				
			if(cheia ( l ) == 1) { 					
				printf("\nLISTA CHEIA.\n"); 				
			} 				
			else { 					
				printf("\nVALOR: "); 						
				scanf("%d", &x); 						
				listar ( l, x ); 				
			} 				
			break;
			 				 			
		case 2: 				
			if( vazia ( l ) == 1) { 					
				printf("\nLISTA VAZIA.\n"); 				
			} 				
			else { 					
				x = desenlistar ( l ); 					
				printf ( "\nElemento %d retirado\n",x );
	 		} 				 				
			break;
			
		case 3:
     if(vazia ( l ) == 1) {
        printf("\nLISTA VAZIA.\n"); 		
     }
    else {
			   imprime ( l );
    }
			break;
				
		case 4: 
   if(vazia ( l ) == 1) {
        printf("\nLISTA VAZIA.\n"); 		
     }
    else {
			    q = quantidade( l );
			    printf("\no total de elementos na lista eh de %d\n", q); 
			 }
    break;
		
		case 5:
			if(cheia ( l ) == 1) { 					
				printf("\nLISTA CHEIA.\n"); 				
			} 				
			else { 		
				printf("Digite a posição que voce deseja fazer a alteração: ");
				scanf("%d", &chave);
				inserirporpos ( l, x, chave );
				printf("Valor atual do vetor [ %d ] = %d\n", chave, l->vetor [ chave ]);
				printf("novo valor: ");
				scanf("%d",&l->vetor [ chave ]);
				printf("Valor modificado do vetor [ %d ] = %d\n", chave, l->vetor [ chave ]);
			}
			break;
			
		case 6:
     printf("Digite a posicao para saber o valor: ");
				scanf("%d", &chave);
				inserirporpos ( l, x, chave );
    	printf("Valor do vetor [ %d ] = %d\n", chave, l->vetor [ chave ]);
			
			break;
    
  case 7:
         printf("Digite a posicao para saber o valor: ");
				    scanf("%d", &chave);
      		r = recuperarchave ( l, x, chave );
        if( r == -1){
            printf("Valor nao encontrado.\n");
         }
        else {
            printf("Valor se encontra na posicao  [ %d ] \n", r);
        }    
    break;		
							 			
		case 8: 
			libera ( l );			
			return 0;
			break; 		
		} 		 	
	}while ( op!=8 ); 
}
