#include "jurado.h"

jurado::jurado() {
	// TODO Auto-generated constructor stub

}

jurado::jurado(string nome , string morada , string telemovel , string artePerformativa) {

	this->nome = nome;
	this->morada = morada;
	this->telemovel = telemovel;
	this->arte = arte;
}




jurado::~jurado() {
	// TODO Auto-generated destructor stub
}

//metodos set()
void jurado::setNome (string nome)
{
	this->nome=nome;
}

void jurado::setMorada (string morada)
{
	this->morada=morada;
}

void jurado::setTelemovel (string telemovel)
{
	this->telemovel=telemovel;
}

void jurado::setArte (string arte)
{
	this->arte=arte;
}

//metodos get()
string jurado::getNome() const
{
	return nome;
}

string jurado::getMorada() const
{
	return morada;
}

string jurado::getTelemovel() const
{
	return telemovel;
}

string jurado::getArte() const
{
	return arte;
}
