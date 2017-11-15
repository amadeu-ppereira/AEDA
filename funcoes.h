#ifndef _FUNCOES_H_
#define _FUNCOES_H_

#include "candidato.h"
#include "jurado.h"
#include "sessao.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


extern vector<candidato*> candidatosGlobal;
extern vector<jurado*> juradosGlobal;
extern vector<sessao*> sessaoGlobal;


/*
 * @brief verifica se houve erro com o cin
 * @return 0 nao houve erro, 1 se houve erro
 */
int cinTeste();

 /*
  * @brief lê o ficheiro e guarda a informacao dos candidatos no vetor global
  * @param file endereço do ficheiro
  * @return 0 se sucesso, 1 se endereço invalido
  */
int lerFicheiroCandidatos(string file);

/*
 * @brief lê o ficheiro e guarda a informacao dos jurados no vetor global
 * @param file endereço do ficheiro
 * @return 0 se sucesso, 1 se endereço invalido
 */
int lerFicheiroJurados(string file);

/*
 * @brief lê o ficheiro e guarda a informacao das sessoes no vetor global
 * @param file endereço do ficheiro
 * @return 0 se sucesso, 1 se endereço invalido
 */
int lerFicheiroSessoes(string file);

/*
 * @brief guarda informacao nos ficheiros e sair do programa
 */
void sair();

/*
 * @brief adiciona um candidato
 * @param c objeto de um candidato
 */
void adicionaCandidato(candidato *c);

/*
 * @brief remove um candidato
 * @param numero numero do candidato a remover
 */
void removeCandidato(int numero);

/*
 * @brief remove um candidato
 * @param nome nome do candidato a remover
 */
void removeCandidato(string nome);

/*
 * @brief dá display da informacao do candidato
 * @param numero numero do candidato
 */
void infoCandidato(int numero);

/*
 * @brief dá display da informacao do candidato
 * @param c candidato pretendido
 */
void infoCandidato(candidato *c);

/*
 * @brief adiciona um jurado
 * @param j objeto de um jurado
 */
void adicionaJurado(jurado *j);

/*
 * @brief remove um jurado
 * @param nome nome do jurado a remover
 */
void removeJurado(string nome);

/*
 * @brief dá display da informacao dos jurados
 * @param j objecto de um jurado
 */
void infoJurado(jurado *j);

/*
 * @brief procura se o candidato se encontra no vetor global
 * @param c candidato a procurar
 * @return indice se existir, -1 se não existir
 */
int procuraCandidato(candidato *c);

/*
 * @brief procura se o candidato se encontra no vetor global
 * @param numero numero do candidato a procurar
 * @return indice se existir, -1 se não existir
 */
int procuraCandidato(int numero);

/*
 * @brief procura se o candidato se encontra no vetor global
 * @param nome nome do candidato a procurar
 * @return indice se existir, -1 se não existir
 */
int procuraCandidato(string nome);

/*
 * @brief procura se o jurado se encontra no vetor global de jurados
 * @param j jurado a procurar
 * @return indice se existir , -1 caso contrário
 */
int procuraJurado (jurado *c);

/*
 *@brief procura se o jurado se encontra no vetor global de jurados
 *@param nome nome do jurado a procurar
 *@return indice se existir , -1 caso contrário
 */
int procuraJurado(string nome);


#endif /* _FUNCOES_H_ */
