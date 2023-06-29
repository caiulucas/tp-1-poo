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

  int getDia() const;
  void setDia(int dia);

  int getMes() const;
  void setMes(int mes);

  int getAno() const;
  void setAno(int ano);

  int getSemana() const;

  friend ostream &operator<<(ostream &os, const Data &data);
};