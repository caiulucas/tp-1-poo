#include "supervisor.h"
#include "../utils/consts.h"

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

vector<Venda *> Supervisor::getVendas() const
{
  vector<Venda *> vendas;

  for (Vendedor v : this->vendedores)
  {
    vector<Venda *> vendasVendedor = v.getVendas();

    for (Venda *venda : vendasVendedor)
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
  int mes = data.getMes();
  int ano = data.getAno();
  double horas = 0.0;

  for (Ponto p : this->getPontos())
  {
    int mesPonto = p.getData().getMes();
    int anoPonto = p.getData().getAno();

    if (mes == mesPonto && ano == anoPonto)
    {
      double horasDia = p.getHorasTrabalhadas();

      if(horasDia > MAX_HORAS_NORMAIS)
        horas += MAX_HORAS_NORMAIS + (horasDia - MAX_HORAS_NORMAIS) * HORA_EXTRA_SUPERVISOR;
      else
        horas += horasDia;
    }
  }

  return this->getSalarioHora() * horas;
}

double Supervisor::getSalarioFinal(Data data) const
{
  return this->getSalarioMes(data) + this->getBonificacao(data);
}

void Supervisor::addVenda(Venda *venda)
{
  throw "Supervisor não pode adicionar vendas";
}

ostream &operator<<(ostream &out, const Supervisor &obj)
{
  out << "\t\x1b[1mNome:\x1b[0m" << obj.getNome() << endl
      << "\t\x1b[1mUsuário:\x1b[0m " << obj.getNomeUsuario() << endl
      << "\t\x1b[1mFunção:\x1b[0m " << obj.getFuncao()
      << "\t\x1b[1mTipo:\x1b[0m Supervisor"
      << "\t\x1b[1mSalário por hora:\x1b[0m " << obj.getSalarioHora();

  return out;
}