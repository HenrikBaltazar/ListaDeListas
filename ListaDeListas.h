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

template <typename T, typename T2>
struct Lista
{
	T valorLista;
	Nodo<T2> *inicio;
	Lista<T,T2> *proximaLista;
	int cardinalidadeNodos;
};

template <typename T, typename T2>
struct ListaDeListas
{
	Lista<T,T2> *inicioLista;
	int cardinalidadeListas;
};

template <typename T, typename T2>
void criaListaDeListas(ListaDeListas<T,T2> &listaDeListas)
{
	listaDeListas.inicioLista = NULL;
	listaDeListas.cardinalidadeListas = 0;
}

template <typename T, typename T2>
void insereLista(ListaDeListas<T,T2> &listaDeListas, T valor, int posicao)
{
	if(posicao < 1 || posicao > listaDeListas.cardinalidadeListas +1)
		throw "POSICAO INVALIDA";
	Lista<T,T2>* q = new Lista<T,T2>;
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
			Lista<T,T2>* p = listaDeListas.inicioLista;
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

template <typename T, typename T2>
void insereNodo(ListaDeListas<T,T2> &ListaDeListas, T lista, T valor, int posicao)
{
	if(!existeLista(ListaDeListas, lista))
		throw "LISTA NAO EXISTE";
	Lista<T,T2> auxLista = ListaDeListas.inicioLista;
	while (auxLista->valorLista != lista)
		auxLista = auxLista->proximaLista;
	if(posicao < 1 || posicao > l1.cardinal +1)
		throw "POSICAO INVALIDA";
	Nodo<T>* q = new Nodo<T>;
	q->valorNodo = valor;
	q->proximoNodo = NULL;
	if(auxLista.inicio == NULL) //Lista esta vazia
		auxLista.inicio = q;
	else{                 //Lista nao esta vazia
		if (posicao == 1) //vai inserir no primeiro da lista
		{
			q->proximoNodo = auxLlista.inicio; //o proximo do novo elemento sera o antigo primeiro
			auxLista.inicio = q; //agora o elemento eh o primeiro
		}
		else{ //nao eh no primeiro
			Nodo<T>* p = auxLista.inicio;
			int contador = 1;
			while (contador!=posicao -1){ //leva o ponteiro ate o nodo anterior para atualizar o seu proximo
				p = p->proximoNodo;
				contador++;
			}
			q->proximoNodo = p->proximoNodo; //o novo nodo recebe a referencia de proximo do nodo anterior
			p->proximoNodo = q; //o nodo anterior recebe a referencia do novo nodo
		}
	}
	auxLista.cardinalidadeNodos++;
}

template<typename T, typename T2>
void destroiListaDeListas(ListaDeListas<T,T2> &listaDeListas)
{
	Lista<T,T2>* auxLista = listaDeListas.inicioLista;
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

template <typename T, typename T2>
bool existeLista(ListaDeListas<T,T2> ListaDeListas, T valor){
	Lista<T,T2> *p = ListaDeListas.inicioLista;
	while( p != NULL){
		if(p.valorLista == valor)
			return true;
		p = p->proximaLista;
	}
	return false;
}

template <typename T, typename T2>
bool existeNodo(Lista<T,T2> Lista, T valor){
	Nodo<T> *p = Lista.inicioNodo;
	while( p != NULL){
		if(p.valorNodo == valor)
			return true;
		p = p->proximoNodo;
	}
	return false;
}

template <typename T, typename T2>
int recuperaQuantidadeLista(ListaDeListas<T,T2> listaDeListas){
	return listaDeListas.cardinalidadeListas;
}

template <typename T, typename T2>
int recuperaQuantidadeNodos(ListaDeListas<T,T2> ListaDeListas){
	Lista<T,T2> Lista = ListaDeListas.inicioLista;
	return Lista.cardinalidadeNodos;
}

template <typename T, typename T2>
bool ehVazia (ListaDeListas<T,T2> ListaDeListas)
{
	return (ListaDeListas.cardinalidadeListas == 0);
}

template <typename T, typename T2>
void mostraListas (ListaDeListas<T,T2> ListaDeListas)
{
	for (Lista<T,T2>* p = ListaDeListas.inicio; p!= NULL; p=p->proximaLista)
		cout << p->valorLista << " ";
	cout << endl;
}

template <typename T, typename T2>
void mostraListasNodos (ListaDeListas<T,T2> ListaDeListas)
{
	for (Lista<T,T2>* p = ListaDeListas.inicioLista; p!= NULL; p=p->proximaLista){
		cout << p->valorLista << ": ";
		for (Nodo<T>* q = p->inicio; q!= NULL; q=q->proximoNodo)
			cout << q->valorNodo << " ";
		cout << endl;
	}
}

template<typename T,typename T2>
void removeLista(ListaDeListas<T,T2> &listaDeListas, T lista)
{
	if(listaDeListas.cardinalidadeListas == 0)
		throw "UNDERFLOW"
	if(existeLista(listaDeListas, lista))
        throw "LISTA NAO EXISTE";
	Lista<T,T2>* auxLista = listaDeListas.inicioLista;
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
	Lista<T,T2>* antLista = listaDeListas.inicioLista;
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

template<typename T, typename T2>
void removeNodo(ListaDeListas<T,T2> &listaDeListas, T lista, T nodo){
	Lista<T,T2>* auxLista = listaDeListas.inicioLista;
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
