#ifndef LISTA_H
#define LISTA_H
struct Nodo
{
    int dado;
    Nodo *proximo;
};


class Lista
{
public:
    Lista();
    Lista(const int&);
    
    Lista(const Lista&);
    ~Lista();
    Lista& operator=(const Lista&);
    
    
    void push_back(const int&);
    void push_front(const int&);
    void insert(const int&, const int&);
    
    
    
    void clear();
    
    void printar();
protected:
    Nodo *cabeca;
    Nodo *calda;

    void copia(const Lista&);
};

#endif