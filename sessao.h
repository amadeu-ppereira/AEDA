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
	bool concluida;
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
	 *	@param data dia,mes,ano da sessao ,respetivamente
	 */
	 sessao( string generoArte,int data[3]);
	 /**
	 *  @brief altera o genero de arte da sessao
	 *
	 *	@param generoArte generto de arte da sessao
	 */
	 void setArte(string generoArte);
	 /**
	 *  @brief altera data da sessao
	 *
	 *	@param data[3] com dia mes e ano para alterar
	 */
	 void setData(int data[3]);
	 /**
	  * @brief funcao que devolve num array a data(dia, mes, ano)
	  *
	  * @return data[3] array com a data
	  */
	 vector<int> getData();
	 /**
	  * @brief funcao que devolve o genero de arte de uma sessao
	  *
	  * @return generoArte da sessao
	  */
	 string getGeneroArte();





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
	 * @brief ordena o vetor de classificacoes da segunda fase
	 *
	 */
	void ordenar2fase();
	/**
	 * @brief funcao que da display do vencedor e da sua pontuacao
	 *
	 */
	void displayVencedor();
};

class sessaoNaoExiste {

public:
	string generoArte;
	vector<int> data;
	/**
	 *  @brief constructor da excepcao candidatoNaoExiste (numero fica a 0)
	 *  @param nome nome do candidato;
	 */
	sessaoNaoExiste(string generoArte,vector<int> data)
	{this->generoArte = generoArte;
	this->data = data;}

};

std::ostream & operator<<(std::ostream &out, const sessaoNaoExiste &s);


class sessaoJaExiste {

public:
	string generoArte;
	vector<int> data;
	/**
	 *  @brief constructor da excepcao sessaoJaExiste
	 *  @param generoArte genero de arte da sessao;
	 *  @param data[] array com data(dia,mes,ano) da sessao;
	 */
	sessaoJaExiste(string generoArte,vector<int> data)
	{this->generoArte = generoArte;
	this->data[0]=data[0];
	this->data[1]=data[1];
	this->data[1]=data[1];}

};

std::ostream & operator<<(std::ostream &out, const sessaoJaExiste &s);

#endif /* SRC_SESSAO_H_ */
