#ifndef AEDA_FASE_H_
#define AEDA_FASE_H_


#include <iostream>
#include <string>
#include <vector>
#include "jurado.h"
#include "sessao.h"
//#include "candidato.h"


class candidato;

/**
 * @struct Classificacao
 * @brief contem a informacao das classificacoes obtidas por um candidato
 */
struct Classificacao {

	candidato* c; ///< candidato
	float j1; ///< pontuacao do jurado 1
	float j2; ///< pontuacao do jurado 2
	float j3; ///< pontuacao do jurado 3
	float media; ///< resultado final
};

/**
 * @class fase
 * @brief classe abstrata relativa as varia fases de uma sessao
 */
class fase {
public:
	/**
	 * @brief construtor da classe fase
	 */
	fase();
	/**
	 * @brief destrutor da classe fase
	 */
	virtual ~fase();
	/**
	 * @brief metodo virtual para a atribuicao das pontuacoes numa fase
	 */
	virtual void atribuiPontuacoes()= 0;
	/**
	 * @brief metodo virtual para ordenar as classificacoes dos candidatos (da maior para a menor)
	 */
	virtual void ordenaPontuacoes() = 0;
	/**
	 * @brief metodo virtual que devolve as classificacoes dos candidatos duma certa fase
	 * @return vetor com as classificacoes
	 */
	virtual vector<Classificacao> getClassificacoes() const = 0;

};

/**
 * @class fase1
 * @brief subclasse da classe fase relativa a primeira fase
 */
class fase1: public fase {
	sessao* s; ///< sessao correspondente a fase
	vector<Classificacao> classificacoes1fase; ///< vetor com as classificacoes da fase
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

	/**
	 * @brief devolve a sessao correspondente a esta fase
	 * @return apontador para a sessa
	 */
	sessao* getSessao();


};

/**
 * @class fase2
 * @brief subclasse da classe fase relativa a segunda fase
 */
class fase2: public fase {
	sessao* s; ///< sessao correspondente a fase
	vector<candidato*> candidatos2fase; ///< vetor com os candidatos que passaram a segunda fase
	vector<Classificacao> classificacoes2fase; ///< vetor com as classificacoes dos candidatos
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

	/**
	 * @brief devolve a sessao correspondente a esta fase
	 * @return apontador para a sessa
	*/
	sessao* getSessao();
};





#endif /* AEDA_FASE_H_ */
