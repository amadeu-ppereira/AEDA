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
	 sessao( string generoArte,vector<int> data);
	 /**
	 *  @brief altera o genero de arte da sessao
	 *
	 *	@param generoArte generto de arte da sessao
	 */
	 void setArte(string generoArte);
	/**
	 *  @brief altera se a sessao ja foi concluida
	 *
	 *	@param c valor para alterar
	 */
	 void setConcluida(bool c);
	 /**
	 *  @brief altera data da sessao
	 *
	 *	@param data vetor com dia mes e ano para alterar
	 */
	 void setData(vector<int> data);
	 /**
	  * @brief funcao que devolve num array a data(dia, mes, ano)
	  *
	  * @return vetor de int's com a data
	  */
	 vector<int> getData() const;
	 /**
	  * @brief funcao que devolve o genero de arte de uma sessao
	  *
	  * @return generoArte da sessao
	  */
	 string getGeneroArte() const;

	/**
	 * @brief funcao que devolve os candidatos de uma sessao
	 *
	 * @return candidatos da sessao
	 */
	 vector<candidato*> getCandidatos() const;

	/**
	 * @brief funcao que devolve os jurados de uma sessao
	 *
	 * @return jurados da sessao
	 */
	vector<jurado*> getJurados() const;

	 /**
	  * @brief adiciona um candidato a sessao
	  * @param c candidato a adicionar
	  */
	 void adicionaCandidato(candidato *c);

	 /**
	  * @brief adiciona um jurado a sessao
	  * @param j jurado a adicionar
	  */
	 void adicionaJurado(jurado *j);

	 /**
	  * @brief diz quantos jurados tem a sessao
	  * @return numero de jurados
	  */
	 int getNumeroJurados() const;

	/**
	 * @brief overload do operador << para a classe sessao (ostream)
	 */
	friend ostream & operator<<(ostream & o, const sessao * s);

	/**
	 * @brief diz se a sessao ja for concluida
	 * @return valor da variavel concluida
	 */
	bool sessaoConcluida() const;

	/**
	 * @brief funcao virtual para atribui pontuacoes aos candidatos
	 *
	 */
	virtual void atribuiPontuacoes();




};


class fase1: public sessao {
protected:
	vector<Classificacao> classificacoes1fase;

public:
	/**
	 * @brief construtor da class fase1
	 */
	fase1();
	/**
	 *  @brief funcao para atribuir as pontuacoes de um candidato
	 *
	 *  @param c candidato a atribuir as pontuacoes
	 *  @param classjurados vetor com as pontuacoes dos 3 jurados
	 */
	void atribuiPontuacoes(candidato *c, vector<float> classjurados);

	/**
	 * @brief devolve o candidatos da primeira fase
	 * @return vetor com os candidatos
	 */
	vector<candidato*> getCandidatos() const;


};

class fase2: public fase1 {
	vector<Classificacao> classificacoes2fase;
	vector<candidato*> candidatos2fase;

public:
	/**
	 * @brief construtor da class fase2
	 */
	fase2();
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

	/**
	 *  @brief funcao para atribuir as pontuacoes de um candidato
	 *
	 *  @param c candidato a atribuir as pontuacoes
	 *  @param classjurados vetor com as pontuacoes dos 3 jurados
	 */
	void atribuiPontuacoes(candidato *c, vector<float> classjurados);
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
	this->data = data;}

};

std::ostream & operator<<(std::ostream &out, const sessaoJaExiste &s);

#endif /* SRC_SESSAO_H_ */
