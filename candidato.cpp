#include "candidato.h"





int candidato::numeroInsc = 0;

std::ostream & operator<<(std::ostream &out, const candidatoJaExiste &c) {
	out << "Candidato " << c.nome << " ja existe!\n";
	return out;
}

std::ostream & operator<<(std::ostream &out, const candidatoNaoExiste &c) {
	if (c.numero != 0)
		out << "Candidato numero " << c.numero << " nao existe!\n";
	else
		out << "Candidato " << c.nome << " nao existe!\n";

	return out;
}

std::ostream & operator<<(std::ostream &out, const candidatoOcupado &c) {
	out << "Candidato ja tem uma sessao nesse dia!\n";
	return out;
}

candidato::candidato() : numero(++numeroInsc){
	this-> dia = 0;
	this->mes = 0;
	this->ano = 0;

}

candidato::candidato(string nome , string morada  , int dia , int mes , int ano,  string arte, vector<pair<int[3],string> > indisp) :
		numero(++numeroInsc)  {
	this->nome = nome;
	this->morada = morada;
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
	this->arte = arte;
	this->indisponibilidades = indisp;

}

candidato::candidato(string info) :numero(++numeroInsc){
	stringstream ss(info);
	char virgula;
	getline(ss, this->nome, ',');
	this->nome = this->nome.substr(0, this->nome.size()-1);
	getline(ss, this->morada, ',');
	this->morada = this->morada.substr(1, this->morada.size()-2);
	ss >> this->dia>> virgula >> this->mes >> virgula >> this->ano >> virgula >> this->arte;

	vector<pair<int[3],string> > indisp;
	string temp;
	while(getline(ss, temp, ';')) {
		pair<int[3],string> a;
		temp = temp.substr(1, temp.size() - 2);
		stringstream i(temp);
		i >> a.first[0] >> virgula >> a.first[1] >> virgula >> a.first[2] >> virgula;
		string razao;
		getline(i, razao);
		razao = razao.substr(1, this->nome.size()-1);
		a.second = razao;
		indisp.push_back(a);
	}

	this->indisponibilidades = indisp;

	ss.ignore('\n');
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

vector<sessao*> candidato::getParticipacoes() const {

	return participacoes;
}

vector<pair<int[3],string> > candidato::getIndisponibilidades() const {
	return indisponibilidades;
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

bool candidato::candidatoOcupado(vector<int> data) {
	for(unsigned int i = 0; i < participacoes.size() ; i++) {
		if(participacoes.at(i)->getData() == data) {
			return true;
		}
	}
	return false;
}

ostream & operator<<(ostream & o, const candidato * c) {
	o << "Numero : " << c->getNumero() << endl;
	o << "Nome : " << c->getNome() << endl;
	o << "Morada : " << c->getMorada() << endl;
	o << "Data de Nascimento : " << c->getDataNascimento()[0] << "/" << c->getDataNascimento()[1] << "/" << c->getDataNascimento()[2] << endl;
	o << "Arte : " << c->getArte() << endl;

	return o;
}

ofstream & operator<<(ofstream & o, const candidato * c) {
	o << c->getNome() << " , " << c->getMorada() << " , " << c->getDataNascimento()[0] << " , " << c->getDataNascimento()[1] << " , " << c->getDataNascimento()[2] << " , " << c->getArte();
	if(c->getIndisponibilidades().size() > 0) {
		o << " , ";
		for(unsigned int i = 0; i < c->getIndisponibilidades().size(); i++) {
			o << c->getIndisponibilidades().at(i).first[0] << " , " << c->getIndisponibilidades().at(i).first[1] << " , " << c->getIndisponibilidades().at(i).first[2] << " , ";
			o << c->getIndisponibilidades().at(i).second << " ; ";
		}
	}
	return o;
}

bool candidato::operator < (const candidato* &c) const {
	if(arte < c->getArte()) {
		return true;
	}

	else if (arte == c->getArte()) {
		if(ano > c->getDataNascimento()[2]) {
			return true;
		}
		else if(ano == c->getDataNascimento()[2]) {
			if(mes > c->getDataNascimento()[1]) {
				return true;
			}
			else if(mes == c->getDataNascimento()[1])
				return dia > c->getDataNascimento()[0];
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	return false;
}

