#ifndef SRC_CANDIDATO_H_
#define SRC_CANDIDATO_H_

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <utility>
#include "sessao.h"
using namespace std;


/**
 * @class candidato
 * @brief classe com as informacoes relativas a um candidato
 */
class candidato {
	string nome; ///< nome do candidato
	string morada; ///< morada do candidato
	int dia, mes ,ano; ///< dia de nascimento do candidato
	string arte; ///< arte perfomativa do candidato
	static int numeroInsc ; ///< variavel do tipo static para se atribuir um numero novo a cada candidato
	const int numero; ///< numero do candidato
	vector<sessao*> participacoes; ///< vetor com as sessoes em que o candidato participa
	vector<pair<vector<int>, string> > indisponibilidades; ///<vetor de pares com as indisponibilidades e as respetivas razoes
	bool desistiu;
public:

	/**
	 *  @brief constructor da class candidato (inicializa dia mes e ano a zero)
	 *
	 */
	candidato();
	/**
	 * @brief destrutor de um objecto da class candidato
	 *
	 */
	~candidato();
	/**
	 * @brief construtor de um objecto da class candidato
	 * @param nome nome do candidato
	 * @param morada morada do candidato
	 * @param dia dia (data de nascimento)do candidato
	 * @param mes mes (data de nascimento) do candidato
	 * @param ano ano (data de nascimento) do candidato
	 * @param arte arte do candidato
	 * @param indisp dias em que o candidato se encontra indisponivel e a razao
	 */
	candidato(string nome , string morada  , int dia , int mes , int ano, string arte, vector<pair<vector<int>, string> > indisp);

	/**
	 * @brief construtor da class candidato que recebe uma string (linha do ficheiro de texto referente a candidatos)
	 *
	 * @param info string que contem informacao sobre os membros do candidato
	 */
	candidato(string info);

	/**
	 * @brief funcao que devolve o nome do candidato
	 * @return nome do candidato
	 */
	string getNome () const;

	/**
	 * @brief funcao que devolve a morada do candidato
	 * @return morada do candidato
	 */
	string getMorada() const;
	/**
	 * @brief funcao que devolve um vector de int com a data de nascimento do candidato (dia mes ano)
	 * @return vector<int> dia mes ano
	 */
	vector<int> getDataNascimento() const;

	/**
	 *@brief funcao que devolve as indisponibilidades do candidato
	 *@return vetor de pairs com as indisponibilidades em forma de vetor e a respetiva razao
	 */
	vector<pair<vector<int>, string> > getIndisponibilidades() const;

	/**
	 * @brief funcao que devolve a arte em que o candidato se considera mais apto
	 *
	 * @return arte performativa do candidato
	 */
	string getArte() const;

	/**
	 * @brief funcao que devolve o numero de inscricao do candidato
	 *
	 * @return numero de inscricao do candidato
	 */
	int getNumero() const;

	/**
	 * @brief funcao que devolve um vector com as sessoes em que o candidato participou
	 *
	 * @return vector<sessao*> sessoes do candidato
	 */
	vector <sessao*> getParticipacoes() const ;

	/**
	 * @brief funcao que devolve uma bool se o candidato desistiu
	 *
	 * @return bool true se desistiu, false se nao
	 */
	bool getDesistiu() const;

	/**
	 * @brief altera nome do candidato
	 *
	 * @param nome string com o nome para alterar
	 */
	void setNome(string nome) ;
	/**
	 * @brief altera morada do candidato
	 *
	 * @param morada string com a morada para alterar
	 */
	void setMorada(string morada);
	/**
	 * @brief altera data de nascimento ( dia mes ano) do candidato
	 *
	 * @param v vector que contem o dia mes e ano (nesta sequencia)
	 */
	void setData (vector<int> v);
	/**
	 * @brief altera arte do candidato
	 *
	 * @param arte string com a arte a alterar
	 */
	void setArte(string arte);

	/**
	 * @brief altera se um candidato desisitiu
	 * @param d bool para que se pretende alterar
	 */
	void setDesistiu(bool d);
	/**
	 * @brief adiciona um apontador de um objeto da class sessao ao vector participacoes do candidato
	 *
	 * @param sessao nova sessao a adicionar
	 *
	 */
	void adicionaSessao(sessao* sessao);

	/**
	 * @brief remove uma sessao das participacoes do candidato
	 */
	void removeSessao(sessao* sessao);

	/**
	 * @brief overload do operador << para a classe candidato (ostream)
	 */
	friend ostream & operator<<(ostream & o, const candidato * c);

	/**
	 * @brief overload do operador << para a classe candidato (fstream)
	 */
	friend ofstream & operator<<(ofstream & o, const candidato * c);

	/**
	 * @brief verifica se o candidato ja tem alguma sessao naquele dia
	 * @return true se sim, false se nao;
	 */
	bool candidatoOcupado(vector<int> data);

	/**
	 * @brief overloado do operador < para a classe candidato
	 */
	bool operator < (const candidato* &c) const;

};

/**
 * @class candidatoNaoExiste
 * @brief excepcao para quando um objeto da classe candidato nao existe
 */
class candidatoNaoExiste {

public:
	string nome;///< nome do candidato
	int numero; ///< numero do candidato
	/**
	 *  @brief constructor da excepcao candidatoNaoExiste (numero fica a 0)
	 *  @param nome nome do candidato
	 */
	candidatoNaoExiste(string nome) {this->nome = nome; this->numero = 0;}

	/**
	 *  @brief constructor da excepcao candidatoNaoExiste (nome fica como uma sting vazia)
	 *  @param numero numero do candidato
	 */
	candidatoNaoExiste(int numero) {this->nome = ""; this->numero = numero;};

};

std::ostream & operator<<(std::ostream &out, const candidatoNaoExiste &c);

/**
 * @class candidatoJaExiste
 * @brief excepcao para quando um objeto da classe candidato ja existe
 */
class candidatoJaExiste {

public:
	string nome; ///< nome do candidato
	/**
	 *  @brief constructor da excepcao candidatoJaExiste
	 *  @param nome nome do candidato
	 */
	candidatoJaExiste(string nome) {this->nome = nome;}

};

std::ostream & operator<<(std::ostream &out, const candidatoJaExiste &c);

/**
 * @class candidatoOcupado
 * @brief excepcao para quando um objeto da classe candidato ja ja se encontra ocupado num determinado dia
 */
class candidatoOcupado {

public:
	int numero; ///< numero do candidato
	vector<int> data; ///< data em que se encontra ocupado
	/**
	 *  @brief constructor da excepcao candidatoOcupado
	 *  @param numero numero do candidato
	 *  @param data data em que esta ocupado
	 */
	candidatoOcupado(int numero, vector<int> data) {this->numero = numero; this->data = data;}

};

std::ostream & operator<<(std::ostream &out, const candidatoOcupado &c);

#endif /* SRC_CANDIDATO_H_ */
