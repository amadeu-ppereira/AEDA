#include "jurado.h"

jurado::jurado() {
	// TODO Auto-generated constructor stub

}

jurado::jurado(string nome , string morada , string telemovel , string artePerformativa) {

	this->nome = nome;
	this->morada = morada;
	this->telemovel = telemovel;
	this->arte = artePerformativa;
}

jurado::jurado(string info) {
	stringstream ss(info);
	char virgula;
	ss >> nome >> virgula >> morada >> virgula >> telemovel >> virgula >> arte;
}

std::ostream & operator<<(std::ostream &out, const JuradoNaoExiste &c){

	out << "Jurado " << c.nome << " não existe !\n";

	return out;

}

std::ostream & operator<<(std::ostream &out, const JuradoJaExiste &c) {

	out << "Jurado " << c.nome << " já existe !\n";

	return out;

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

//---------

ostream & operator<<(ostream & o, const jurado * j) {

	o << "Nome         : " << j->getNome() << endl;
	o << "Morada       : " << j->getMorada() << endl;
	o << "Telemovel    : " << j->getTelemovel() << endl;
	o << "Arte Perfor. : " << j->getArte();

	return o;
}
fstream & operator<<(fstream & o, const jurado * j) {

	o << j->getNome() << "," << j->getMorada() << "," << j->getTelemovel() << "," << j->getArte();

	return o;
}
