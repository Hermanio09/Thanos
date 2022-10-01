#include <stdio.h>
#include <stdlib.h>
typedef struct prod{
    int cod_prod;
    double preco;
}PROD;
typedef struct No{

    int cod_prod;
    double preco;
    //mecanismo p/ unir nos!
    struct No * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;


void add(int cod_prod, double preco, int pos){

    if(pos >= 0 && pos <= tam){

        NO * novo = malloc(sizeof(NO));
        novo->cod_prod = cod_prod;
        novo->preco = preco;
        novo->prox = NULL;
        
        if(inicio == NULL){ //lista vazia
            inicio = novo;
            fim = novo;
            tam++;
        }else if(pos == 0){ //inicio
            novo->prox = inicio;
            inicio = novo;
            tam++;
        }else if(pos == tam){ //fim
            fim->prox = novo;
            fim = novo;
            tam++;
        }else{ // "no meio"

            NO * aux = inicio;
            for(int i = 0; i < pos-1; i++){
                //OPERACAO DE CAMINHADA - MUITO IMPORTANTE
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            tam++;
        
        }
    }else{
        printf("deu ruim!!\n");
    }
}


void imprimir(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Cod prod: %d\n", aux->cod_prod);
        aux = aux->prox;
    }
}
PROD remover(int pos){

    PROD produto;
    if(pos >= 0 && pos < tam){
        //remover!
        if(pos == 0){ //inicio!

            NO *lixo = inicio;
            inicio = inicio->prox;
            produto.cod_prod = lixo->cod_prod;
            produto.preco = lixo->preco;
            free(lixo);
            tam--;
            if(tam == 1){
                fim = NULL;
            }
        }else { //meio e fim

            NO * aux = inicio;
            for(int i = 0; i < pos-1; i++){
                //OPERACAO DE CAMINHADA - MUITO IMPORTANTE
                aux = aux->prox;
            
            }
            NO *lixo = aux->prox;
            aux->prox = aux->prox->prox;
            produto.cod_prod = lixo->cod_prod;
            produto.preco = lixo->preco;
            free(lixo);
            tam--;
            if(pos == tam -1){
                fim = aux;
            }
        
        }   
    
    }else{
        printf("Posicao invalida! :/ \n");
    }

    return produto;
}

void vira_po(){

    int metade = tam/2;
    for(int i = 0; i <= metade; i++){
        int pos = rand()% (tam - 1);
        PROD teste = remover(pos);
        printf("Cod prod removido eh:%d\n", teste.cod_prod);
    }
}


int main(){
    add(29383, 50.0, 0);
    add(29848, 150.0, 0);
    add(29646, 20.0, 2);
    add(29133, 20.0, 0);
    add(44445, 70.0, 3);
    printf("Impressao antes da remocao:\n");
    imprimir();
    printf("Impressao depois do thanos:\n");
    vira_po();
} 