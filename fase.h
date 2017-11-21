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
	fase() {};
	~fase() {};
	virtual void atribuiPontuacoes()= 0;
	virtual void ordenaPontuacoes() = 0;

};


class fase1: public fase {
protected:
	vector<Classificacao> classificacoes1fase;
	sessao* s;

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

};

class fase2: public fase1 {
	vector<Classificacao> classificacoes2fase;
	vector<candidato*> candidatos2fase;

public:
	/**
	 * @brief construtor da class fase2 que passa a segunda fase os 5 melhores classificados da primeiara fase
	 * @param s apontador para a sessao  a que se pretende adicionar a segunda fase
	 */

	fase2(sessao *s);

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
