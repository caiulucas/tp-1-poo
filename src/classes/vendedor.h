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
  Vendedor(string nome = "", string nomeUsuario = "", string senha = "", string funcao = "", double = 0.0);

  vector<Venda> getVendas() const;
  void setVendas(vector<Venda> vendas);
};