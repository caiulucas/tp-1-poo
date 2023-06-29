#include "supervisor.h"

Supervisor::Supervisor(string nome, string nomeUsuario, string senha, string funcao, double salario)
    : Funcionario(nome, nomeUsuario, senha, funcao, salario) {}

vector<Vendedor> Supervisor::getVendedores() const
{
  return this->vendedores;
}

void Supervisor::addVendedor(Vendedor vendedor)
{
  this->vendedores.push_back(vendedor);
}

vector<Venda> Supervisor::getVendas() const
{
  vector<Venda> vendas;

  for (Vendedor v : this->vendedores)
  {
    vector<Venda> vendasVendedor = v.getVendas();

    for (Venda venda : vendasVendedor)
      vendas.push_back(venda);
  }

  return vendas;
}

double Supervisor::getBonificacao(Data data) const
{
  double bonificacao = 0.0;

  for (Vendedor v : this->vendedores)
    bonificacao += v.getValorVendas(data) * 0.01;

  return bonificacao;
}

double Supervisor::getSalarioMes(Data data) const
{
  double salario = 0.0;

  for (Vendedor v : this->vendedores)
    salario += v.getSalarioMes(data);

  return salario;
}

double Supervisor::getSalarioFinal(Data data) const
{
  return this->getSalarioMes(data) + this->getBonificacao(data);
}

ostream &operator<<(ostream &out, const Supervisor &obj)
{
  out << "\x1b[1mNome:\x1b[0m" << obj.getNome() << endl
      << "\t"
      << "\x1b[1mUsuário:\x1b[0m " << obj.getNomeUsuario() << endl
      << "\t"
      << "\x1b[1mFunção:\x1b[0m " << obj.getFuncao()
      << "\t"
      << "\x1b[1mTipo:\x1b[0m Supervisor"
      << "\x1b[1mSalário por hora:\x1b[0m " << obj.getSalarioHora();

  return out;
}