
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

vector<Ponto*> Funcionario::getPontos() const
{
  return this->pontos;
}

void Funcionario::addPonto(Ponto *ponto)
{
  this->pontos.push_back(ponto);
}

ostream &operator<<(ostream &out, const Funcionario &obj)
{
  out << "\x1b[1mNome:\x1b[0m" << obj.getNome() << endl
      << "\x1b[1mUsuário:\x1b[0m " << obj.getNomeUsuario() << endl
      << "\x1b[1mFunção:\x1b[0m " << obj.getFuncao();
  return out;
}