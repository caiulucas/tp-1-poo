#pragma once

#include <string>
#include <vector>
#include "pessoa.h"
#include "data.h"
#include "ponto.h"
#include "venda.h"

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

  double getHorasSemana(Data data) const;
  double getHorasMes(Data data) const;

  virtual vector<Venda*> getVendas() const = 0;
  virtual double getSalarioMes(Data data) const = 0;
  virtual double getBonificacao(Data data) const = 0;
  virtual double getSalarioFinal(Data data) const = 0;
  virtual void addVenda(Venda *venda) = 0;

  friend ostream &operator<<(ostream &out, const Funcionario &obj);
};