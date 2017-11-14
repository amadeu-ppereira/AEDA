#ifndef _MENUS_H_
#define _MENUS_H_

#include <iostream>
#include "Casting.h"
using namespace std;

/*
 * @brief display do menu geral
 * @param c elemento da class casting (por referencia)
 * @return devolve 0 ao sair
 */
int menu(Casting &c);

/*
 * @brief display do menu sobre os candidatos
 * @param c elemento da class casting (por referencia)
 *
 */
void menuCandidatos(Casting &c);

/*
 * @brief display do menu sobre os jurados
 * @param c elemento da class casting (por referencia)
 */
void menuJurados(Casting &c);

/*
 * @brief display do menu acerca das varias sessoes
 * @param c elemento da class casting (por referencia)
 */
void menuSessoes(Casting &c);



#endif /* _MENUS_H_ */
