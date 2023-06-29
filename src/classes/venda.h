#pragma once

#include <iostream>
#include <string>
#include "data.h"

using namespace std;

class Venda
{
private:
  double valor;
  Data data;

public:
  Venda(double valor, Data data);

  virtual ~Venda();

  double getValor() const;
  void setValor(double valor);

  Data getData() const;
  void setData(Data data);

  friend ostream &operator<<(ostream &os, const Venda &venda);
};