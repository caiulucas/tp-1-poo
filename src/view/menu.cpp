#include "menu.h"
#include "menu_chefe.h"
#include "menu_funcionario.h"

void Menu::menuPrincipal()
{
  Chefe *chefe = new Chefe(10000);
  int opcao;
  while (true)
  {
    cout << "\x1B[2J\x1B[H";
    cout << "\x1b[1m\x1b[34mBem vindo ao sistema de gerenciamento de funcionarios\x1b[0m" << endl;
    cout << "\x1b[1m\x1b[34mEscolha uma opcao:\x1b[0m" << endl;
    cout << "\x1b[1m\x1b[34m1.\x1b[0m Login" << endl;
    cout << "\x1b[1m\x1b[34m2.\x1b[0m Sair" << endl;
    cout << "\x1b[1m\x1b[34mOpção:\x1b[0m ";
    cin >> opcao;

    string nomeUsuario, senha;

    switch (opcao)
    {
    case 1:
      cout << "\x1b[1m\x1b[34mNome de usuário:\x1b[0m ";
      cin >> nomeUsuario;
      cout << "\x1b[1m\x1b[34mSenha:\x1b[0m ";
      cin >> senha;

      if (nomeUsuario == "admin" && senha == "admin")
      {
        cout << "\x1B[2J\x1B[H";
        MenuChefe *menuChefe = new MenuChefe(chefe);
        menuChefe->menu();
      }
      else
      {
        for (auto f : chefe->getFuncionarios())
        {
          if (f->getNomeUsuario() == nomeUsuario && f->getSenha() == senha)
          {
            cout << "\x1B[2J\x1B[H";
            MenuFuncionario *menuFuncionario = new MenuFuncionario(f);
            menuFuncionario->menu();
            break;
          }
        }
      }
      break;
    case 2:
      return;
    default:
      cout << "\x1b[1m\x1b[31mOpção inválida!\x1b[0m" << endl;
      break;
    }
  }
}