#include <ios>
#include <limits>

#include "menu_chefe.h"
#include "../classes/funcionario.h"
#include "../classes/vendedor.h"
#include "../classes/supervisor.h"

using namespace std;

MenuChefe::MenuChefe(Chefe *chefe)
{
  this->chefe = chefe;
}

MenuChefe::~MenuChefe()
{
  for (auto funcionario : this->chefe->getFuncionarios())
    delete funcionario;
}

void MenuChefe::addFuncionario()
{
  string nome, nomeUsuario, senha, tipo, funcao, usuarioSupervisor;
  double salario;

  cout << "\x1b[1m\x1b[34mNome:\x1b[0m ";
  getline(cin >> ws, nome);
  cout << "\x1b[1m\x1b[34mNome de usuário:\x1b[0m ";
  cin >> nomeUsuario;
  cout << "\x1b[1m\x1b[34mSenha:\x1b[0m ";
  cin >> senha;

  while (tipo != "Vendedor" && tipo != "Supervisor")
  {
    cout << "\x1b[1m\x1b[34mTipo:\x1b[0m ";
    cin >> tipo;

    if (tipo != "Vendedor" && tipo != "Supervisor")
      cout << "\x1b[1m\x1b[31mTipo inválido!\x1b[0m" << endl;
  }

  if (tipo == "Vendedor")
  {
    cout << "\x1b[1m\x1b[34mUsuário do supervisor:\x1b[0m ";
    cin >> usuarioSupervisor;
  }

  cout << "\x1b[1m\x1b[34mFunção:\x1b[0m ";
  getline(cin >> ws, funcao);
  cout << "\x1b[1m\x1b[34mSalário:\x1b[0m ";
  cin >> salario;

  Funcionario *funcionario;

  if (tipo == "Vendedor")
  {
    Supervisor *supervisor = (Supervisor *)chefe->getFuncionarioPorUsuario(usuarioSupervisor);

    funcionario = new Vendedor(nome, nomeUsuario, senha, funcao, salario);
    supervisor->addVendedor((Vendedor *)funcionario);
  }
  else
    funcionario = new Supervisor(nome, nomeUsuario, senha, funcao, salario);

  this->chefe->addFuncionario(funcionario);
  cout << "\x1B[2J\x1B[H";
}

void MenuChefe::listarFuncionarios()
{
  cout << "\x1B[2J\x1B[H";
  cout << "\x1b[1m\x1b[34mFuncionários:\x1b[0m" << endl;

  for (auto funcionario : this->chefe->getFuncionarios())
    cout << *funcionario << endl;
}

void MenuChefe::menu()
{
  int opcao;

  do
  {
    cout << "\x1B[2J\x1B[H"
         << "\x1b[1m\x1b[34mMenu do Chefe:\x1b[0m" << endl
         << "\x1b[1m\x1b[34m1.\x1b[0m Adicionar funcionário" << endl
         << "\x1b[1m\x1b[34m2.\x1b[0m Listar funcionários" << endl
         << "\x1b[1m\x1b[34m3.\x1b[0m Checar ponto de funcionário" << endl
         << "\x1b[1m\x1b[34m4.\x1b[0m Calcular salário de funcionário" << endl
         << "\x1b[1m\x1b[34m5.\x1b[0m Sair" << endl
         << "\x1b[1m\x1b[34mOpção:\x1b[0m ";
    cin >> opcao;

    switch (opcao)
    {
    case 1:
      this->addFuncionario();
      break;
    case 2:
      this->listarFuncionarios();
      cout << "\x1b[1m\x1b[34mPressione ENTER para continuar...\x1b[0m" << endl;
      break;
    default:
      cout << "\x1b[1m\x1b[31mOpção inválida!\x1b[0m" << endl;
      break;
    }
    cin.ignore();
    
  } while (opcao != 5);
}