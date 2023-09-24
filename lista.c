#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct No{
    int matricula;
    char *nome;
    float nota;
    struct No *proximo;
}No;

No *InserirInicio(No *atual,No dados){
    No *novo=(No*)malloc(sizeof(No));
    novo->matricula=dados.matricula;
    novo->nome=dados.nome;
    novo->nota=dados.nota;
    novo->proximo=atual;
    atual=novo;

    return atual;
}

No *InserirFinal(No *atual,No dados){
    No *no,*novo=(No*)malloc(sizeof(No));
    novo->matricula=dados.matricula;
    novo->nome=dados.nome;
    novo->nota=dados.nota;

    no=atual;

    while(no->proximo!=NULL){
        no=no->proximo;
    }
    no->proximo=novo;

    return atual;
}

void Imprimir(No *atual){
    if(atual==NULL){
        printf("Lista vazia\n");
    }else{
        printf("---------------------------------------------LISTA-------------------------------------------------------\n");
        while(atual!=NULL){
            printf("  Matricula: %d",atual->matricula);
            printf("  Nome: %s",atual->nome);
            printf("  Nota: %.1f\n",atual->nota);
            atual=atual->proximo;
        }
        printf("---------------------------------------------LISTA-------------------------------------------------------\n");
    }
}

No *Seleciona(No *atual,int id){
    No *no,*Selecao=(No*)malloc(sizeof(No));
    no=atual;
    if(atual==NULL){
        printf("Lista vazia:");
    }else{
        while(no->matricula!=id){
            no=no->proximo;
        }
        Selecao->matricula=no->matricula;
        Selecao->nome=no->nome;
        Selecao->nota=no->nota;
    }

    return Selecao;
}

float CalcMedia(No *atual){

    float soma=0,media;
    int c=0;

    if(atual==NULL){
        printf("Lista vazia");
    }else{

        while(atual!=NULL){
            soma=soma+atual->nota;
            atual=atual->proximo;
            c++;
        }
    media=soma/c;
    }

    return media;
}

No *Remover(No *atual,int id){
    No *no,*inicio=(No*)malloc(sizeof(No));
    no=atual;
    inicio=atual;

    while(id!=no->matricula){
        no=no->proximo;
    }
    if(no==inicio&&no->proximo==NULL){
        atual=NULL;
    }else if(no->proximo==NULL){
        while(atual->proximo!=no){
            atual=atual->proximo;
        }
        inicio->proximo=atual;
        atual->proximo=NULL;
        atual=inicio;
    }else if(no==inicio){
        no=no->proximo;
        atual->proximo=NULL;
        atual=no;
    }else{
        while(atual->proximo!=no){
            atual=atual->proximo;
        }
        inicio->proximo=atual;
        no=no->proximo;
        atual->proximo=no;
        atual=inicio;
    }
    return atual;
}

int main(){

    setlocale(LC_ALL,"");
    No *lista=NULL;//cria lista vazia
    No *selecionado=(No*)malloc(sizeof(No));
    No dados;
    int op,id;
    float Media;
    printf("----------------------------------------LISTA DE INFORMA��ES DOS ALUNOS-------------------------------------------------\n");
    do{
        printf("[1]: Inserir no inicio\n");
        printf("[2]: Imprimir \n");
        printf("[3]: Inserir no final\n");
        printf("[4]: Remover elemento\n");
        printf("[5]: Buscar aluno\n");
        printf("[6]: Media aritmetica dos alunos\n");
        printf("[7]: Encerrar o programa\n");
        scanf("%d",&op);

        switch(op){
            case 1:
                printf("insira a matricula do aluno: ");
                scanf("%d",&dados.matricula);
                dados.nome=(char*)malloc(sizeof(char)*40);
                printf("insira o nome do aluno: ");
                scanf("%s",dados.nome);
                printf("insira a nota do aluno: ");
                scanf("%f",&dados.nota);
                lista=InserirInicio(lista,dados);
                break;
            case 2:
                Imprimir(lista);
                break;
            case 3:
                printf("insira a matricula do aluno: ");
                scanf("%d",&dados.matricula);
                dados.nome=(char*)malloc(sizeof(char)*40);
                printf("insira o nome do aluno: ");
                scanf("%s",dados.nome);
                printf("insira a nota do aluno: ");
                scanf("%f",&dados.nota);
                lista=InserirFinal(lista,dados);
                break;

            case 4:
                printf("insira a matricula do aluno que deseja remover: ");
                scanf("%d",&id);
                lista=Remover(lista,id);
                break;
            case 5:
                printf("insira a matricula do aluno que deseja Buscar: ");
                scanf("%d",&id);
                selecionado=Seleciona(lista,id);
                printf("Matricula do selecionado: %d\n",selecionado->matricula);
                printf("Nome do selecionado: %s\n",selecionado->nome);
                printf("Nota do selecionado: %f\n",selecionado->nota);
                break;
            case 6:
                Media=CalcMedia(lista);
                printf("A media das notas dos alunos � : %f\n",Media);
                break;
            case 7:
                printf("Finalizandooooooooooooooo\n");
                break;
            default:
                printf("Opcao invalida\n");

        }
    }while(op!=7);

    }
