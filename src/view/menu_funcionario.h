#pragma once

#include <iostream>
#include "../classes/funcionario.h"

using namespace std;

class MenuFuncionario
{
private:
  Funcionario *funcionario;

  void addPonto();
  void mostrarSalario();
  void listarVendas();

public:
  MenuFuncionario(Funcionario *funcionario);

  void menu();
};