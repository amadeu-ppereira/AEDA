#include "sessao.h"
#include "funcoes.h"




sessao::sessao() {
	this->dia=0;
	this->mes=0;
	this->ano=0;
	this->concluida = false;
}



sessao::sessao(string generoArte,vector<int> data) {
	this->generoArte = generoArte;
	this->dia = data[0];
	this->mes = data[1];
	this->ano = data[2];
	this->concluida = false;


}

sessao::sessao(string info) {

	vector<jurado*> j;
	string nome;
	int i, concluida;
	stringstream ss(info);
	char virgula;

	ss >> concluida >> virgula;
	this->concluida = (concluida == 1) ? true : false;
	getline(ss, this->generoArte, ',');
	this->generoArte = this->generoArte.substr(1, this->generoArte.size()-2);
	ss >> this->dia >> virgula >> this->mes >> virgula >> this->ano >> virgula;

	getline(ss, nome, ',');
	nome = nome.substr(1, nome.size() - 2);
	i = procuraJurado(nome);
	j.push_back(juradosGlobal.at(i));
	juradosGlobal.at(i)->adicionaSessao(this);

	getline(ss, nome, ',');
	nome = nome.substr(1, nome.size() - 2);
	i = procuraJurado(nome);
	j.push_back(juradosGlobal.at(i));
	juradosGlobal.at(i)->adicionaSessao(this);

	getline(ss, nome, ',');
	nome = nome.substr(1, nome.size() - 2);
	i = procuraJurado(nome);
	j.push_back(juradosGlobal.at(i));
	juradosGlobal.at(i)->adicionaSessao(this);

	jurados = j;

	vector<candidato*> c;
	while(getline(ss, nome, ',')) {
		nome = nome.substr(1, nome.size() - 2);
		BSTItrIn<candidato*> it(candidatosGlobal);
		it = procuraCandidato(nome);
		if(it.isAtEnd()) {
			break;
		}
		c.push_back(it.retrieve());

		it.retrieve()->adicionaSessao(this);
	}

	candidatos = c;


}


sessao::~sessao() {
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

void sessao::setConcluida(bool c) {
	this->concluida = c;
}

vector<int> sessao::getData() const
{
	vector<int> data;
	data.push_back(dia);
	data.push_back(mes);
	data.push_back(ano);
	return data;
}

string sessao::getGeneroArte() const
{
	return generoArte;
}

int sessao::getNumeroJurados() const {
	return jurados.size();
}

vector<candidato*> sessao::getCandidatos() const {
	return candidatos;
}

vector<jurado*> sessao::getJurados() const {
	return jurados;
}

void sessao::adicionaCandidato(candidato *c) {
	candidatos.push_back(c);
}

void sessao::adicionaJurado(jurado* j) {
	jurados.push_back(j);
}


ostream & operator<<(std::ostream &out, const sessaoJaExiste &s)
{
	out << "Ja existe uma sessao de " << s.generoArte << " no dia " << s.data[0]
		<< '/' << s.data[1] << '/' << s.data[2] << " !\n";
	return out;
}

std::ostream & operator<<(std::ostream &out, const sessaoNaoExiste &s)
{
	out << "Sessao do genero " << s.generoArte << " no dia " << s.data[0] << '/'
			<< s.data[1] << '/' << s.data[2] << " nao existe!\n";
	return out;
}

ostream & operator<<(ostream & o, const sessao * s) {


	o << "Arte: " << s->getGeneroArte() << endl;
	o << "Data: " << s->getData()[0] << "/" << s->getData()[1] << "/"  << s->getData()[2] << endl;
	o << "Candidatos (numeros): ";
	for(unsigned int i = 0;  i < s->getCandidatos().size(); i++) {
		if(i == s->getCandidatos().size() - 1) {
			o << s->getCandidatos().at(i)->getNumero() << "\n";
		}
		else {
			o << s->getCandidatos().at(i)->getNumero() << ", ";
		}
	}
	o << "Jurados: ";
	for (unsigned int i = 0; i < s->getJurados().size(); i++) {
		if(i == 0) {
			o << s->getJurados().at(i)->getNome() << "(principal)";
		}
		else {
			o << " , " << s->getJurados().at(i)->getNome();

		}
	}
		o << endl;
	return o;
}

bool sessao::sessaoConcluida() const {
	return concluida;
}

ofstream & operator<<(ofstream & o, const sessao * s) {
	int flag = (s->sessaoConcluida()) ? 1 : 0;
	o << flag << " , ";

	o << s->getGeneroArte() << " , " << s->getData()[0] << " , " << s->getData()[1] << " , " << s->getData()[2] << " , ";
	for (unsigned int i = 0; i < s->getJurados().size(); i++) {
		o << s->getJurados().at(i)->getNome() << " , ";
	}

	for (unsigned int i = 0; i < s->getCandidatos().size(); i++) {
		o << s->getCandidatos().at(i)->getNome() << " , ";
	}

	return o;

}


bool sessao::operator < (const sessao* &s) const
{
	if(this->ano>s->getData()[2])
		return true;
	if(this->ano==s->getData()[2]){
		if(this->mes>s->getData()[1])
			return true;
		if(this->mes==s->getData()[1])
		{
			if(this->dia>s->getData()[0])
				return true;
		}
	}
	return false;
}
