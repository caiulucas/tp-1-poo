#include "vendedor.h"

Vendedor::Vendedor(string nome, string nome_usuario, string senha, string tipo, string funcao, double salario)
    : Funcionario(nome, nome_usuario, senha, tipo, funcao, salario) {}

Vendedor::~Vendedor() {}

vector<Venda> Vendedor::get_vendas() const
{
  return this->vendas;
}

void Vendedor::set_vendas(vector<Venda> vendas)
{
  this->vendas = vendas;
}
