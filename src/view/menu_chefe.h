#pragma once

#include "../classes/chefe.h"

using namespace std;

class MenuChefe
{
private:
  Chefe *chefe;

  void addFuncionario();
  void listarFuncionarios();
  void checarPontoFuncionario();
  void calcularSalarioFuncionario();

public:
  MenuChefe(Chefe *chefe);

  ~MenuChefe();

  void menu();
};