#pragma once

#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
private:
  string nome;
  string nome_usuario;
  string senha;

public:
  Pessoa(string = "");

  virtual ~Pessoa();

  string get_nome() const;
  void set_nome(string nome);

  void set_nome_usuario(string nome_usuario);
  string get_nome_usuario() const;

  void set_senha(string senha);
  string get_senha() const;

  friend ostream &operator<<(ostream, const Pessoa &);
};