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
	candidato();
	~candidato();
	candidato(string nome , string morada  , int dia , int mes , int ano, string arte);
};

#endif /* SRC_CANDIDATO_H_ */
