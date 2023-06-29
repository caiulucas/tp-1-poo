#include "vendedor.h"
#include "../utils/consts.h"

Vendedor::Vendedor(string nome, string nome_usuario, string senha, string funcao, double salario)
    : Funcionario(nome, nome_usuario, senha, funcao, salario) {}

vector<Venda *> Vendedor::getVendas() const
{
  return this->vendas;
}

void Vendedor::addVenda(Venda *venda)
{
  this->vendas.push_back(venda);
}

double Vendedor::getValorVendas(Data data) const
{
  double valor = 0.0;

  for (Venda *v : this->vendas)
  {
    int mesVenda = v->getData().getMes();
    int anoVenda = v->getData().getAno();

    if (data.getMes() == mesVenda && data.getAno() == anoVenda)
      valor += v->getValor();
  }

  return valor;
}

double Vendedor::getSalarioMes(Data data) const
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

      if (horasDia > MAX_HORAS_NORMAIS)
        horas += MAX_HORAS_NORMAIS + (horasDia - MAX_HORAS_NORMAIS) * HORA_EXTRA_VENDEDOR;
      else
        horas += horasDia;
    }
  }
  return this->getSalarioHora() * horas;
}

double Vendedor::getBonificacao(Data data) const
{
  double bonificacao = 0.0;
  bonificacao = this->getValorVendas(data) * 0.10;
  return bonificacao;
}

double Vendedor::getSalarioFinal(Data data) const
{
  double salario = 0.0;
  salario = this->getSalarioMes(data) + this->getBonificacao(data);
  return salario;
}

ostream &operator<<(ostream &out, const Vendedor &obj)
{
  out << "\t\x1b[1mNome:\x1b[0m" << obj.getNome() << endl
      << "\t\x1b[1mUsuário:\x1b[0m " << obj.getNomeUsuario() << endl
      << "\t\x1b[1mFunção:\x1b[0m " << obj.getFuncao()
      << "\t\x1b[1mTipo:\x1b[0m Vendedor"
      << "\t\x1b[1mSalário por hora:\x1b[0m " << obj.getSalarioHora();

  return out;
}