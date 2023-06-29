#include <iostream>
#include "view/menu.h"

using namespace std;

int main()
{
  Menu *menu = new Menu();

  menu->menuPrincipal();

  delete menu;

  return EXIT_SUCCESS;
}