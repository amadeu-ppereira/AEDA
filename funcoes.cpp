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

int lerFicheiroCandidatos(){
	ifstream f;
	f.open("candidatos.txt");
	if(!f.is_open()) {
		return 1;
	}

	string info;
	while(getline(f, info)) {
		candidato *c = new candidato(info);
		candidatosGlobal.push_back(c);
	}

	f.close();

	return 0;
}

int lerFicheiroJurados() {
	ifstream f;
	f.open("jurados.txt");
	if (!f.is_open()) {
		return 1;
	}

	string info;
	while (getline(f, info)) {
		jurado *j = new jurado(info);
		juradosGlobal.push_back(j);
	}

	f.close();

	return 0;
}

int lerFicheiroSessoes() {
	return 0;
}

int lerFicheiros() {
	if(lerFicheiroCandidatos()) {
		cerr << "Erro ao carregar o ficheiro 'candidatos.txt'!\n";
		return 1;
	}
	if (lerFicheiroJurados()) {
		cerr << "Erro ao carregar o ficheiro 'jurados.txt'!\n";
		return 1;
	}
	if(lerFicheiroSessoes()) {
		cerr << "Erro ao carregar o ficheiro 'sessoes.txt'!\n";
		return 1;
	}

	cout << "Ficheiros carregados com sucesso!\n";

	return 0;
}

int gravarFicheiroCandidatos() {
	ofstream f;
	f.open("candidatos.txt");
	if (!f.is_open()) {
		return 1;
	}

	for(unsigned int i = 0; i < candidatosGlobal.size(); i++) {
		if(i == (candidatosGlobal.size() - 1)) {
			f << candidatosGlobal.at(i);
		}
		else {
			f << candidatosGlobal.at(i) << endl;
		}
	}

	f.close();
	return 0;
}

int gravarFicheiroJurados() {
	ofstream f;
	f.open("jurados.txt");
	if (!f.is_open()) {
		return 1;
	}

	for(unsigned int i = 0; i < juradosGlobal.size(); i++) {
		if(i == (juradosGlobal.size() - 1)) {
			f << juradosGlobal.at(i);
		}
		else {
			f << juradosGlobal.at(i) << endl;
		}
	}

	f.close();
	return 0;
}

int gravarFicheiroSessoes() {
	return 0;
}

int gravarFicheiros() {
	if (lerFicheiroCandidatos()) {
		cerr << "Erro ao carregar o ficheiro 'candidatos.txt'!\n";
		return 1;
	}
	if (lerFicheiroJurados()) {
		cerr << "Erro ao carregar o ficheiro 'jurados.txt'!\n";
		return 1;
	}
	if (lerFicheiroSessoes()) {
		cerr << "Erro ao carregar o ficheiro 'sessoes.txt'!\n";
		return 1;
	}

	cout << "Ficheiros atualizados com sucesso!\n";

	return 0;
}

void sair() {

	do {
		cout <<"___________________________________________________________________________\n";
		cout <<"            __   ____  _____ ______  ____  ___     ____  _____       \n";
		cout <<"	   /  ] /    |/ ___/|      ||    ||    \\  /    |/ ___/       \n";
		cout <<"	  /  / |  o  (   \\_ |      | |  | |  _  ||   __(   \\_        \n";
		cout <<"	 /  /  |     |\\__  ||_|  |_| |  | |  |  ||  |  |\\__  \|       \n";
		cout <<"	/   \\_ |  _  |/  \\ |  |  |   |  | |  |  ||  |_ |/  \\ |       \n";
		cout <<"	\\     ||  |  |\\    |  |  |   |  | |  |  ||     |\\    |       \n";
		cout <<"	 \\____||__|__| \\___|  |__|  |____||__|__||___,_| \\___|       \n";
		cout <<"___________________________________________________________________________\n\n";

		char opcao;
		cout << "Atualizar ficheiros ? (S/N) ";
		cin >> opcao;
		if(cinTeste())
			continue;

		switch(opcao) {
		case 'S':
			gravarFicheiros();
			cin.get();
			return;
			break;
		case 'N':
			return;
			break;
		default:
			break;
		}
	}while(1);
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


