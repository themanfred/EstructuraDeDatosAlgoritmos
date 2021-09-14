#include <iostream>
#include <string>
using namespace std;
#pragma once

struct Bitacora
{
  //Declaracion de atributos y funciones
  string month;
  int day;
  string time;
  int key;
  string ip;
  string message;
  Bitacora();
  Bitacora(string month, int day, string time, string ip, string message);
  long int createKey();
  bool operator<(Bitacora bitacora);
  bool operator>(Bitacora bitacora);
  bool operator==(Bitacora bitacora);
};

//Constructor sin parametros de objeto tipo Bitacora
Bitacora::Bitacora()
{
  month = "";
  day = 0;
  time = "";
  ip = "";
  message = "";
  key = 0;
}

//Constructor de objeto tipo Bitacora con parametros
Bitacora::Bitacora(string month, int day, string time, string ip, string message)
{
  this->month = month;
  this->day = day;
  this->time = time;
  this->ip = ip;
  this->message = message;
  this->key = createKey();
}

//Se hace sobrecarga de operadores para comparar el "key" de dos objetos de tipo Bitacora. En este caso, se sobrecarga "menor que". Si el "key" que llama al operador es menor que el recibido,se retorna un valor de verdadero
bool Bitacora::operator<(Bitacora bitacora)
{
  return key < bitacora.key;
}
//Sobrecarga de "mayor que" para comparar el "key" de dos objetos
bool Bitacora::operator>(Bitacora bitacora)
{
  return key > bitacora.key;
}
//Sobrecarga de "igual que" para comparar el "key" de dos objetos
bool Bitacora::operator==(Bitacora bitacora)
{
  return key == bitacora.key;
}

long int Bitacora::createKey()
{
  //Convierte un determinado mes a segundos, con respecto a su numero en el calendario
  long int monthSeg;
  if (this->month == "Jun")
  {
    monthSeg = 6 * 2592000;
  }
  else if (this->month == "Jul")
  {
    monthSeg = 7 * 2592000;
  }
  else if (this->month == "Aug")
  {
    monthSeg = 8 * 2592000;
  }
  else if (this->month == "Sep")
  {
    monthSeg = 9 * 2592000;
  }
  else
  {
    monthSeg = 10 * 2592000;
  }

  // Hora a segundos
  // Hora a segundos
  // Crea "substrings" del input obtenido.
  string hh = this->time.substr(0, 2);
  string mm = this->time.substr(3, 2);
  string ss = this->time.substr(6, 2);
  //De string a int -> stoi
  //Convierte a entero el string substraído y lo convierte a segundos

  //Horas convertidas a entero y luego a segundos
  int horaInt = stoi(hh) * 3600;
  //Minutos convertidos a entero y luego a seugndos
  int minutoInt = stoi(mm) * 60;
  //String de segundos convertidos a entero
  int segundoInt = stoi(ss);
  //Dia a segundos
  long int diaSegundo = this->day * 86400;
  //Para generar el "key", que nos ayuda a identificar el valor de la fecha y hora, se suman todos los valores de segundos correspondientes al mes, dia, y hora
  long int key = monthSeg + diaSegundo + horaInt + minutoInt + segundoInt;

  //Finalmente se retorna el valor "key" obtenido
  return key;
  
}

