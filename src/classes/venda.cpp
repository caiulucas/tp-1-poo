#include "venda.h"

Venda::Venda(double valor, Data data)
{
  this->valor = valor;
  this->data = data;
}

Venda::~Venda()
{
}

double Venda::get_valor() const
{
  return this->valor;
}

void Venda::set_valor(double valor)
{
  this->valor = valor;
}

Data Venda::get_data() const
{
  return this->data;
}

void Venda::set_data(Data data)
{
  this->data = data;
}