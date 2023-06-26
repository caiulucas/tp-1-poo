#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "funcionario.h"
#include "venda.h"

using namespace std;

class Vendedor : public Funcionario
{

private:
  vector<Venda> vendas;

public:
  Vendedor(string nome = "", string nome_usuario = "", string senha = "", string tipo = "", string funcao = "", double = 0.0);
  virtual ~Vendedor();

  vector<Venda> get_vendas() const;
  void set_vendas(vector<Venda> vendas);
};