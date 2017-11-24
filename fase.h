#ifndef AEDA_FASE_H_
#define AEDA_FASE_H_


#include <iostream>
#include <string>
#include <vector>
#include "jurado.h"
#include "sessao.h"


class candidato;

struct Classificacao {

	candidato* c;
	float j1;
	float j2;
	float j3;
	float media;
};

class fase {
public:
	fase();
	virtual ~fase();
	virtual void atribuiPontuacoes()= 0;
	virtual void ordenaPontuacoes() = 0;
	virtual vector<Classificacao> getClassificacoes() const;
	virtual sessao* getSessao() = 0;

};


class fase1: public fase {
	sessao* s;
	vector<Classificacao> classificacoes1fase;
public:
	/**
	 * @brief construtor da class fase1
	 * @param s apontador para a sessao a que se pretende adicionar a primeira fase
	 */
	fase1(sessao* s);

	/**
	 * @brief construtor da class fase1
	 * @param info string com a informacao relativa à fase1
	 */
	fase1(string info);

	/**
	 *  @brief funcao para atribuir as pontuacoes de um candidato
	 */
	void atribuiPontuacoes();

	/**
	 * @brief ordena as varias classificacoes de cada candidato de ordem decrescente tendo como base a media
	 */
	void ordenaPontuacoes();

	/**
	 * @brief devolve o vetor com as classificacoes
	 * @return vetor com classificacoes
	 */
	vector<Classificacao> getClassificacoes() const;

	/**
	 * @brief overload do operador << para a classe fase1 (ostream)
	 */
	friend ostream & operator<<(ostream & o, fase1 f);

	sessao* getSessao();


};

class fase2: public fase {
	sessao* s;
	vector<candidato*> candidatos2fase;
	vector<Classificacao> classificacoes2fase;
public:
	/**
	 * @brief construtor da class fase2 que passa a segunda fase os 5 melhores classificados da primeiara fase
	 * @param f primeirafase correspondente
	 * @param s apontador para a sessao  a que se pretende adicionar a segunda fase
	 */

	fase2(fase1 f, sessao *s);

	/**
	 * @brief construtor da class fase1
	 * @param info string com a informacao relativa à fase1
	 */
	fase2(string info);

	/**
	 * @brief ordena as varias classificacoes de cada candidato de ordem decrescente tendo como base a media
	 */
	void ordenaPontuacoes();
	/**
	 * @brief funcao que da display do vencedor e da sua pontuacao
	 *
	 */
	void displayVencedor();

	/**
	 *  @brief funcao para atribuir as pontuacoes de um candidato
	 */
	void atribuiPontuacoes();

	/**
	 * @brief devolve o vetor com as classificacoes
	 * @return vetor com classificacoes
	 */
	vector<Classificacao> getClassificacoes() const;


	/**
	 * @brief overload do operador << para a classe fase2 (ostream)
	 */
	friend ostream & operator<<(ostream & o, fase2 f);

	sessao* getSessao();
};





#endif /* AEDA_FASE_H_ */
