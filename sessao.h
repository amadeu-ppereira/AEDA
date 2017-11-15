#ifndef SRC_SESSAO_H_
#define SRC_SESSAO_H_

#include "jurado.h"
#include <string>
#include <vector>


class candidato;


struct Classificacao {

	candidato* c;
	float j1;
	float j2;
	float j3;
	float media;
};


class sessao {
	vector <jurado*> jurados ;
	vector <candidato*> candidatos;
	string generoArte;
	jurado* responsavel;
	int dia,mes,ano;
public:
	/**
	*  @brief constructor da class sessao (inicializa dia mes e ano a zero)
	*
	*/
	sessao();
	/**
	 *
	 * @brief destrutor da class sessao
	 *
	 */
	 ~sessao();
	 /**
	 *  @brief constructor da class sessao
	 *
	 *	@param genertoArte genero de arte da sessao
	 */
	 sessao( string generoArte);
	 /**
	 *  @brief altera o genero de arte da sessao
	 *
	 *	@param generoArte generto de arte da sessao
	 */
	 void setArte(string generoArte);
	 /**
	 *  @brief altera data da sessao
	 *
	 *	@param data com dia mes e ano para alterar
	 */
	 void setData(vector<int> data);





};


class fase1: public sessao {
	protected:
		vector<Classificacao> classificacoes1fase;

	public:
	/**
	 *  @brief funcao para atribuir as pontuacoes de um candidato
	 *
	 *  @param c candidato a atribuir as pontuacoes
	 *  @param classjurados[3] array com as pontuacoes dos 3 jurados
	 */
	void atribuiPontuacoes(candidato *c, float classjurados[3]);


};

class fase2: public fase1 {
	vector<Classificacao> classificacoes2fase;

public:
	/**
	 *  @brief funcao que passa a segunda fase os 5 melhores classificados da primeiara fase
	 *
	 */
	void passagem2fase();

	/**
	 * @brief calcula o vencedor da segunda fase
	 *
	 */
	void calculaVencedor();
};



#endif /* SRC_SESSAO_H_ */
