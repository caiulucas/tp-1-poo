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

  vector<Venda> getVendas() const override;
  void addVenda(Venda venda);

  double getSalarioMes(Data data) const override;
  double getBonificacao(Data data) const override;
  double getSalarioFinal(Data data) const override;
  double getValorVendas(Data data) const;

  friend ostream &operator<<(ostream &out, const Vendedor &obj);
};