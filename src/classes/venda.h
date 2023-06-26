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

  double get_valor() const;
  void set_valor(double valor);

  Data get_data() const;
  void set_data(Data data);

  friend ostream &operator<<(ostream &os, const Venda &venda);
};