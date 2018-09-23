#include <stdio.h>
#include <stdlib.h>

    
/* Mostra os elementos do vetor */
void mostra(int* v, int n){
    int i;
        for(i=0; i<n; i++){
            printf("%d\t",v[i]);
        }
        printf("\n \n");
    }


/* No for pega o elemento  maior e coloca no final a fim de ordenar.
    Vai verificando e faz a troca
*/
void bubbleSort(int* v, int n){//vetor e seu tamanho;

    int i, aux,continua;
do{
    continua=0;
    for(i=0; i<n-1; i++){ //vai até a penúltima posição do vetor
        if(v[i] > v[i+1]){
            aux = v[i];
            v[i] = v[i+1];
            v[i+1]=aux;
            continua=i;
        }

    }
    
}while(continua!=0);

}
/*Move os valores maiores para a frente*/
/*## EXEMPLO DAS CARTAS DE BARALHO###*/

void insertionSort(int* v, int n){
    int i,j,aux;
    for(i=0; i<n; i++){
        aux = v[i];
        for(j=i; (j>0)&&(aux < v[j-1]); j--){//Voltando os indice j e copiando os elementos para frente 
            v[j] = v[j-1];
        }
        v[j] = aux;
        

    }
}
void selectionSort(int* v, int n){
    int i, j, menor, troca;

    for(i=0; i<n; i++){

        menor = i;

        for(j=i+1; j < n;j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}


void intercala(int p,int q,int r,int* v){
    int i,j,k, *w;
    w = (int*)malloc((r-p)*sizeof(int));
    i=p;
    j=q;
    k=0;

    while(i<q && j<r){
        if(v[i] <= v[j]){
            w[k++]=v[i++];
        }else{
            w[k++] = v[j++];
        }
    }
    while(i<q){
        w[k++] = v[i++];
    }
    while(j<r){
        w[k++]=v[j++];
    }

    for(i=p; i<r; i++){
        v[i]=w[i-p];    
    }
    free(w);
}

/*Merge Sort é um algoritmo recursivo*/

void mergeSort(int p, int r,int* v){
    if(p < r-1){
        int q = (p+r) / 2;
        mergeSort(p,q,v);
        mergeSort(q,r,v);
        intercala(p,q,r+1,v);
    }
}


int particiona(int* v, int inicio, int final) {
    int esq, dir, pivo, aux;

    esq = inicio;
    dir = final;
    pivo = v[inicio];

    while(esq < dir) {
        while(v[esq] <= pivo) 
            esq++;
        
        while(v[dir] > pivo)
            dir--;
        
        if(esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
        
    }
    v[inicio] = v[dir];
    v[dir]  = pivo;


    return dir;

}
void quickSort(int* v, int inicio, int fim) {
    int  p;

if(fim > inicio){
    p = particiona(v,inicio,fim);
    quickSort(v,inicio,p-1);
    quickSort(v,p+1,fim);
}

}
void criaHeap(int *vet, int i, int f ) {
    int aux = vet[i]; //Posição PAI

    int j = i*2+1; //filho


    while(j <= f ){
        if(j < f){
            if(vet[j] < vet[j+1]){ /*Pai tem dois filhos. Quem é o maior*/

                j=j+1;
            }
        }
        if(aux < vet[j] ){ /*FILHO maior que o PAI?*/
            vet[i] = vet[j];//FILHO se torna PAI
            i = j;
            j = 2 * i +1;   //Repetir o processo
        }else{
            j = f + 1;
        }
    }
    vet[i] = aux; //Antigo PAI ocupa lugar do último filho analisado 

}

void heapSort(int* v, int n) {
    int i, aux;
    /*Cria heap a partir dos dados*/
    for(i=(n-1)/2; i>=0; i--){
        criaHeap(v,i , n-1);
    }   


    for(i=n-1; i >= 1; i--){
        /*Pega o maior elemento da heap
        e coloca na posição correspondente no array*/
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;

        criaHeap(v,0,i-1); //Reconstruir heap
    }

}




int main(){

    int vetor[] = {1,6,2,5,3,4},i;
    int n = 6;
    printf("Desordenado\n");
    
    mostra(vetor,n);

    bubbleSort(vetor,n);
    
    printf("Bubble Sort\n");
     mostra(vetor,n);


    insertionSort(vetor,n);
    printf("Insertion Sort\n");

    mostra(vetor,n);

    selectionSort(vetor,n);
    printf("Selection Sort\n");
    mostra(vetor,n);


    mergeSort(0, 5,vetor);
    printf("Merge Sort\n");

    mostra(vetor,n);
    

     quickSort(vetor, 0, 5);
     printf("Quick Sort\n");

     mostra(vetor,n);

     heapSort(vetor,n);
     printf("Heap Sort\n");

     mostra(vetor,n);
}




