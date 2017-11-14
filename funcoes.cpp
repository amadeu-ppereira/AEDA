#include "funcoes.h"

vector<candidato*> candidatosGlobal;
vector<jurado*> juradosGlobal;
vector<sessao*> sessaoGlobal;


int cinTeste() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		return 1;
	}
	return 0;
}

int lerFicheiroCandidatos(string file) {
	return 0;
}

int lerFicheiroJurados(string file) {
	return 0;
}

int lerFicheiroSessoes(string file) {
	return 0;
}

void sair() {

}

void adicionaCandidato(candidato *c) {

	if (procuraCandidato(c) != -1) {
		throw candidatoJaExiste(c->getNome());
	}
	else {
		candidatosGlobal.push_back(c);
		cout << "Candidato numero " << c->getNumero() << " (" << c->getNome() << ") adicionado!\n";
		cin.get();
	}
}


void removeCandidato(int numero) {

	int i;
	if (i = procuraCandidato(numero) == -1) {
		throw candidatoNaoExiste(numero);
	}
	else {
		candidatosGlobal.erase(candidatosGlobal.begin() + i);
		cout << "Candidato numero " << numero << " removido!\n";
		cin.get();
	}
}

void removeCandidato(string nome) {

	int i;
	if (i = procuraCandidato(nome) == -1) {
		throw candidatoNaoExiste(nome);
	}
	else {
		candidatosGlobal.erase(candidatosGlobal.begin() + i);
		cout << "Candidato " << nome << " removido!\n";
		cin.get();
	}
}


void infoCandidato(int numero) {

	int i;
	if (i = procuraCandidato(numero) == -1) {
		throw candidatoNaoExiste(numero);

	}
	cout << "Numero : " << candidatosGlobal.at(i)->getNumero() << endl;
	cout << "Nome : " << candidatosGlobal.at(i)->getNome() << endl;
	cout << "Morada : " << candidatosGlobal.at(i)->getMorada() << endl;
	cout << "Data de Nascimento : " << candidatosGlobal.at(i)->getDataNascimento()[0] << "/" << candidatosGlobal.at(i)->getDataNascimento()[1] << "/" << candidatosGlobal.at(i)->getDataNascimento()[2] << endl;
	cout << "Arte : " << candidatosGlobal.at(i)->getArte() << endl;

}

void infoCandidato(candidato *c) {

	cout << "Numero : " << c->getNumero() << endl;
	cout << "Nome : " << c->getNome() << endl;
	cout << "Morada : " << c->getMorada() << endl;
	cout << "Data de Nascimento : " << c->getDataNascimento()[0] << "/" << c->getDataNascimento()[1] << "/" << c->getDataNascimento()[2] << endl;
	cout << "Arte : " << c->getArte() << endl;

}


void adicionaJurado() {

}


void removeJurado() {

}

void infoJurado() {

}

int procuraCandidato(candidato *c) {

	for (unsigned int i = 0; i < candidatosGlobal.size(); i++)
		if (candidatosGlobal.at(i)->getNumero() == c->getNumero() || candidatosGlobal.at(i)->getNome() == c->getNome())
			return i; // encontrou

	return -1;

}

int procuraCandidato(int numero) {

	for (unsigned int i = 0; i < candidatosGlobal.size(); i++)
		if (candidatosGlobal.at(i)->getNumero() == numero)
			return i; // encontrou

	return -1;

}

int procuraCandidato(string nome) {

	for (unsigned int i = 0; i < candidatosGlobal.size(); i++)
		if (candidatosGlobal.at(i)->getNome() == nome)
			return i; // encontrou

	return -1;

}
