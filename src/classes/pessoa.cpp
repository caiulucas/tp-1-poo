#include "pessoa.h"

using namespace std;

Pessoa::Pessoa(string nome, string nomeUsuario, string senha)
{
  this->nome = nome;
  this->nomeUsuario = nomeUsuario;
  this->senha = senha;
}

Pessoa::~Pessoa()
{
}

string Pessoa::getNome() const
{
  return this->nome;
}

void Pessoa::setNome(string nome)
{
  this->nome = nome;
}

string Pessoa::getNomeUsuario() const
{
  return this->nomeUsuario;
}

void Pessoa::setNomeUsuario(string nomeUsuario)
{
  this->nomeUsuario = nomeUsuario;
}

string Pessoa::getSenha() const
{
  return this->senha;
}

void Pessoa::setSenha(string senha)
{
  this->senha = senha;
}

ostream &operator<<(ostream &out, const Pessoa &obj)
{
  out << "\x1b[1m\x1b[34mNome:\x1b[0m " << obj.getNome();
  return out;
}
