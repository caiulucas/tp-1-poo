#pragma once

#include <string>
#include <vector>
#include "funcionario.h"

using namespace std;

class Chefe : public Pessoa
{
  double salario_fixo;
  vector<Funcionario> funcionarios;

public:
  Chefe(double salario_fixo = 0.0);

  virtual ~Chefe();

  double get_salario_fixo() const;
  void set_salario_fixo(double salario_fixo);
};