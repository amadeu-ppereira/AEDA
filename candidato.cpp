#include "candidato.h"
#include "sstream"

int candidato::numeroInsc = 0;

std::ostream & operator<<(std::ostream &out, const candidatoJaExiste *c)
{ out << "Candidato numero" << c->numero << ": " << c->nome << "ja existe!\n"; return out; }

candidato::candidato() : numero(++numeroInsc){
	this-> dia = 0;
	this->mes = 0;
	this->ano = 0;

}

candidato::candidato(string nome , string morada  , int dia , int mes , int ano,  string arte) :
		numero(++numeroInsc)  {
	this->nome = nome;
	this->morada = morada;
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
	this->arte = arte;

}

candidato::candidato(string info) :numero(++numeroInsc){
	stringstream ss(info);
	char virgula;

	ss >> this->nome >> virgula >> this->morada >> virgula >> this->dia >> virgula >> this->mes >> virgula >> this->ano >> virgula >> this->arte;

}

candidato::~candidato() {
	// TODO Auto-generated destructor stub
}


/////////// get functions /////////////
string candidato::getArte() const {

	return arte;
}

vector<int> candidato::getDataNascimento() const {

	vector <int> v;
	v.push_back(dia);
	v.push_back(mes);
	v.push_back(ano);

	return v;
}

string candidato::getNome() const {

	return nome;
}

string candidato::getMorada() const {

	return morada;
}

int candidato::getNumero() const {
	return numero;
}

vector<sessao*> candidato::getParticipacoes() {

	return participacoes;
}

/////////// set functions ////////////

void candidato::setNome(string nome){
	this->nome = nome;
}

void candidato::setMorada(string morada){
	this->morada = morada;
}

void candidato::setArte(string arte){
	this->arte = arte;
}

void candidato::setData(vector<int> v){

	this->dia = v[0];
	this->mes = v[1];
	this->ano = v[2];

}
/////////////////////////////////////////

void candidato::adicionaSessao(sessao* sessao){
	participacoes.push_back(sessao);

}

