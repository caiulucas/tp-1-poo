#include "vendedor.h"

Vendedor::Vendedor(string nome, string nome_usuario, string senha, string funcao, double salario)
    : Funcionario(nome, nome_usuario, senha, funcao, salario) {}

vector<Venda> Vendedor::getVendas() const
{
  return this->vendas;
}

void Vendedor::setVendas(vector<Venda> vendas)
{
  this->vendas = vendas;
}
