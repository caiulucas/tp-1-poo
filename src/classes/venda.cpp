#include "venda.h"

Venda::Venda(double valor, Data data)
{
  this->valor = valor;
  this->data = data;
}

Venda::~Venda()
{
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