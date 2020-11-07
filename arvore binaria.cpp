#include<iostream>
using namespace std;

struct No {

int chave;//conteudo que ele guarda
No *esq;
No *dir;

};

struct ArvoreBinaria{
No *raiz;
void Criar();
No * Inserir(No *noAtual, int valor);
bool Pesquisar(No *noAtual,int valor);
void Inserir_semretorno(int valor);
void Imprime_ordem(No* noAtual);
void Imprime_pos_ordem(No* noAtual);
void Imprime_pre_ordem(No* noAtual);
void Pesquisar_folha(No* noAtual, int valor);
};

void ArvoreBinaria::Criar(){

raiz=NULL;

}
No * ArvoreBinaria::Inserir(No *noAtual, int valor){

if(noAtual==NULL){
    noAtual= new No;
    noAtual->dir=NULL;
    noAtual->esq=NULL;
    noAtual->chave=valor;
}

else if(valor<noAtual->chave){// verificar se vai pra esq ou dir
    noAtual->esq= Inserir(noAtual->esq, valor);

}
else {
        noAtual->dir= Inserir(noAtual->dir, valor);
}

return noAtual;

}


bool ArvoreBinaria::Pesquisar(No* noAtual, int valor){

if(noAtual==NULL){

return false;
}

else if(noAtual->chave== valor){
    return true;
}

else{
    if(valor<noAtual->chave){
        Pesquisar(noAtual->esq, valor);
    }
    else {
         Pesquisar(noAtual->dir, valor);
    }

}
}

void ArvoreBinaria::Inserir_semretorno(int valor){

raiz=Inserir(raiz, valor);
}

void ArvoreBinaria::Imprime_ordem(No* noAtual){

if(noAtual!=NULL){
    Imprime_ordem(noAtual->esq);
    cout<<"Elemento visitado foi o"<<noAtual->chave<<endl;
    Imprime_ordem(noAtual->dir);

}
}
void ArvoreBinaria::Imprime_pos_ordem(No* noAtual){
    if(noAtual!=NULL){
    Imprime_pos_ordem(noAtual->esq);
    Imprime_pos_ordem(noAtual->dir);
    cout<<"Elemento visitado foi o"<<noAtual->chave<<endl;
    }
}
void ArvoreBinaria::Imprime_pre_ordem(No* noAtual){
    if(noAtual!=NULL){
    cout<<"Elemento visitado foi o"<<noAtual->chave<<endl;
    Imprime_pre_ordem(noAtual->esq);
    Imprime_pre_ordem(noAtual->dir);

    }
}

void ArvoreBinaria::Pesquisar_folha(No* noAtual, int valor){ 
    //a função pesquisa na arvore a partir de um valor fornecido
    //caso esse nó esteja com a direita e a esquerda vazias ele é identificado como folha 

if(noAtual==NULL){
    cout<<"Elemento não existe";
}

else if(noAtual->chave==valor){
    if (noAtual->dir==NULL && noAtual->esq==NULL)
    {
        cout<<noAtual->chave<<" É um nó Folha"<<endl;
    }
    else
    {
        cout<<noAtual->chave<<" Não é um nó folha"<<endl;
    }
}

else{
    if(valor<noAtual->chave){
        Pesquisar_folha(noAtual->esq, valor);
    }
    else {
         Pesquisar_folha(noAtual->dir, valor);
    }

}
}

int main(){
ArvoreBinaria arv;
arv.Criar();
arv.Inserir_semretorno(50);
arv.Inserir_semretorno(10);
arv.Inserir_semretorno(27);
arv.Inserir_semretorno(33);
arv.Inserir_semretorno(12);
arv.Inserir_semretorno(13);

if(arv.Pesquisar(arv.raiz,28)){
        cout<<"Elemento foi encontrado"<<endl;
   }
   else{
     cout<<"Elemento nâo foi encontrado"<<endl;

}

arv.Pesquisar_folha(arv.raiz,13);
arv.Pesquisar_folha(arv.raiz,10);

arv.Imprime_pre_ordem(arv.raiz);
cout<<endl;
arv.Imprime_ordem(arv.raiz);
cout<<endl;
arv.Imprime_pos_ordem(arv.raiz);




return 0;
}

