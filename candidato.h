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

};

#endif /* SRC_CANDIDATO_H_ */
