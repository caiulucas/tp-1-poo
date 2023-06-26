#pragma once

#include <iostream>
#include <string>

using namespace std;

class Data
{
private:
  int dia;
  int mes;
  int ano;

public:
  Data(int dia = 1, int mes = 1, int ano = 2023);
  virtual ~Data();

  int get_dia() const;
  void set_dia(int dia);

  int get_mes() const;
  void set_mes(int mes);

  int get_ano() const;
  void set_ano(int ano);

  friend ostream &operator<<(ostream &os, const Data &data);
};