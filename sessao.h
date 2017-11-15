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
	/*
	*  @brief constructor da class sessao (inicializa dia mes e ano a zero)
	*
	*/
	sessao();
	 ~sessao();
	 /*
	 *  @brief constructor da class sessao
	 *
	 *	@param genertoArte genero de arte da sessao
	 */
	 sessao( string generoArte);
	 /*
	 *  @brief altera o genero de arte da sessao
	 *
	 *	@param generoArte generto de arte da sessao
	 */
	 void setArte(string generoArte);
	 /*
	 *  @brief altera data da sessao
	 *
	 *	@param data com dia mes e ano para alterar
	 */
	 void setData(vector<int> data);
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
