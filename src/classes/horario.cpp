#include "horario.h"

Horario::Horario(short unsigned hora, short unsigned minuto)
{
  if(hora > 23 || minuto > 59)
    throw std::invalid_argument("Hora ou minuto inválido(s).");

  this->hora = hora;
  this->minuto = minuto;
}

short unsigned Horario::getHora() const
{
  return this->hora;
}

void Horario::setHora(short unsigned hora)
{
  if(hora > 23)
    throw std::invalid_argument("Hora inválida.");

  this->hora = hora;
}

short unsigned Horario::getMinuto() const
{
  return this->minuto;
}

void Horario::setMinuto(short unsigned minuto)
{
  if(minuto > 59)
    throw std::invalid_argument("Minuto inválido.");

  this->minuto = minuto;
}

int unsigned Horario::getHorarioEmMinutos() const
{
  return this->hora * 60 + this->minuto;
}

std::ostream &operator<<(std::ostream &os, const Horario &horario)
{
  os << horario.hora << ":" << horario.minuto;
  return os;
}
