#include "sessao.h"

sessao::sessao() {
	this->dia=0;
	this->mes=0;
	this->ano=0;
}


sessao::sessao(string generoArte) {
	this->generoArte = generoArte;

}

sessao::~sessao() {
	// TODO Auto-generated destructor stub
}

void sessao::setArte(string generoArte)
{
	this->generoArte=generoArte;
}

void sessao::setData(vector<int> data)
{
	this->dia=data[0];
	this->mes=data[1];
	this->ano=data[2];
}

void fase1::atribuiPontuacoes(candidato *c , float classjurados[3]){

	float m = (classjurados[0] + classjurados[1] + classjurados[2])/3;
	Classificacao cf = {c , classjurados[0] , classjurados[1] , classjurados[2], m};
	classificacoes1fase.push_back(cf);
}


void fase2::passagem2fase(){


	if (classificacoes1fase.size() >= 5){
		for (unsigned int i = 0 ; i < 5 ; i++){
			classificacoes2fase.push_back(classificacoes1fase[i]);
		}
	}

	else classificacoes2fase = classificacoes1fase;

}

void fase2::calculaVencedor(){




}






