#pragma once 

#include <iostream>
#include "data.h"
#include "horario.h"

class Ponto {
  Data data;
  Horario entrada;
  Horario saida;

public:
  Ponto(Data data = Data(), Horario entrada = Horario(), Horario saida = Horario());

  Data getData() const;
  void setData(Data data);

  Horario getEntrada() const;
  void setEntrada(Horario entrada);

  Horario getSaida() const;
  void setSaida(Horario saida);

  double getHorasTrabalhadas();

  friend ostream &operator<<(ostream &os, const Ponto &ponto);
};