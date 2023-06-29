#include "ponto.h"

Ponto::Ponto(Data data, Horario entrada, Horario saida)
{
  this->data = data;
  this->entrada = entrada;
  this->saida = saida;
}

Data Ponto::getData() const
{
  return this->data;
}

void Ponto::setData(Data data)
{
  this->data = data;
}

Horario Ponto::getEntrada() const
{
  return this->entrada;
}

void Ponto::setEntrada(Horario entrada)
{
  this->entrada = entrada;
}

Horario Ponto::getSaida() const
{
  return this->saida;
}

void Ponto::setSaida(Horario saida)
{
  this->saida = saida;
}

double Ponto::getHorasTrabalhadas()
{
  int unsigned entrada = this->entrada.getHorarioEmMinutos();
  int unsigned saida = this->saida.getHorarioEmMinutos();

  if (saida < entrada)
    saida += 24 * 60; // 24 horas * 60 minutos (1 dia)

  int unsigned minutosTrabalhados = saida - entrada;

  return minutosTrabalhados / 60.0;
}

std::ostream &operator<<(std::ostream &os, const Ponto &ponto)
{
  os << ponto.data << "Entrada: " << ponto.entrada << "| Saída: " << ponto.saida;
  return os;
}
