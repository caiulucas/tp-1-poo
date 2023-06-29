
#include <iostream>
#include "funcionario.h"

using namespace std;

Funcionario::Funcionario(string nome, string usuario, string senha,
                         string funcao, double salarioHora)
    : Pessoa(nome, usuario, senha)
{
  this->tipo = tipo;
  this->funcao = funcao;
  this->salarioHora = salarioHora;
}

Funcionario::~Funcionario()
{
}

void Funcionario::setTipo(string tipo)
{
  this->tipo = tipo;
}

string Funcionario::getTipo() const
{
  return this->tipo;
}

void Funcionario::setFuncao(string funcao)
{
  this->funcao = funcao;
}

string Funcionario::getFuncao() const
{
  return this->funcao;
}

void Funcionario::setSalarioHora(double salarioHora)
{
  this->salarioHora = salarioHora;
}

double Funcionario::getSalarioHora() const
{
  return this->salarioHora;
}

double Funcionario::getHorasSemana(Data data) const
{
  int semana = data.getSemana();
  double horas = 0.0;

  for (Ponto p : this->pontos)
  {
    int semanaPonto = p.getData().getSemana();

    if (semana == semanaPonto)
    {
      horas += p.getHorasTrabalhadas();
    }
  }

  return horas;
}

double Funcionario::getHorasMes(Data data)
{
  int mes = data.getMes();
  int ano = data.getAno();
  double horas = 0.0;

  for (Ponto p : this->pontos)
  {
    int mesPonto = p.getData().getMes();
    int anoPonto = p.getData().getAno();

    if (mes == mesPonto && ano == anoPonto)
    {
      horas += p.getHorasTrabalhadas();
    }
  }

  return horas;
}

vector<Ponto> Funcionario::getPontos() const
{
  return this->pontos;
}

void Funcionario::addPonto(Ponto ponto)
{
  this->pontos.push_back(ponto);
}

ostream &operator<<(ostream &out, const Funcionario &obj)
{
  out << "\x1b[1mNome:\x1b[0m" << obj.getNome() << endl
      << "\t"
      << "\x1b[1mUsuário:\x1b[0m " << obj.getNomeUsuario() << endl
      << "\t"
      << "\x1b[1mFunção:\x1b[0m " << obj.getFuncao();
  return out;
}