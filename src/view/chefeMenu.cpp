#include <ios>
#include <limits>

#include "chefeMenu.h"
#include "../classes/funcionario.h"
#include "../classes/vendedor.h"

using namespace std;

ChefeMenu::ChefeMenu()
{
  this->chefe = Chefe();
}

void ChefeMenu::addFuncionario()
{
  string nome, nomeUsuario, senha, tipo, funcao;
  double salario;

  cout << "\x1b[1m\x1b[34mNome:\x1b[0m ";
  cin >> nome;
  cout << "\x1b[1m\x1b[34mNome de usuário:\x1b[0m ";
  cin >> nomeUsuario;
  cout << "\x1b[1m\x1b[34mSenha:\x1b[0m ";
  cin >> senha;
  cout << "\x1b[1m\x1b[34mTipo:\x1b[0m ";
  cin >> tipo;
  cout << "\x1b[1m\x1b[34mFunção:\x1b[0m ";
  cin >> funcao;
  cout << "\x1b[1m\x1b[34mSalário:\x1b[0m ";
  cin >> salario;

  Funcionario *funcionario;
  if (tipo == "Vendedor")
    funcionario = new Vendedor(nome, nomeUsuario, senha, funcao, salario);

  this->chefe.addFuncionario(*funcionario);
  cout << "\x1B[2J\x1B[H";
}

void ChefeMenu::listarFuncionarios()
{
  cout << "\x1B[2J\x1B[H";
  cout << "\x1b[1m\x1b[34mFuncionários:\x1b[0m" << endl;

  for (Funcionario funcionario : this->chefe.getFuncionarios())
    cout << funcionario << endl;
}

void ChefeMenu::menu()
{
  int opcao;

  do
  {
    cout << "\x1b[1m\x1b[34mMenu do Chefe:\x1b[0m" << endl;
    cout << "\x1b[1m\x1b[34m1.\x1b[0m Adicionar funcionário" << endl;
    cout << "\x1b[1m\x1b[34m2.\x1b[0m Listar funcionários" << endl;
    cout << "\x1b[1m\x1b[34m3.\x1b[0m Checar ponto de funcionário" << endl;
    cout << "\x1b[1m\x1b[34m4.\x1b[0m Calcular salário de funcionário" << endl;
    cout << "\x1b[1m\x1b[34m5.\x1b[0m Sair" << endl;
    cout << "\x1b[1m\x1b[34mOpção:\x1b[0m ";
    cin >> opcao;

    switch (opcao)
    {
    case 1:
      this->addFuncionario();
      break;
    case 2:
      this->listarFuncionarios();
      cout << "\x1b[1m\x1b[34mPressione qualquer tecla para continuar...\x1b[0m" << endl;
      cin.get();
      break;
    default:
      cout << "\x1b[1m\x1b[31mOpção inválida!\x1b[0m" << endl;
      break;
    }
  } while (opcao != 3);
}