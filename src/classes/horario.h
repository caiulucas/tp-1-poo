#pragma once

#include <iostream>

class Horario
{
private:
  short unsigned hora;
  short unsigned minuto;

public:
  Horario(short unsigned hora = 0, short unsigned minuto = 0);

  // Mostra o número absoluto da hora
  short unsigned getHora() const;
  // Define o valor da hora
  void setHora(short unsigned hora);

  // Mostra o valor absoluto do minuto
  short unsigned getMinuto() const;
  // Define o valor do minuto
  void setMinuto(short unsigned minuto);

  int unsigned getHorarioEmMinutos() const;

  friend std::ostream& operator<<(std::ostream& os, const Horario& horario);
};