#include<iostream>

using namespace std;

#include "lista.h"

int main()
{
    Lista lista;
    lista.push_back(3);
    lista.push_back(4);
    lista.printar();
    
    Lista lista2(lista);
    
    lista2.printar();
    
    lista2.push_back(10);
    cout<<"Lista: ";
    lista.printar();
    cout<<"Lista2: ";
    lista2.printar();
    
    Lista lista3 = lista;
    
    lista3.push_front(999);
    
    lista3.printar();
    lista.printar();
    lista2.printar();
    
    
    return 0;
}