#include <iostream>
#include "classes/funcionario.h"
#include "classes/chefe.h"

using namespace std;

int main()
{
  Funcionario *funcionario = new Funcionario("Funcionario", "Funcionario", 0.0);
  Chefe *chefe = new Chefe(0.0);

  cout << funcionario->get_funcao() << endl;
  cout << chefe->get_salario_fixo() << endl;
  return EXIT_SUCCESS;
}