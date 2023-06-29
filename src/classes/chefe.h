#pragma once

#include <string>
#include <vector>
#include "funcionario.h"

using namespace std;

class Chefe : public Pessoa
{
  double salario;
  vector<Funcionario*> funcionarios;

public:
  Chefe(double salario = 0.0);

  double getSalario() const;
  void setSalario(double salario);

  vector<Funcionario*> getFuncionarios() const;
  void addFuncionario(Funcionario *funcionario);
  void removeFuncionario(string nome);

  friend ostream &operator<<(ostream &out, const Chefe &obj);
};