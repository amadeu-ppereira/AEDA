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
