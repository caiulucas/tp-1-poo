#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "funcionario.h"
#include "vendedor.h"

using namespace std;

class Supervisor : public Funcionario
{

private:
  vector<Vendedor> vendedores;

public:
  Supervisor(string nome = "", string nomeUsuario = "", string senha = "", string funcao = "", double = 0.0);

  double getBonificacao(Data data) const override;
  double getSalarioMes(Data data) const override;
  double getSalarioFinal(Data data) const override;
  vector<Venda> getVendas() const override;

  vector<Vendedor> getVendedores() const;
  void addVendedor(Vendedor vendedor);

  friend ostream &operator<<(ostream &out, const Supervisor &supervisor);
};