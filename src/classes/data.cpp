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

int Data::getDia() const
{
  return this->dia;
}

void Data::setDia(int dia)
{
  this->dia = dia;
}

int Data::getMes() const
{
  return this->mes;
}

void Data::setMes(int mes)
{
  this->mes = mes;
}

int Data::getAno() const
{
  return this->ano;
}

void Data::setAno(int ano)
{
  this->ano = ano;
}

int Data::getSemana() const
{
  int dia = this->dia;
  int mes = this->mes;
  int ano = this->ano;

  return dia += mes <= 2 ? ano-- : ano - 2,
         23 * mes / 9 + dia + 4 + ano / 4 - ano / 100 + ano / 400;
}

ostream &operator<<(ostream &os, const Data &data)
{
  os << data.dia << "/" << data.mes << "/" << data.ano;
  return os;
}