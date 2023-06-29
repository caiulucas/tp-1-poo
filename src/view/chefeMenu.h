#pragma once

#include "../classes/chefe.h"

using namespace std;

class ChefeMenu
{
private:
  Chefe *chefe;

  void addFuncionario();
  void listarFuncionarios();
  void checarPontoFuncionario();
  void calcularSalarioFuncionario();

public:
  ChefeMenu(Chefe *chefe);

  ~ChefeMenu();

  void menu();
};