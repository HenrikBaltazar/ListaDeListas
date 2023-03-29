#include <iostream>
#include "ListaDeListas.h"

using namespace std;

int main()
{
    int opcao, posicao;
    string nomealuno, nomemateria;
    bool achou = false;
    ListaDeListas<string> ListaAlunos, ListaQuantidadeDeMaterias;

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
            cout << "Qual posição deseja inserir " << nomealuno << ": ";
            cin >> posicao;
            if (ehvazia(ListaAlunos == true))
            {
                cria(ListaAlunos)
                insere(ListaAlunos, nomealuno, posicao);
            }
            else
                insere(ListaAlunos, nomealuno, posicao);
            getchar();
            system("clear");
            break;
        case 2:
            cout << "Qual o nome do aluno que deseja inserir a materia?: ";
            cin >> nomealuno;
            // eh vazia
            achou = existeelemento(ListaAluno, nomealuno);
            if (achou == false)
                cout << "Aluno não encontrado" << endl;
            else
                cout << "Qual materia deseja inserir?: ";
            cin >> nomemateria;
            cout << "Qual posição deseja inserir " << nomemateria << ": ";
            cin >> posicao;
            insere(ListaMaterias, nomemateria, posicao);
            getchar();
            system("clear");
            break;
        case 3:
            cout << "Qual o nome deseja excluir?: ";
            cin >> nomealuno;
            removealuno(ListaAluno, nomealuno);

            getchar();
            system("clear");
            break;
        case 4:
            cout << "Qual aluno deseja que a materia seja removida?: ";
            cin >> nomealuno;

            achou = existeelemento(ListaAluno, nomealuno);
            if (achou == false)
                cout << "Aluno não encontrado" << endl;
            else
                exibemateriasaluno(ListaAluno);
            cout << endl;
            cout << "Qual materia deseja remover?: ";
            cin >> nomemateria;
            removemateria(ListaAluno, nomemateria);
            getchar();
            system("clear");
            break;
        case 5:
            exibeAlunosMaterias(ListaAlunos);
            getchar();
            system("clear");
            break;
        case 6:
            cout << "Qual aluno deseja que as materias sejam exibidas?: ";
            cin >> nomealuno;

            achou = existeelemento(ListaAluno, nomealuno);
            if (achou == false)
                cout << "Aluno não encontrado" << endl;
            else
                exibematerias(ListaAlunos, nomealuno);
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