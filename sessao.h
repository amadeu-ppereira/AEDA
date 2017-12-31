#ifndef SRC_SESSAO_H_
#define SRC_SESSAO_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "jurado.h"
#include "fase.h"



class candidato;


/**
 * @class sessao
 * @brief classe com as informacoes relativas a uma sessao
 */
class sessao {
	vector <jurado*> jurados ; ///< vetor com todos os jurados desta sessao
	vector <candidato*> candidatos; ///< vetor com todos os candidatos desta sessao
	string generoArte; ///< genero de arte perfomativa da sessao
	int dia,mes,ano; ///< data da sessao
	bool concluida; ///< indica se a sessao ja foi concluida (true se sim, false se nao)
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
	  * @brief construtor da class sessao
	  * @param info string com toda a informacao acerca de uma sessao
	  */
	 sessao(string info);

	 /**
	 *  @brief constructor da class sessao
	 *
	 *	@param generoArte genero de arte da sessao
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
	 * @brief overload do operador << para a classe sessao (fstream)
	 */
	friend ofstream & operator<<(ofstream & o, const sessao * s);

	/**
	 * @brief overload do operador < para a classe sessao
	 */
	bool operator < (const sessao* &s) const;

};



/**
 * @class sessaoNaoExiste
 * @brief excepcao para quando um objeto da classe sessao nao existe
 */
class sessaoNaoExiste {

public:
	string generoArte; ///< genero de arte da sessao
	vector<int> data; ///< data da sessao
	/**
	 *  @brief constructor da classe sessao nao existe
	 *  @param generoArte genero de arte;
	 *  @param data vetor com a data da sessao
	 */
	sessaoNaoExiste(string generoArte,vector<int> data)
	{this->generoArte = generoArte;
	this->data = data;}

};

std::ostream & operator<<(std::ostream &out, const sessaoNaoExiste &s);

/**
 * @class sessaoJaExiste
 * @brief excepcao para quando um objeto da classe sessao ja existe
 */
class sessaoJaExiste {

public:
	string generoArte; ///< genero de arte da sessao
	vector<int> data; ///< data da sessao
	/**
	 *  @brief constructor da excepcao sessaoJaExiste
	 *  @param generoArte genero de arte da sessao;
	 *  @param data vetor com data(dia,mes,ano) da sessao;
	 */
	sessaoJaExiste(string generoArte,vector<int> data)
	{this->generoArte = generoArte;
	this->data = data;}

};

std::ostream & operator<<(std::ostream &out, const sessaoJaExiste &s);

#endif /* SRC_SESSAO_H_ */
