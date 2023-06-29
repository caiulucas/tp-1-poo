#include "venda.h"

Venda::Venda(double valor, Data data)
{
  this->valor = valor;
  this->data = data;
}

double Venda::getValor() const
{
  return this->valor;
}

void Venda::setValor(double valor)
{
  this->valor = valor;
}

Data Venda::getData() const
{
  return this->data;
}

void Venda::setData(Data data)
{
  this->data = data;
}

ostream &operator<<(ostream &os, const Venda &venda)
{
  os << "\x1b[1mValor:\x1b[0m " << venda.getValor() << endl
     << "\t"
     << "\x1b[1mData:\x1b[0m " << venda.getData() << endl;

  return os;
}