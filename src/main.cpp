#include <iostream>
#include "classes/pessoa.h"

using namespace std;

int main()
{
  Pessoa *pessoa = new Pessoa("vini");

  cout << pessoa->getNome();
  return EXIT_SUCCESS;
}