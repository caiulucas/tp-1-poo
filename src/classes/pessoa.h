#pragma once

#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
private:
  string nome;

public:
  Pessoa(string = "");

  virtual ~Pessoa();

  void setNome(string nome);
  string getNome() const;

  friend ostream &operator<<(ostream, const Pessoa &);
};