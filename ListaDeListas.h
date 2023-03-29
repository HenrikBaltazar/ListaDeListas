#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>

using namespace std;

template <typename T>
struct Nodo
{
	T valorNodo;
	Nodo<T> *proximoNodo;
};

template <typename T>
struct Lista
{
	T valorLista;
	Nodo<T> *inicio;
	Lista<T> *proximaLista;
	int cardinalidadeNodos;
};

template <typename T>
struct ListaDeListas
{
	Lista<T> *inicioLista;
	int cardinalidadeListas;
};

template <typename T>
void criaListaDeListas(ListaDeListas<T> &listaDeListas)
{
	listaDeListas.inicioLista = NULL;
	listaDeListas.cardinalidadeListas = 0;
}

template <typename T>
void insereLista(ListaDeListas<T> &listaDeListas, T valor, int posicao)
{
	if(posicao < 1 || posicao > listaDeListas.cardinalidadeListas +1)
		throw "POSICAO INVALIDA";
	Lista<T>* q = new Lista<T>;
	q->valorLista = valor;
	q->proximaLista = NULL;
	if(listaDeListas.inicioLista == NULL) //Lista esta vazia
		listaDeListas.inicioLista = q;
	else{                 //Lista nao esta vazia
		if (posicao == 1) //vai inserir no primeiro da lista
		{
			q->proximaLista = listaDeListas.inicioLista; //o proximo do novo elemento sera o antigo primeiro
			listaDeListas.inicioLista = q; //agora o novo elemento eh o primeiro
		}
		else{ // nao eh no primeiro
			Lista<T>* p = listaDeListas.inicioLista;
			int contador = 1;
			while (contador!=posicao -1){ //leva o ponteiro ate o nodo anterior para atualizar o seu proximo
				p = p->proximaLista;
				contador++;
			}
			q->proximaLista = p->proximaLista; //o novo nodo recebe a referencia de proximo do nodo anterior
			p->proximaLista = q; //o nodo anterior recebe a referencia do novo nodo
		}
	}
	listaDeListas.cardinalidadeListas++;
}

template <typename T>
void insereNodo(Lista<T> &lista, T valor, int posicao)
{
	if(posicao < 1 || posicao > l1.cardinal +1)
		throw "POSICAO INVALIDA";
	Nodo<T>* q = new Nodo<T>;
	q->valorNodo = valor;
	q->proximoNodo = NULL;
	if(lista.inicio == NULL) //Lista esta vazia
		lista.inicio = q;
	else{                 //Lista nao esta vazia
		if (posicao == 1) //vai inserir no primeiro da lista
		{
			q->proximoNodo = lista.inicio; //o proximo do novo elemento sera o antigo primeiro
			lista.inicio = q; //agora o elemento eh o primeiro
		}
		else{ //nao eh no primeiro
			Nodo<T>* p = lista.inicio;
			int contador = 1;
			while (contador!=posicao -1){ //leva o ponteiro ate o nodo anterior para atualizar o seu proximo
				p = p->proximoNodo;
				contador++;
			}
			q->proximoNodo = p->proximoNodo; //o novo nodo recebe a referencia de proximo do nodo anterior
			p->proximoNodo = q; //o nodo anterior recebe a referencia do novo nodo
		}
	}
	lista.cardinalidadeNodos++;
}

template<typename T>
void destroiListaDeListas(ListaDeListas<T> &listaDeListas)
{
	Lista<T>* auxLista = listaDeListas.inicioLista;
	Nodo<T>* auxNodo;
	while (auxLista != NULL)
	{
		auxNodo = auxLista->inicio;
		while (auxNodo != NULL)
		{
			auxLista->inicio = auxNodo->proximoNodo;
			delete auxNodo;
			auxNodo = auxLista->inicio;
		}
		listaDeListas.inicioLista = auxLista->proximaLista;
		delete auxLista;
		auxLista = listaDelistas.inicioLista;
	}
	listaDeListas.cardinalidadeListas = 0;
}

