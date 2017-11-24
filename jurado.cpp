#include "jurado.h"
#include "sessao.h"


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
	getline(ss, this->nome, ',');
	this->nome = this->nome.substr(0, this->nome.size() - 1);
	getline(ss, this->morada, ',');
	this->morada = this->morada.substr(1, this->morada.size() - 2);
	ss >> telemovel >> virgula >> arte;
	ss.ignore('\n');

}

std::ostream & operator<<(std::ostream &out, const JuradoNaoExiste &c){

	out << "Jurado " << c.nome << " não existe !\n";

	return out;

}

std::ostream & operator<<(std::ostream &out, const JuradoJaExiste &c) {

	out << "Jurado " << c.nome << " já existe !\n";

	return out;

}

std::ostream & operator<<(std::ostream &out, const juradoOcupado &c) {
	out << "O jurado ja tem uma sessao nesse dia!\n";
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

void jurado::setSessoes(vector<sessao*> s) {
	this->sessoes = s;
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

vector<sessao*> jurado::getSessoes() const {
	return sessoes;
}

//---------

void jurado::adicionaSessao(sessao* s) {
	this->sessoes.push_back(s);
}

bool jurado::juradoOcupado(vector<int> data) {
	for(unsigned int i = 0; i < sessoes.size() ; i++) {
		if(sessoes.at(i)->getData() == data) {
			return true;
		}
	}
	return false;
}

ostream & operator<<(ostream & o, const jurado * j) {

	o << "Nome         : " << j->getNome() << endl;
	o << "Morada       : " << j->getMorada() << endl;
	o << "Telemovel    : " << j->getTelemovel() << endl;
	o << "Arte Perfor. : " << j->getArte() << endl;

	return o;
}
ofstream & operator<<(ofstream & o, const jurado * j) {

	o << j->getNome() << " , " << j->getMorada() << " , " << j->getTelemovel() << " , " << j->getArte();

	return o;
}
