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
 * @brief dá display da informacao dos candidatos
 */
void infoCandidato();

/*
 * @brief adiciona um jurado
 */
void adicionaJurado();

/*
 * @brief remove um jurado
 */
void removeJurado();

/*
 * @brief dá display da informacao dos jurados
 */
void infoJurado();

/*
 * @brief procura se o candidato se encontra no vetor global
 * @param c candidato a procurar
 * return indice se existir, -1 se não existir
 */
int procuraCandidato(candidato *c);

/*
 * @brief procura se o candidato se encontra no vetor global
 * @param numero numero do candidato a procurar
 * return indice se existir, -1 se não existir
 */
int procuraCandidato(int numero);

/*
 * @brief procura se o candidato se encontra no vetor global
 * @param nome nome do candidato a procurar
 * return indice se existir, -1 se não existir
 */
int procuraCandidato(string nome);



#endif /* _FUNCOES_H_ */
