#include "menu.h"
#include "chefeMenu.h"

void Menu::menuPrincipal()
{
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
      ChefeMenu chefeMenu;
      chefeMenu.menu();
      break;
    }
  } while (opcao != 2);
}