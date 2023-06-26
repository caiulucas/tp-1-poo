#include <iostream>
#include "classes/funcionario.h"
#include "classes/chefe.h"

using namespace std;

int main()
{
  Funcionario *funcionario = new Funcionario("Camilla", "jacaroa", "123@321", "funcionario", "vendedora", 43242.0);
  // Chefe *chefe = new Chefe(0.0);

  cout << *funcionario << endl;
  // cout << chefe->get_salario_fixo() << endl;
  return EXIT_SUCCESS;
}