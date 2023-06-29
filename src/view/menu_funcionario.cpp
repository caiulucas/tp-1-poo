
#include "menu_funcionario.h"

using namespace std;

MenuFuncionario::MenuFuncionario(Funcionario *funcionario)
{
  this->funcionario = funcionario;
}

void MenuFuncionario::addPonto()
{
  int dia, mes, ano;

  while (true)
  {
    cout << "\x1b[1m\x1b[34mData (DD MM YYYY):\x1b[0m ";
    cin >> dia >> mes >> ano;

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0)
      cout << "\x1b[1m\x1b[31mData inválida!\x1b[0m" << endl;
    else
      break;
  }

  Data *data = new Data(dia, mes, ano);

  int hora, minuto;

  while (true)
  {
    cout << "\x1b[1m\x1b[34mHorário de entrada (HH MM):\x1b[0m ";
    cin >> hora >> minuto;

    if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59)
      cout << "\x1b[1m\x1b[31mHorário inválido!\x1b[0m" << endl;
    else
      break;
  }

  Horario *horarioInicio = new Horario(hora, minuto);

  while (true)
  {
    cout << "\x1b[1m\x1b[34mHorário de entrada (HH MM):\x1b[0m ";
    cin >> hora >> minuto;

    if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59)
      cout << "\x1b[1m\x1b[31mHorário inválido!\x1b[0m" << endl;
    else
      break;
  }

  Horario *horarioSaida = new Horario(hora, minuto);

  Ponto *ponto = new Ponto(*data, *horarioInicio, *horarioSaida);

  this->funcionario->addPonto(*ponto);
  cout << "\x1B[2J\x1B[H";
}

void MenuFuncionario::mostrarSalario()
{
  int mes, ano;

  while (true)
  {
    cout << "\x1b[1m\x1b[34mData (MM YYYY):\x1b[0m ";
    cin >> mes >> ano;

    if (mes < 1 || mes > 12 || ano < 0)
      cout << "\x1b[1m\x1b[31mData inválida!\x1b[0m" << endl;
    else
      break;
  }

  Data *data = new Data(1, mes, ano);

  cout << "\x1B[2J\x1B[H";
  cout << "\x1b[1m\x1b[34mSalário:\x1b[0m "
       << this->funcionario->getSalarioMes(*data) << endl;
  cout << "\x1b[1m\x1b[34mBônus:\x1b[0m "
       << this->funcionario->getBonificacao(*data) << endl;
  cout << "\x1b[1m\x1b[34mSalário final:\x1b[0m "
       << this->funcionario->getSalarioFinal(*data) << endl;
}

void MenuFuncionario::listarVendas()
{
  cout << "\x1B[2J\x1B[H";
  cout << "\x1b[1m\x1b[34mVendas:\x1b[0m" << endl;

  for (auto venda : this->funcionario->getVendas())
    cout << venda << endl;
}

void MenuFuncionario::menu()
{
  int opcao;

  while (true)
  {
    cout << "\x1B[2J\x1B[H";
    cout << "\x1b[1m\x1b[34mMenu do funcionário\x1b[0m" << endl;
    cout << "\x1b[1m\x1b[34m1.\x1b[0m Registrar ponto" << endl;
    cout << "\x1b[1m\x1b[34m2.\x1b[0m Mostrar salário" << endl;
    cout << "\x1b[1m\x1b[34m3.\x1b[0m Listar vendas" << endl;
    cout << "\x1b[1m\x1b[34m4.\x1b[0m Sair" << endl;
    cout << "\x1b[1m\x1b[34mOpção:\x1b[0m ";
    cin >> opcao;

    switch (opcao)
    {
    case 1:
      this->addPonto();
      break;
    case 2:
      this->mostrarSalario();
      break;
    case 3:
      this->listarVendas();
      break;
    case 4:
      return;
    default:
      cout << "\x1b[1m\x1b[31mOpção inválida!\x1b[0m" << endl;
      break;
    }

    cout << "\x1b[1m\x1b[34mPressione ENTER para continuar...\x1b[0m" << endl;
    cin.ignore();
    cin.get();
  }
}