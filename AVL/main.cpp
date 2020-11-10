#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//No da arvore AVL
struct No
{
    int info;
    No *esquerda;
    No *direita;
    int altura = 0;
};

//Estrutura da arvore AVL
struct ArvoreAVL
{
    No *raiz;

    void Criar(ArvoreAVL &MinhaArvore);
    int Maximo(int a, int b);
    int Atribui_altura(No *N);
    No *NovoNo(int chave);
    int Calcula_balanceamento(No *N);
    void RotacaoEsquerda(No *&Raiz);
    void RotacaoDireita(No *&Raiz);
    void RealizarRotacao(No *&Raiz);
    void Inserir(No *&Raiz, int valor);
};
//Metodo de inicializacao da AVL
void Criar(ArvoreAVL &MinhaArvore)
{
    MinhaArvore.raiz = NULL;
}

//Funcao para pegar o maior entre de dois numeros - SLIDE
int Maximo(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

//Funcao para pegar a altura da arvore
int Atribui_altura(No *N)
{

    if (N != NULL)
        N->altura;
}

//Funcao para alocar um novo no
No *NovoNo(int chave)
{
    No *node = new No;
    node->info = chave;
    node->esquerda = NULL;
    node->direita = NULL;
    node->altura = 0;
    return (node);
} //Funcao para pegar o fator de balanceamento de um no
int Calcula_balanceamento(No *N)
{
    if (N == NULL)
        return 0;
    return Atribui_altura(N->esquerda) - Atribui_altura(N->direita);
}

//rotação simples a esquerda
void RotacaoEsquerda(No *&Raiz)
{
    struct No *no;                                        //cria um no auxiliar
    no = Raiz->direita;                                   //recebendo um filho da direita
    Raiz->direita = no->esquerda;                         // filho a esquerda recebe o filho a esquerda
    no->esquerda = Raiz;                                  // o filho a direita recebe a raiz
    Raiz->altura = Maximo(Atribui_altura(Raiz->direita),  // o filho a direita recebe a raiz
                          Atribui_altura(Raiz->esquerda)) // altura da raiz será  a maior altura do filho da direita
                   + 1;
    no->altura = Maximo(Atribui_altura(no->direita), //altura do no sera o maior valor da altura da direita
                        Raiz->altura) +
                 1; //e a altura da raiz + 1
    Raiz = no;      //raiz recebe o valor guardado no no
}

//rotação simples a direita
void RotacaoDireita(No *&Raiz)
{                                                         // no que deseja balancear
    struct No *no;                                        //cria um no auxiliar
    no = Raiz->esquerda;                                  //recebendo um filho da esquerda
    Raiz->esquerda = no->direita;                         // filho a esquerda recebe o filho a direita
    no->direita = Raiz;                                   // o filho a direita recebe a raiz
    Raiz->altura = Maximo(Atribui_altura(Raiz->esquerda), // altura da raiz será  a maior altura do filho da esquerda
                          Atribui_altura(Raiz->direita)) +
                   1;
    no->altura = Maximo(Atribui_altura(no->esquerda), //altura do no sera o maior valor da altura da direita
                        Raiz->altura) +
                 1; // e do filho da direita +1
    Raiz = no;      //raiz recebe o valor guardado no no
}

void RealizarRotacao(No *&Raiz)
{
    int fb = Calcula_balanceamento(Raiz);
    if (fb == 2)
    { //Rotacao direita
        int fbe = Calcula_balanceamento(Raiz->esquerda);
        if (fbe == -1)
        { //Rotacao dupla direita
            RotacaoEsquerda(Raiz->esquerda);
        }
        RotacaoDireita(Raiz);
        return;
    }
    else if (fb == -2)
    { //Rotacao esquerda
        int fbd = Calcula_balanceamento(Raiz->direita);
        if (fbd == 1)
        { //Rotacao dupla esquerda
            RotacaoDireita(Raiz->direita);
        }
        RotacaoEsquerda(Raiz);
        return;
    }
}

//Funcao recursiva para insercao
void Inserir(No *&Raiz, int valor)
{
    //Insercao no no folha
    if (Raiz == NULL)
    {
        Raiz = NovoNo(valor);
        return;
    }
    if (valor < Raiz->info)
        Inserir(Raiz->esquerda, valor);
    else if (valor > Raiz->info)
        Inserir(Raiz->direita, valor);
    else // Ja existe o elemento
        return;
    //Atualizar a altura do no
    Raiz->altura =
        1 + Maximo(Atribui_altura(Raiz->esquerda),
                   Atribui_altura(Raiz->direita));
    RealizarRotacao(Raiz);
}




