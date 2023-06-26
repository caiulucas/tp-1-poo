#include "pessoa.h"

using namespace std;

Pessoa::Pessoa(string nome)
{
  this->nome = nome;
}

Pessoa::~Pessoa()
{
}

string Pessoa::get_nome() const
{
  return this->nome;
}

void Pessoa::set_nome(string nome)
{
  this->nome = nome;
}

string Pessoa::get_nome_usuario() const
{
  return this->nome_usuario;
}

void Pessoa::set_nome_usuario(string nome_usuario)
{
  this->nome_usuario = nome_usuario;
}

string Pessoa::get_senha() const
{
  return this->senha;
}

void Pessoa::set_senha(string senha)
{
  this->senha = senha;
}

ostream &operator<<(ostream &out, const Pessoa &obj)
{
  out << "\x1b[1m\x1b[34mNome:\x1b[0m " << obj.get_nome();
  return out;
}
