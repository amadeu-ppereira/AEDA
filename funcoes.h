#ifndef _FUNCOES_H_
#define _FUNCOES_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "candidato.h"
#include "jurado.h"
#include "sessao.h"
#include "fase.h"



extern vector<candidato*> candidatosGlobal;
extern vector<jurado*> juradosGlobal;
extern vector<sessao*> sessaoGlobal;


/**
 * @brief verifica se houve erro com o cin
 * @return 0 nao houve erro, 1 se houve erro
 */
int cinTeste();

/**
 * @brief grava o vetor global de candidatos no ficheiro
 * @return 0 se sucesso, 1 se endereço invalido
 */
int gravarFicheiroCandidatos();

/**
 * @brief grava o vetor global de jurados no ficheiro
 * @return 0 se sucesso, 1 se endereço invalido
 */
int gravarFicheiroJurados();

/**
 * @brief grava o vetor global de sessoes no ficheiro
 * @return 0 se sucesso, 1 se endereço invalido
 */
int gravarFicheiroSessoes();

/**
 * @brief grava os vetores globais nos ficheiros respetivos
 * @return 0 se nao houver erro, 1 se houver erro
 */
int gravarFicheiros();


/**
 * @brief abre e lê a informacao de todos os ficheiros
 * @return 0 se nao houver erro, 1 se houve algum erro
 */
int lerFicheiros();

 /**
  * @brief lê o ficheiro e guarda a informacao dos candidatos no vetor global
  * @return 0 se sucesso, 1 se endereço invalido
  */
int lerFicheiroCandidatos();

/**
 * @brief lê o ficheiro e guarda a informacao dos jurados no vetor global
 * @return 0 se sucesso, 1 se endereço invalido
 */
int lerFicheiroJurados();

/**
 * @brief lê o ficheiro e guarda a informacao das sessoes no vetor global
 * @return 0 se sucesso, 1 se endereço invalido
 */
int lerFicheiroSessoes();

/**
 * @brief guarda informacao nos ficheiros e sair do programa
 */
void sair();

/**
 * @brief adiciona um candidato
 * @param c objeto de um candidato
 */
void adicionaCandidato(candidato *c);

/**
 * @brief remove um candidato
 * @param numero numero do candidato a remover
 */
void removeCandidato(int numero);

/**
 * @brief remove um candidato
 * @param nome nome do candidato a remover
 */
void removeCandidato(string nome);

/**
 * @brief dá display da informacao do candidato
 * @param numero numero do candidato
 */
void infoCandidato(int numero);

/**
 * @brief dá display da informacao do candidato
 * @param c candidato pretendido
 */
void infoCandidato(candidato *c);

/**
 * @brief adiciona um jurado
 * @param j objeto de um jurado
 */
void adicionaJurado(jurado *j);

/**
 * @brief remove um jurado
 * @param nome nome do jurado a remover
 */
void removeJurado(string nome);

/**
 * @brief dá display da informacao dos jurados
 * @param j objecto de um jurado
 */
void infoJurado(jurado *j);

/**
 * @brief procura se o candidato se encontra no vetor global
 * @param c candidato a procurar
 * @return indice se existir, -1 se não existir
 */
int procuraCandidato(candidato *c);

/**
 * @brief procura se o candidato se encontra no vetor global
 * @param numero numero do candidato a procurar
 * @return indice se existir, -1 se não existir
 */
int procuraCandidato(int numero);

/**
 * @brief procura se o candidato se encontra no vetor global
 * @param nome nome do candidato a procurar
 * @return indice se existir, -1 se não existir
 */
int procuraCandidato(string nome);

/**
 * @brief procura se o jurado se encontra no vetor global de jurados
 * @param j jurado a procurar
 * @return indice se existir , -1 caso contrário
 */
int procuraJurado (jurado *c);

/**
 *@brief procura se o jurado se encontra no vetor global de jurados
 *@param nome nome do jurado a procurar
 *@return indice se existir , -1 caso contrário
 */
int procuraJurado(string nome);

/**
 * @brief dá display da informacao do jurado
 * @param nome nome do jurado
 */
void infoJurado(string nome);
/**
 *@brief procura se a sessao se encontra no vetor global de sessoes
 *@param s sessao a procurar
 *@return indice se existir , -1 caso contrário
 */
int procuraSessao(sessao *s);
/**
 *@brief procura se a sessao se encontra no vetor global de sessoes
 *@param s generoArte é o genero de arte da sessao pretendida
 *@param data é da data da sessao
 *@return indice se existir , -1 caso contrário
 */
int procuraSessao(string generoArte,vector<int> data);
/**
 * @brief adiciona uma nova sessao ao vetor global sessoes
 *
 * @param s sessao a adicionar
 */
void adicionaSessao(sessao *s);
/**
 * @brief remove uma sessao do vetor global de sessoes
 *
 * @param generoArte generto de arte da sessao a remover
 * @param data vetor com a data (dia,mes,ano) a remover
 */
void removeSessao(string generoArte,vector<int> data);

/**
 * @brief da display de todos os candidatos disponiveis para uma sessao
 * @param s sessao a analisar
 * @return vector com os numeros de todos os candidatos disponiveis
 */
vector<int> candidatosDisponiveis(sessao* s);

/**
 * @brief da display de todos os jurados disponiveis para uma sessao
 * @param s sessao a analisar
 * @return vector com os nomes de todos os jurados disponiveis
 */
vector<string> juradosDisponiveis(sessao* s);

/**
 * @brief adiciona um candidato a uma sessao
 * @param n numero do candidato
 * @param s sessao a adicionar
 */
void adicionaCandidatoSessao(int n, sessao* s);

/**
 * @brief adiciona um jurado a uma sessao
 * @param nome nome do jurado
 * @param s sessao a adicionar
 */
void adicionaJuradoSessao(string nome, sessao* s);

/**@brief dá display das informacoes de uma sessao
 * @param arte arte da sessao
 * @param data data da sessao
 */
void displayInfoSessao(string arte, vector<int> data);
/**
 * @brief esta funcao permite a atribuicao de pontos a cada candidato de uma sessao (para ambas as fases) mostrando no fim o vencedor
 * tambem adiciona aos vetores globais as novas fases
 * @param arte a arte da sessao
 * @param data a data da sessao
 */
void comecarSessao(string arte,vector<int> data);

/**
 *@brief procura se a sessao ja tem uma fase1
 *@param s sessao a procurar
 *@return indice da fase se existir , -1 caso contrário
 */
int procuraFase1 (sessao *s);

/**
 *@brief procura se a sessao ja tem uma fase2
 *@param s sessao a procurar
 *@return indice da fase se existir , -1 caso contrário
 */
int procuraFase2 (sessao *s);

/**
 * @brief remove as fases de uma sessao
 * @param s sessao
 */
void removeFases(sessao* s);

#endif /* _FUNCOES_H_ */