template <typename T>
bool existeLista(ListaDeListas<T> ListaDeListas, T valor){
	Lista<T> *p = ListaDeListas.inicioLista;
	while( p != NULL){
		if(p.valorLista == valor)
			return true;
		p = p->proximaLista;
	}
	return false;
}

template <typename T>
bool existeNodo(Lista<T> Lista, T valor){
	Nodo<T> *p = Lista.inicioNodo;
	while( p != NULL){
		if(p.valorNodo == valor)
			return true;
		p = p->proximoNodo;
	}
	return false;
}

template <typename T>
int recuperaQuantidadeLista(ListaDeListas<T> listaDeListas){
	return listaDeListas.cardinalidadeListas;
}

template <typename T>
int recuperaQuantidadeNodos(Lista<T> lista){
	return lista.cardinalidadeNodos;
}

template <typename T>
bool ehVazia (ListaDeListas<T> ListaDeListas)
{
	return (ListaDeListas.cardinalidadeListas == 0);
}

template <typename T>
void mostraListas (ListaDeListas<T> ListaDeListas)
{
	for (Lista<T>* p = ListaDeListas.inicio; p!= NULL; p=p->proximaLista)
		cout << p->valorLista << " ";
	cout << endl;
}

template <typename T>
void mostraListasNodos (ListaDeListas<T> ListaDeListas)
{
	for (Lista<T>* p = ListaDeListas.inicioLista; p!= NULL; p=p->proximaLista){
		cout << p->valorLista << ": ";
		for (Nodo<T>* q = p->inicio; q!= NULL; q=q->proximoNodo)
			cout << q->valorNodo << " ";
		cout << endl;
	}
}

template<typename T>
void removeLista(ListaDeListas<T> &listaDeListas, T lista)
{
	if(listaDeListas.cardinalidadeListas == 0)
		throw "UNDERFLOW"
	if(existeLista(listaDeListas, lista))
        throw "LISTA NAO EXISTE";
	Lista<T>* auxLista = listaDeListas.inicioLista;
	if (auxLista->valorLista == lista)		//primeiro elemento Lista eh a list a ser removida
	{
		Nodo<T> auxNodo = auxLista->inicio;
		while (auxNodo != NULL)
		{
			auxLista->inicio = auxNodo->proximoNodo;
			delete auxNodo;
			auxNodo = auxLista->inicio;
		}
		listaDeListas.inicioLista = auxLista->proximaLista;
		delete auxLista;
		return;
	}
	// nao retornou pois o primeiro elemento nao eh o elemento a ser removido
	Lista<T>* antLista = listaDeListas.inicioLista;
	auxLista = auxLista->proximaLista;
	while (auxLista != NULL and auxLista->valorLista != lista)
	{
		antLista = auxLista;
		auxLista = auxLista->proximaLista;
	}
	Nodo<T> auxNodo = auxLista->inicio;
	while (auxNodo != NULL)
	{
		auxLista->inicio = auxNodo->proximoNodo;
		delete auxNodo;
		auxNodo = auxLista->inicio;
	}
	antLista->proximaLista = auxLista->proximaLista;
	delete auxLista;
}

template<typename T>
void removeNodo(ListaDeListas<T> &listaDeListas, T lista, T nodo){
	Lista<T>* auxLista = listaDeListas.inicioLista;
	if(auxLista.cardinalidadeNodos == 0)
		throw "UNDERFLOW"
	if(existeNodo(auxLista, nodo))
        throw "NODO NAO EXISTE";
	while (auxLista->valorLista != lista)
		auxLista = auxLista->proximaLista;
	Nodo<T>* auxNodo = auxLista->inicio;
	if (auxNodo->valorNodo == nodo)
	{
		auxLista->inicio = auxNodo->proximoNodo;
		delete auxNodo;
		return;
	}
	Nodo<T>* antNodo = auxNodo;
	auxNodo = auxNodo->proximoNodo;
	while (auxNodo->valorNodo != nodo)
	{
		antNodo = auxNodo;
		auxnodo = auxNodo->proximoNodo;
	}
	antNodo->proximoNodo = auxNodo->proximoNodo;
	delete auxNodo;
}

#endif // LISTA_H_INCLUDED
