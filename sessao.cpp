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
	vector<pair <candidato*, bool> > c;
	while(getline(ss, nome, ',')) {
		int desistiu;
		nome = nome.substr(1, nome.size() - 2);
		BSTItrIn<candidato*> it(candidatosGlobal);
		it = procuraCandidato(nome);
		if(it.isAtEnd()) {
			break;
		}
		ss >> desistiu >> virgula;
		bool d = (desistiu == 1) ? true : false;

		pair<candidato*, bool> a(it.retrieve(), d);

		c.push_back(a);
		if(!d)
			it.retrieve()->adicionaSessao(this);
	}

	candidatos = c;


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

vector<pair <candidato*, bool> > sessao::getCandidatos() const {
	return candidatos;
}

vector<jurado*> sessao::getJurados() const {
	return jurados;
}

void sessao::adicionaCandidato(candidato *c) {
	pair<candidato*, bool> temp;
	temp.first = c;
	temp.second = false;

	candidatos.push_back(temp);
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
			if(s->getCandidatos().at(i).second)
				o << s->getCandidatos().at(i).first->getNumero() << " (desistiu)" << "\n";
			else
				o << s->getCandidatos().at(i).first->getNumero() << "\n";
		}
		else {
			if(s->getCandidatos().at(i).second)
				o << s->getCandidatos().at(i).first->getNumero() << " (desistiu)" << ", ";
			else
				o << s->getCandidatos().at(i).first->getNumero() << ", ";
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
		o << s->getCandidatos().at(i).first->getNome() << " , ";
		if(s->getCandidatos().at(i).second)
			o << "1" << " , ";
		else
			o << "0" << " , ";
	}

	return o;

}

