#include "menu.h"
#include "chefeMenu.h"
#include "menu_funcionario.h"

void Menu::menuPrincipal()
{
  Chefe *chefe = new Chefe(10000) ;
  int opcao;
  do
  {
    cout << "Bem vindo ao sistema de gerenciamento de funcionarios" << endl;
    cout << "Escolha uma opcao:" << endl;
    cout << "1 - Login" << endl;
    cout << "2 - Sair" << endl;
    cin >> opcao;
    switch (opcao)
    {
    case 1:
      string nomeUsuario, senha;

      cout << "\x1b[1m\x1b[34mNome de usuário:\x1b[0m ";
      cin >> nomeUsuario;
      cout << "\x1b[1m\x1b[34mSenha:\x1b[0m ";
      cin >> senha;

      if (nomeUsuario == "admin" && senha == "admin")
      {
        cout << "\x1B[2J\x1B[H";
        ChefeMenu *chefeMenu = new ChefeMenu(chefe); 
        chefeMenu->menu();
      }
      else
      {
        for(auto f : chefe->getFuncionarios()) {
          if(f->getNomeUsuario() == nomeUsuario && f->getSenha() == senha) {
            cout << "\x1B[2J\x1B[H";
            MenuFuncionario *menuFuncionario = new MenuFuncionario(f);
            menuFuncionario->menu();
            break;
          }
        }
      }

      break;
    }
  } while (opcao != 2);
}