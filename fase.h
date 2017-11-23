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
protected :
	sessao* s;
public:
	fase(sessao * s) {this->s = s;};
	~fase() {};
	virtual void atribuiPontuacoes()= 0;
	virtual void ordenaPontuacoes() = 0;

};


class fase1: public fase {
	vector<Classificacao> classificacoes1fase;
public:
	/**
	 * @brief construtor da class fase1
	 * @param s apontador para a sessao a que se pretende adicionar a primeira fase
	 */
	fase1(sessao* s);

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

};

class fase2: public fase {
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
};





#endif /* AEDA_FASE_H_ */
