#include <iostream>
#include "ListaDeListas.h"

using namespace std;

int main()
{
    int opcao, posicao;
    string nomealuno, nomemateria;
    bool achou = false;
    ListaDeListas<string, string> ListaAlunos;

    do
    {
        do
        {
            cout << "         Menu        " << endl;
            cout << "     1 - Insere aluno     " << endl;
            cout << "     2 - Insere materia associada ao aluno     " << endl;
            cout << "     3 - Remover aluno     " << endl;
            cout << "     4 - Remover materia de um aluno     " << endl;
            cout << "     5 - Mostrar todos os alunos e suas materias        " << endl;
            cout << "     6 - Mostrar materias de um aluno    " << endl;
            cout << "     7 - Quantidade de alunos associadas a um aluno    " << endl;
            cout << "     0 - Sair              " << endl;
            cin >> opcao;
            getchar();
        } while (opcao > 7);
        system("clear");
        switch (opcao)
        {
        case 1:
            cout << "Qual o nome deseja inserir?: ";
            cin >> nomealuno;
            cout << "Qual posicao deseja inserir " << nomealuno << ": ";
            cin >> posicao;
            if (ehVazia(ListaAlunos))
            {
                criaListaDeListas(ListaAlunos);
                insereLista(ListaAlunos, nomealuno, posicao);
            }
            else
                insereLista(ListaAlunos, nomealuno, posicao);
            getchar();
            system("clear");
            break;
        case 2:
            cout << "Qual o nome do aluno que deseja inserir a materia?: ";
            cin >> nomealuno;
            // eh vazia
            achou = existeLista(ListaAlunos, nomealuno);
            if (achou == false)
                cout << "Aluno nao encontrado" << endl;
            else
            {
                cout << "Qual materia deseja inserir?: ";
                cin >> nomemateria;
                cout << "Qual posicao deseja inserir " << nomemateria << ": ";
                cin >> posicao;
                insereNodo(ListaAlunos, nomealuno, nomemateria, posicao);
            }
            getchar();
            system("clear");
            break;
        case 3:
            cout << "Qual o nome deseja excluir?: ";
            cin >> nomealuno;
            removeLista(ListaAlunos, nomealuno);
            getchar();
            system("clear");
            break;
        case 4:
            cout << "Qual aluno deseja que a materia seja removida?: ";
            cin >> nomealuno;

            achou = existeLista(ListaAlunos, nomealuno);
            if (achou == false)
                cout << "Aluno nao encontrado" << endl;
            else
            {
                mostraListas(ListaAlunos);
                cout << endl;
                cout << "Qual materia deseja remover?: ";
                cin >> nomemateria;
                removeNodo(ListaAlunos, nomealuno, nomemateria);
            }
            getchar();
            system("clear");
            break;
        case 5:
            mostraListasNodos(ListaAlunos);
            getchar();
            system("clear");
            break;
        case 6:
            cout << "Qual aluno deseja que as materias sejam exibidas?: ";
            cin >> nomealuno;

            achou = existeLista(ListaAlunos, nomealuno);
            if (achou == false)
                cout << "Aluno nao encontrado" << endl;
            else
                mostraNodosDeUmaLista(ListaAlunos, nomealuno);
            getchar();
            system("clear");
            break;
        case 7:
            getchar();
            system("clear");
            break;
        }
    } while (opcao != 0);

    // Destroilista;
    return 0;
}