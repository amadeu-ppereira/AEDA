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

};


class sessao {
	vector <jurado*> jurados ;
	vector <candidato*> candidatos;
	string generoArte;
	jurado* responsavel;
	int dia,mes,ano;
public:
	sessao();
	 ~sessao();
	 sessao( string generoArte);
};




class fase1 : public sessao {
	vector <Classificacao> classificacoes1fase;

public :



};

class fase2 : public fase1{
	vector <candidato*> candidatos2fase;
	vector <Classificacao> classificacoes2fase;




};



#endif /* SRC_SESSAO_H_ */
