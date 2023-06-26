#include "data.h"

Data::Data(int dia, int mes, int ano)
{
  this->dia = dia;
  this->mes = mes;
  this->ano = ano;
}

Data::~Data()
{
}

int Data::get_dia() const
{
  return this->dia;
}

void Data::set_dia(int dia)
{
  this->dia = dia;
}

int Data::get_mes() const
{
  return this->mes;
}

void Data::set_mes(int mes)
{
  this->mes = mes;
}

int Data::get_ano() const
{
  return this->ano;
}

void Data::set_ano(int ano)
{
  this->ano = ano;
}
