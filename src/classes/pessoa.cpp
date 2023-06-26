#include "pessoa.h"

using namespace std;

Pessoa::Pessoa(string nome)
{
  this->nome = nome;
}

string Pessoa::getNome() const
{
  return this->nome;
}

void Pessoa::setNome(string nome)
{
  this->nome = nome;
}

ostream &operator<<(ostream &out, const Pessoa &obj)
{
  out << "\x1b[1m\x1b[34mNome:\x1b[0m " << obj.getNome();
  return out;
}
