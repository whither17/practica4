#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include "red.h"

void entradaShort(unsigned short *numero, unsigned short *b);
void entradaInt(int *numero, std::string *ms);
void entradaDouble(double *numero, std::string *ms);

void nuevoruter(red *Red);
void delrouter(red *Red);
void modrouter(red *Red);
void rutaOptima(red *Red);

#endif // FUNCIONES_H
