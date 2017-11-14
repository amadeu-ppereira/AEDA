#include "candidato.h"
#include "sstream"

int candidato::numeroInsc = 0;


candidato::candidato(int dia = 0 , int mes = 0 , int ano = 0) : numero(++numeroInsc){
	this-> dia = dia;
	this->mes = mes;
	this->ano = ano;

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

void candidato::adicionaSessao(sessao* sessao){
	participacoes.push_back(sessao);

}

