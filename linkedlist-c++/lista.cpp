#include <iostream>
using namespace std;
#include "lista.h"

Lista::Lista() : cabeca(NULL), calda(NULL)
{

}

Lista::Lista(const int &n) : cabeca(NULL), calda(NULL)
{
    
    this->push_front(n);
    
}

Lista::Lista(const Lista &o) : cabeca(NULL), calda(NULL)
{

    this->copia(o);
    
}

Lista& Lista::operator=(const Lista &o)
{
    this->copia(o);
    
    return *this;
}

// destrutor - O(n)

Lista::~Lista()
{
    this->clear();
}

// insercao no fim - O(1)

void Lista::push_back(const int &n)
{
    if(!cabeca){
        push_front(n);
        return;
    }
    
    Nodo *novo = new Nodo;
    
    novo->dado = n;
    novo->proximo = NULL;
    calda->proximo = novo;
    calda = novo;
    
    novo = NULL;
}

// insercao no comeco - O(1)

void Lista::push_front(const int &n)
{
    Nodo *novo = new Nodo;
    novo->dado = n;
    
    // se não há cabeca, então crie
    
    if(!cabeca){
        
        novo->proximo = NULL;
        
        cabeca = novo;
        calda = cabeca;
        
    }
    else{
        
        novo->proximo = cabeca;
        cabeca = novo;
        
    }
    
    novo = NULL;
}

// insercao em posicao arbitraria - O(n)

void Lista::insert(const int &pos, const int &n)
{
    if(pos == 0 || cabeca == NULL) {
        
        this->push_front(n);
        return;
        
    }
    
    Nodo *novo = new Nodo;
    novo->dado = n;
    
    Nodo *cursor = cabeca;
    for(int i = 0; i < pos-1 ; i++)
        cursor = cursor->proximo;
    
    novo->proximo = cursor->proximo;
    cursor->proximo = novo;
    
    novo = NULL;
}

void Lista::printar()
{
    Nodo *cursor;
    cursor = cabeca;
    
    // se não há cursor ( cursor nulo ) é porque a lista está vazia.
    
    if(!cursor)
        
        cout<<"lista vazia";
    
    else{
        
        while(cursor != NULL){
            
            cout<<cursor->dado<<" ";
            cursor = cursor->proximo;
            
        }
    }
    
    cout<<endl;
}

// limpar a lista - O(n)

void Lista::clear()
{
    Nodo *cursor = cabeca;
    
    // enquanto tem cabeca, então deleta da memoria
    while(cabeca) {
        
        cabeca = cursor->proximo;
        delete cursor;
        cursor = cabeca;
        
    }
    
    cursor = calda = NULL;
}


void Lista::copia(const Lista &o)
{
    
    if(cabeca)
        this->clear();
    
    Nodo *cursor = o.cabeca;
    
    
    while(cursor != NULL){
        
        this->push_back(cursor->dado);
        cursor = cursor->proximo;
        
    } 
    
}