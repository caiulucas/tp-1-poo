  #pragma once

  #include <string>
  #include "pessoa.h"

  using namespace std;

  class Funcionario : public Pessoa
  {
  private:
    string nome_usuario;
    string senha;
    string tipo;
    string funcao;
    double salario_hora;

  public:
    Funcionario(string tipo = "", string funcao = "", double salario_hora = 0.0);

    virtual ~Funcionario();

    void set_tipo(string tipo);
    string get_tipo() const;

    void set_funcao(string funcao);
    string get_funcao() const;

    void set_salario_hora(double salario_hora);
    double get_salario_hora() const;

    double calcular_horas_semana();
    double calcular_horas_mes();

    virtual double calcular_salario();
    virtual void mostrar_salario();
    virtual void mostrar_vendas();

    friend ostream &operator<<(ostream, const Funcionario &);
  };