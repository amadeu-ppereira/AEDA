#ifndef SRC_JURADO_H_
#define SRC_JURADO_H_

#include <string>
#include <vector>

using namespace std;


class jurado {
	string nome;
	string morada;
	string telemovel;
	string arte;

public:
	/*
	* @brief construtor de um objecto da class candidato
	*
	*/
	jurado();
	/*
	* @brief construtor de um objecto da class candidato
	* @param nome nome do jurado
	* @param morada morada do jurado
	* @param arte arte em que o jurado e especialista
	*/
	jurado (string nome , string morada , string telemovel , string arte);
	/*
	* @brief destrutor de um objecto da class jurado
	*
	*/
	~jurado();
	/*
	* @brief funcao que altera o nome do jurado
	* @param nome nome do jurado
	*/
	void setNome (string nome);
	/*
	* @brief funcao que altera a morada do jurado
	* @param morada morada do jurado
	*/
	void setMorada (string morada);
	/*
	* @brief funcao que altera o telemovel do jurado
	* @param telemovel telemovel do jurado
	*/
	void setTelemovel (string telemovel);
	/*
	* @brief funcao que altera a arte do jurado
	* @param arte arte do jurado
	*/
	void setArte (string arte);
	/*
	* @brief funcao que devolve o nome do jurado
	* @return nome do jurado
	*/
	string getNome () const;
	/*
	* @brief funcao que devolve a morada do jurado
	* @return morada do jurado
	*/
	string getMorada() const;
	/*
	* @brief funcao que devolve o numero de telemovel do jurado
	* @return telemovel do jurado
	*/
	string getTelemovel() const;
	/*
	* @brief funcao que devolve a arte do jurado
	* @return arte do jurado
	*/
	string getArte() const;
};

#endif /* SRC_JURADO_H_ */
