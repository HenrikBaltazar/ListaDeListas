#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template<typename T>
struct nodo
{
	T valor;
	nodo* proximoNodo;
};

template<typename T>
struct Lista
{
	T valor;
	nodo<T>* proximoNodo;
	Lista* proximaLista;
	int n;
};

template<typename T>
void criaLista(Lista<T> &lista, string nome)
{
	lista.valor = nome;
	lista.proximoNodo = NULL;
	lista.proximaLista = NULL;
	lista.n = 0;
}

template<typename T>
void destroiLista(Lista<T>& lista)
{
	Lista<string>* aux = &lista;
	nodo<string>* auxn;
	while (aux != NULL)
	{
		auxn = aux->proximoNodo;
		while (auxn != NULL)
		{
			aux->proximoNodo = auxn->proximoNodo;
			delete auxn;
			auxn = aux->proximoNodo;
		}
		aux = lista.proximaLista;
		lista.proximaLista = aux->proximaLista;
		delete aux;
		aux = lista.proximaLista;
	}
}

template<typename T>
bool estaVazia(Lista<T> lista)
{
	if (lista.n == 0)
		return true;
	else
		return false;
}

template<typename T>
int numeroElementos(Lista<T> lista)
{
	Lista<string> *aux;
	int n = 1;
	aux = lista.proximaLista;
	while (aux != NULL)
	{
		aux = aux->proximaLista;
		n += 1;
	}
	return n;
}

template<typename T>
int elementosAssociados(Lista<T> lista, string valor)
{
	if (lista.valor == valor)
		return lista.n;
	Lista<string>* aux = lista.proximaLista;
	while (aux != NULL and aux->valor != valor)
		aux = aux->proximaLista;
	if (aux != NULL)
		return aux->n;
	else
	{
		cout << "elemento nao encontrado" << endl;
		return;
	}
}

template<typename T>
bool existeNaLista(Lista<T> lista, string valor)
{
	if (lista.valor == valor)
		return true;
	Lista<string>* aux = lista.proximaLista;
	while (aux != NULL and aux->valor != valor)
		aux = aux->proximaLista;
	if (aux != NULL)
		return true;
	return false;
}

template<typename T>
bool existeAssociado(Lista<T> lista, string valor, string valorAssociado)
{
	Lista<string>* aux = &lista;
	while (aux != NULL and aux->valor != valor)
		aux = aux->proximaLista;
	if (aux == NULL)
	{
		cout << "elemento nao encontrado" << endl;
		return false;
	}
	nodo<string>* naux = aux->proximoNodo;
	while (naux != NULL and naux->valor == valorAssociado)
		naux = naux->proximoNodo;
	if (naux == NULL)
	{
		cout << "elemento associado nao encontrado" << endl;
		return false;
	}
	return true;
}


#endif // LISTA_H_INCLUDED
