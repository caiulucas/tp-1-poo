#pragma once

#include <string>
#include <vector>
#include "pessoa.h"
#include "data.h"
#include "ponto.h"

using namespace std;

class Funcionario : public Pessoa
{
private:
  string tipo;
  string funcao;
  double salarioHora;
  vector<Ponto> pontos;

public:
  Funcionario(string nome = "", string usuario = "", string senha = "", string funcao = "", double salarioHora = 0.0);

  virtual ~Funcionario();

  string getTipo() const;
  void setTipo(string tipo);

  string getFuncao() const;
  void setFuncao(string funcao);

  double getSalarioHora() const;
  void setSalarioHora(double salario_hora);

  vector<Ponto> getPontos() const;
  void addPonto(Ponto ponto);

  double getHorasSemana(Data data);
  double getHorasMes(Data data);

  friend ostream &operator<<(ostream &out, const Funcionario &obj);
};