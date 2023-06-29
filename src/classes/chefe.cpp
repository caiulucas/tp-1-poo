#include "chefe.h"

using namespace std;

Chefe::Chefe(double salario)
    : Pessoa("Chefe", "admin", "admin")
{
  this->salario = salario;
}

double Chefe::getSalario() const
{
  return this->salario;
}

void Chefe::setSalario(double salario)
{
  this->salario = salario;
}

Funcionario *Chefe::getFuncionarioPorUsuario(string nomeUsuario)
{
  for (Funcionario *f : this->getFuncionarios())
  {
    if (f->getNomeUsuario() == nomeUsuario)
      return f;
  }

  return nullptr;
};

vector<Funcionario *> Chefe::getFuncionarios() const
{
  return this->funcionarios;
}

void Chefe::addFuncionario(Funcionario *funcionario)
{
  this->funcionarios.push_back(funcionario);
}

ostream &operator<<(ostream &out, const Chefe &obj)
{
  out << "\x1b[1m\x1b[34mNome:\x1b[0m " << obj.getNome() << endl;
  out << "\x1b[1m\x1b[34mNome de usuário:\x1b[0m " << obj.getNomeUsuario() << endl;
  out << "\x1b[1m\x1b[34mSalário:\x1b[0m " << obj.getSalario() << endl;
  return out;
}