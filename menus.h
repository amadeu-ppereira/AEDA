#ifndef _MENUS_H_
#define _MENUS_H_

#include <iostream>
#include <sessao.h>

using namespace std;

/**
 * @brief display do menu geral
 */
void menu();

/**
 * @brief display do menu sobre os candidatos
 */
void menuCandidatos();

/**
 * @brief display do menu sobre os jurados
 */
void menuJurados();

/**
 * @brief display do menu acerca das varias sessoes
 */
void menuSessoes();

/**
 * @brief display do menu para adicionar um candidato
 */
void menuAdicionaCandidato();

/**
 * @brief display do menu para remover um candidato
 */
void menuRemoveCandidato();

/**
 * @brief display do menu para remover um candidato com base no numero
 */
void menuRemoveCandidatoNumero();

/**
 * @brief display do menu para remover um candidato com base no nome
 */
void menuRemoveCandidatoNome();

/**
 * @brief display do menu para ver a informacao dos candidatos
 */
void menuInfoCandidato();

/**
 * @brief display do menu para procurar e ver a informacao de um candidato;
 */
void menuInfoCandidatoNumero();

/**
 * @brief display do menu para ver a informacao de todos os candidatos
 */
void menuInfoCandidatoTodos();

/**
 * @brief display do menu para adicionar um jurado
 */
void menuAdicionaJurado();

/**
 * @brief display do menu para remover um jurado
 */
void menuRemoveJurado();

/**
 * @brief display do menu para ver a informacao dos candidatos
 */
void menuInfoJurado();

/**
 * @brief display do menu para procurar e ver a informacao de um jurado;
 */
void menuInfoJuradoNome();

/**
 * @brief display do menu para ver a informacao de todos os jurados
 */
void menuInfoJuradoTodos();

/**
 * @brief dispay do menu para adicionar uma sessao
 *
 */
void menuAdicionaSessao();

/**
 * @brief dispay do menu para remover uma sessao
 */
void menuRemoveSessao();

/**
 * @brief dispay do menu para adicionar candidatos a uma sessao
 * @param s sessao a que se pretende adicionar candidatos
 */
void menuAdicionaCandidatosSessao(sessao* s);




#endif /* _MENUS_H_ */
