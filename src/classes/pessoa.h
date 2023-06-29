#pragma once

#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
private:
  string nome;
  string nomeUsuario;
  string senha;

public:
  Pessoa(string nome = "", string nomeUsuario = "", string senha = "");

  virtual ~Pessoa();

  string getNome() const;
  void setNome(string nome);

  void setNomeUsuario(string nomeUsuario);
  string getNomeUsuario() const;

  void setSenha(string senha);
  string getSenha() const;

  friend ostream &operator<<(ostream, const Pessoa &);
};