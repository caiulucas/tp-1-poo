
#include <iostream>
#include "funcionario.h"

using namespace std;

Funcionario::Funcionario(string nome, string nome_usuario, string senha, string tipo, string funcao, double salario_hora)
    : Pessoa(nome, nome_usuario, senha)
{
  this->tipo = tipo;
  this->funcao = funcao;
  this->salario_hora = salario_hora;
}

Funcionario::~Funcionario()
{
}

void Funcionario::set_tipo(string tipo)
{
  this->tipo = tipo;
}

string Funcionario::get_tipo() const
{
  return this->tipo;
}

void Funcionario::set_funcao(string funcao)
{
  this->funcao = funcao;
}

string Funcionario::get_funcao() const
{
  return this->funcao;
}

void Funcionario::set_salario_hora(double salario_hora)
{
  this->salario_hora = salario_hora;
}

double Funcionario::get_salario_hora() const
{
  return this->salario_hora;
}

double Funcionario::calcular_horas_semana()
{
  return 0.0;
}

double Funcionario::calcular_horas_mes()
{
  return 0.0;
}

double Funcionario::calcular_salario()
{
  return 0.0;
}

void Funcionario::mostrar_salario()
{
}

void Funcionario::mostrar_vendas()
{
}

ostream &operator<<(ostream &out, const Funcionario &obj)
{
  out << "\x1b[1m\x1b[34m" << obj.get_nome() << "\x1b[0m" << endl
      << "\t"
      << "\x1b[1mUsuário:\x1b[0m " << obj.get_nome_usuario() << endl
      << "\t"
      << "\x1b[1mTipo de funcionário:\x1b[0m " << obj.get_tipo() << endl
      << "\t"
      << "\x1b[1mFunção:\x1b[0m " << obj.get_funcao();
  return out;
}