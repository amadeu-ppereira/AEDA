#ifndef _MENUS_H_
#define _MENUS_H_

#include <iostream>
#include "sessao.h"


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
 * @briefs display do menu para alterar a informacao de um candidato
 */
void menuAlterarCandidato();

/**
 * @brief display do menu para alterar um candidato com base no numero
 */
void menuAlterarCandidatoNumero();

/**
 * @brief display do menu para alterar um candidato com base no nome
 */
void menuAlterarCandidatoNome();

/**
 * @brief display do menu para ver a informacao dos candidatos
 */
void menuInfoCandidato();

/**
 * @brief display do menu para procurar e ver a informacao de um candidato
 */
void menuInfoCandidatoNumero();

/**
 * @brief display de todos os candidatos de uma arte perfomativa
 */
void menuInfoCandidatosArte();

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
 * @brief display do menu para adicionar uma sessao
 *
 */
void menuAdicionaSessao();

/**
 * @brief display do menu para remover uma sessao
 */
void menuRemoveSessao();

/**
 * @brief display do menu para adicionar candidatos a uma sessao
 * @param s sessao a que se pretende adicionar candidatos
 */
void menuAdicionaCandidatosSessao(sessao* s);

/**
 * @brief display do menu para adicionar jurados a uma sessao
 * @param s sessao a que se pretende adicionar jurados
 * @return devolve 1 se nao existirem jurados suficientes para criar uma sessao
 */
int menuAdicionaJuradosSessao(sessao* s);

/**
 * @brief display do menu para obter informacao de uma sessao
 */
void menuInfoSessoes();
/**
 *
 *
 *
 */
void menuIniciarSessao();



#endif /* _MENUS_H_ */
