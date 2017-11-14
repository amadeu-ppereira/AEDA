#ifndef SRC_CANDIDATO_H_
#define SRC_CANDIDATO_H_

#include <string>
#include <vector>
#include "sessao.h"
using namespace std;
class Casting;

class candidato {
	string nome;
	string morada;
	int dia, mes ,ano;// 1 -> dia 2 -> mes 3 -> ano ;;
	string arte;
	static int numeroInsc ;
	const int numero;
	vector<sessao*> participacoes;
public:

	/*
	 *  @brief constructor da class candidato (inicializa dia mes e ano a zero)
	 *
	 */
	candidato();
	/*
	 * @brief destrutor de um objecto da class candidato
	 *
	 */
	~candidato();
	/*
	 * @brief construtor de um objecto da class candidato
	 * @param nome nome do candidato
	 * @param morada morada do candidato
	 * @param dia dia (data de nascimento)do candidato
	 * @param mes mes (data de nascimento) do candidato
	 * @param ano ano (data de nascimento) do candidato
	 * @param arte arte do candidato
	 */
	candidato(string nome , string morada  , int dia , int mes , int ano, string arte);

	/*
	 * @brief construtor da class candidato que recebe uma string (linha do ficheiro de texto referente a candidatos)
	 *
	 * @param info string que contem informacao sobre os membros do candidato
	 */
	candidato(string info);

	/*
	 * @brief funcao que devolve o nome do candidato
	 * @return nome do candidato
	 */
	string getNome () const;

	/*
	 * @brief funcao que devolve a morada do candidato
	 * @return morada do candidato
	 */
	string getMorada() const;
	/*
	 * @brief funcao que devolve um vector de int com a data de nascimento do candidato (dia mes ano)
	 * @return vector<int> dia mes ano
	 */
	vector<int> getDataNascimento() const;

	/*
	 * @brief funcao que devolve a arte em que o candidato se considera mais apto
	 *
	 * @return arte performativa do candidato
	 */
	string getArte() const;

	/*
	 * @brief funcao que devolve o numero de inscricao do candidato
	 *
	 * @return numero de inscricao do candidato
	 */
	int getNumero() const;

	/*
	 * @brief funcao que devolve um vector com as sessoes em que o candidato participou
	 *
	 * @return vector<sessao*> sessoes do candidato
	 */
	vector <sessao*> getParticipacoes()  ;

	/*
	 * @brief altera nome do candidato
	 *
	 * @param nome string com o nome para alterar
	 */
	void setNome(string nome) ;
	/*
	 * @brief altera morada do candidato
	 *
	 * @param morada string com a morada para alterar
	 */
	void setMorada(string morada);
	/*
	 * @brief altera data de nascimento ( dia mes ano) do candidato
	 *
	 * @param v vector que contem o dia mes e ano (nesta sequencia)
	 */
	void setData (vector<int> v);
	/*
	 * @brief altera arte do candidato
	 *
	 * @param arte string com a arte a alterar
	 */
	void setArte(string arte);
	/*
	 * @brief adiciona um apontador de um objeto da class sessao ao vector participacoes do candidato
	 *
	 * @param sessao nova sessao a adicionar
	 *
	 */
	void adicionaSessao(sessao* sessao);





};

class candidatoNaoExiste {

public:
	string nome;
	int numero;
	/*
	 *  @brief constructor da excepcao candidatoNaoExiste (numero fica a 0)
	 *  @param nome nome do candidato;
	 */
	candidatoNaoExiste(string nome) {this->nome = nome; this->numero = 0;}

	/*
	 *  @brief constructor da excepcao candidatoNaoExiste (nome fica como uma sting vazia)
	 *  @param numero numero do candidato;
	 */
	candidatoNaoExiste(int numero) {this->nome = ""; this->numero = numero;};

};

std::ostream & operator<<(std::ostream &out, const candidatoNaoExiste &c);


class candidatoJaExiste {

public:
	string nome;
	/*
	 *  @brief constructor da excepcao candidatoJaExiste
	 *  @param nome nome do candidato;
	 */
	candidatoJaExiste(string nome) {this->nome = nome;}

};

std::ostream & operator<<(std::ostream &out, const candidatoJaExiste &c);

#endif /* SRC_CANDIDATO_H_ */
