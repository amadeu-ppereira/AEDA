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
		cin.ignore();
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

	int i= procuraCandidato(numero);
	if (i == -1) {
		throw candidatoNaoExiste(numero);

	}
	cout << candidatosGlobal.at(i) << endl;

}

void infoCandidato(candidato *c) {

	cout << c << endl;

}


void adicionaJurado(jurado *j) {

	if (procuraJurado(j) != -1) {
			throw JuradoJaExiste(j ->getNome());
		}
	else {
			juradosGlobal.push_back(j);
			cout << "Jurado "<< j->getNome() << " adicionado!\n";
			cin.get();
		}

}

void removeJurado(string nome) {

	int i= procuraJurado(nome);
		if (i  == -1) {
			throw JuradoNaoExiste(nome);
		}
		else {
			juradosGlobal.erase(juradosGlobal.begin() + i);
			cout << "Jurado " << nome << " removido!\n";
			cin.get();
		}

}

void infoJurado(string nome) {

	int i= procuraJurado(nome);
	if (i == -1) {
		throw JuradoNaoExiste(nome);

	}
	cout << juradosGlobal.at(i) << endl;

}

void infoJurado(jurado *j) {

	cout << j << endl;

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

int procuraJurado (jurado *j){

	for (unsigned int i = 0; i < juradosGlobal.size(); i++)
			if (juradosGlobal.at(i)->getNome() == j->getNome())
				return i; // encontrou
	return -1;

}

int procuraJurado (string nome){

	for (unsigned int i = 0; i < juradosGlobal.size(); i++)
			if (juradosGlobal.at(i)->getNome() == nome)
				return i; // encontrou

		return -1;


}


