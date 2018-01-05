#include "candidato.h"
#include "funcoes.h"


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

candidato::candidato(){
	this-> dia = 0;
	this->mes = 0;
	this->ano = 0;

}

candidato::candidato(string nome , string morada  , int dia , int mes , int ano,  string arte, vector<pair<vector<int>,string> > indisp) :
		numero(++numeroInsc)  {
	this->nome = nome;
	this->morada = morada;
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
	this->arte = arte;
	this->indisponibilidades = indisp;
	this->desistiu = false;

}

candidato::candidato(string info) :numero(++numeroInsc){
	stringstream ss(info);
	char virgula;
	int desistiu;
	getline(ss, this->nome, ',');
	this->nome = this->nome.substr(0, this->nome.size()-1);
	getline(ss, this->morada, ',');
	this->morada = this->morada.substr(1, this->morada.size()-2);
	ss >> this->dia>> virgula >> this->mes >> virgula >> this->ano >> virgula >> this->arte >> virgula >> desistiu;

	this->desistiu = (desistiu) ? true : false;

	vector<pair<vector<int>,string> > indisp;
	string temp;
	//para saber se é o primeiro
	int flag = 1;
	while(getline(ss, temp, ';')) {
		pair<vector<int>, string> a;

		if(flag)
			temp = temp.substr(3, temp.size() - 4);
		else
			temp = temp.substr(1, temp.size() - 2);
		stringstream i(temp);
		vector<int>dia;
		int n;
		i >> n >> virgula;
		dia.push_back(n);
		i >> n >> virgula;
		dia.push_back(n);
		i >> n >> virgula;
		dia.push_back(n);
		a.first=dia;

		string razao;
		getline(i, razao);
		razao = razao.substr(1, razao.size()-1);
		a.second = razao;

		indisp.push_back(a);

		flag = 0;
	}

	this->indisponibilidades = indisp;


	ss.ignore('\n');
}

candidato::~candidato() {
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

priority_queue<sessao *> candidato::getParticipacoes() const {
	return participacoes;
}

vector<pair<vector<int>,string> > candidato::getIndisponibilidades() const {
	return indisponibilidades;
}

bool candidato::getDesistiu() const {
	return desistiu;
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

void candidato::setDesistiu(bool d) {
	desistiu = d;
}
/////////////////////////////////////////

void candidato::adicionaSessao(sessao* sessao){
	participacoes.push(sessao);
}

void candidato::removeSessao(sessao* s) {
	vector<sessao*> aux;
	while (!(participacoes.empty())) {
		if (participacoes.top()->getData() == s->getData()) {
			participacoes.pop();
			break;
		}
		aux.push_back(participacoes.top());
		participacoes.pop();
	}
	while (aux.size() > 0) {
		participacoes.push(aux[aux.size()-1]);
	}

}

bool candidato::candidatoOcupado(vector<int> data) {
	vector<sessao*> aux;

	bool flag = false;

	while (!(participacoes.empty())) {
		if (participacoes.top()->getData() == data) {
			flag = true;
			break;
		}
		aux.push_back(participacoes.top());
		participacoes.pop();
	}

	while (aux.size() > 0) {
		participacoes.push(aux[aux.size()-1]);
	}

	return flag;
}

ostream & operator<<(ostream & o, const candidato & c) {
	o << "Numero : " << c.getNumero() << endl;
	o << "Nome : " << c.getNome() << endl;
	o << "Morada : " << c.getMorada() << endl;
	o << "Data de Nascimento : " << c.getDataNascimento()[0] << "/" << c.getDataNascimento()[1] << "/" << c.getDataNascimento()[2] << endl;
	o << "Arte : " << c.getArte() << endl;
	if (c.getIndisponibilidades().size() > 0) {
		o << "Indisponibilidades:\n";
		for (unsigned int i = 0; i < c.getIndisponibilidades().size(); i++) {
			o << c.getIndisponibilidades().at(i).first[0] << "/"
					<< c.getIndisponibilidades().at(i).first[1] << "/"
					<< c.getIndisponibilidades().at(i).first[2] << ": ";
			o << c.getIndisponibilidades().at(i).second << endl;
		}
	}
	if(c.getDesistiu()) {
		o << "(desistiu)\n";
	}

	return o;
}

ofstream & operator<<(ofstream & o, const candidato & c) {
	o << c.getNome() << " , " << c.getMorada() << " , " << c.getDataNascimento()[0] << " , " << c.getDataNascimento()[1] << " , " << c.getDataNascimento()[2] << " , " << c.getArte() << " , " << c.getDesistiu();

	if(c.getIndisponibilidades().size() > 0) {
		o << " , ";
		for(unsigned int i = 0; i < c.getIndisponibilidades().size(); i++) {
			o << c.getIndisponibilidades().at(i).first[0] << " , " << c.getIndisponibilidades().at(i).first[1] << " , " << c.getIndisponibilidades().at(i).first[2] << " , ";

			if(i == (c.getIndisponibilidades().size() - 1)) {
				o << c.getIndisponibilidades().at(i).second << " ;";
			}
			else {
				o << c.getIndisponibilidades().at(i).second << " ; ";
			}

		}
	}

	return o;
}

bool candidato::operator<(const candidato c2) const{

	if(arte < c2.getArte()) {
		return true;
	}

	else if (arte == c2.getArte()) {
		if(ano > c2.getDataNascimento()[2]) {
			return true;
		}
		else if(ano == c2.getDataNascimento()[2]) {
			if(mes > c2.getDataNascimento()[1]) {
				return true;
			}
			else if(mes == c2.getDataNascimento()[1])
				return dia > c2.getDataNascimento()[0];
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
