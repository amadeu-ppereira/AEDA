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


void infoCandidato() {

}


void adicionaJurado() {

}


void removeJurado() {

}

void infoJurado() {

}

int procuraCandidato(candidato *c) {

	for (unsigned int i = 0; i < candidatosGlobal.size(); i++)
		if (candidatosGlobal.at(i)->getNome() == c->getNome() || candidatosGlobal.at(i)->getNumero() == c->getNumero())
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
