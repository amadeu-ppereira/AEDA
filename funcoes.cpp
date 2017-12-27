#include "funcoes.h"

candidato* notF = NULL;
BST<candidato*> candidatosGlobal(notF);
vector<jurado*> juradosGlobal;
vector<sessao*> sessaoGlobal;
vector<fase1> fases1;
vector<fase2> fases2;
HashTab indisponibilidades;


int cinTeste() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
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

		if(c->getDesistiu()) {
			pair<candidato*, string> p;
			p.first = c;
			p.second = "";
			indisponibilidades.insert(p);
		}
		else
			candidatosGlobal.insert(c);

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

	ifstream f;
	f.open("sessoes.txt");
	if (!f.is_open()) {
		return 1;
	}

	ifstream g;
	g.open("fases.txt");
	if (!g.is_open()) {
		return 1;
	}


	string info;
	while (getline(f, info)) {
		sessao *s = new sessao(info);
		sessaoGlobal.push_back(s);
		if(s->sessaoConcluida()) {
			getline(g, info);
			fase1 f1(info);
			fases1.push_back(f1);
			getline(g, info);
			fase2 f2(info);
			fases2.push_back(f2);
		}
	}

	f.close();
	g.close();

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

	HashTab::iterator it1;
	for (it1 = indisponibilidades.begin(); it1 != indisponibilidades.end();
			it1++) {
		pair<candidato*, string> p;
		p = *it1;
		f << p.first << endl;
	}

	BSTItrIn<candidato*> it(candidatosGlobal);
	BSTItrIn<candidato*> temp(candidatosGlobal);
	temp.advance();

	while(!it.isAtEnd()) {

		if(temp.isAtEnd()) {
			f << it.retrieve();
			it.advance();
		}
		else {
			f << it.retrieve() << endl;
			it.advance();
			temp.advance();
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

	ofstream f;
	f.open("sessoes.txt");
	if(!f.is_open()) {
		return 1;
	}
	ofstream g;
	g.open("fases.txt");
	if(!g.is_open()) {
		return 1;
	}
	int h;
	for(unsigned int i = 0; i < sessaoGlobal.size(); i++) {
		if(i == (sessaoGlobal.size() - 1)) {
			f << sessaoGlobal.at(i);
			if(sessaoGlobal.at(i)->sessaoConcluida()) {
				h = procuraFase1(sessaoGlobal.at(i));
				g << fases1.at(h) << endl;
				h = procuraFase2(sessaoGlobal.at(i));
				g << fases2.at(h) << endl;
			}
		}
		else {
			f << sessaoGlobal.at(i) << endl;
			if(sessaoGlobal.at(i)->sessaoConcluida()) {
				h = procuraFase1(sessaoGlobal.at(i));
				g << fases1.at(h) << endl;
				h = procuraFase2(sessaoGlobal.at(i));
				g << fases2.at(h) << endl;
			}
		}
	}

	f.close();
	g.close();

	return 0;
}

int gravarFicheiros() {
	if (gravarFicheiroCandidatos()) {
		cerr << "Erro ao carregar o ficheiro 'candidatos.txt'!\n";
		return 1;
	}
	if (gravarFicheiroJurados()) {
		cerr << "Erro ao carregar o ficheiro 'jurados.txt'!\n";
		return 1;
	}
	if (gravarFicheiroSessoes()) {
		cerr << "Erro ao carregar o ficheiro 'sessoes.txt'!\n";
		return 1;
	}

	cout << "Ficheiros atualizados com sucesso!\n";

	return 0;
}

void sair() {

	do {
		cout <<"\n\n\n\n\n___________________________________________________________________________\n";
		cout <<"            __   ____  _____ ______  ____  ___     ____  _____       \n";
		cout <<"	   /  ] /    |/ ___/|      ||    ||    \\  /    |/ ___/       \n";
		cout <<"	  /  / |  o  (   \\_ |      | |  | |  _  ||   __(   \\_        \n";
		cout <<"	 /  /  |     |\\__  ||_|  |_| |  | |  |  ||  |  |\\__  \\|       \n";
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

	if (!procuraCandidato(c).isAtEnd()) {
		throw candidatoJaExiste(c->getNome());
	}
	else {
		candidatosGlobal.insert(c);
		cout << "Candidato numero " << c->getNumero() << " (" << c->getNome() << ") adicionado!\n";
		cin.get();
	}
}


void removeCandidato(int numero) {

	BSTItrIn<candidato*> it(candidatosGlobal);

	if ((it = procuraCandidato(numero)).isAtEnd()) {
		throw candidatoNaoExiste(numero);
	}

	else {
		candidato* temp = it.retrieve();
		candidatosGlobal.remove(it.retrieve());
		delete temp;
		cout << "Candidato numero " << numero << " removido!\n";
		cin.ignore(1000, '\n');;
		cin.get();
	}
}

void removeCandidato(string nome) {

	BSTItrIn<candidato*> it(candidatosGlobal);

	if ((it = procuraCandidato(nome)).isAtEnd()) {
		throw candidatoNaoExiste(nome);
	}
	else {
		candidato* temp = it.retrieve();
		candidatosGlobal.remove(it.retrieve());
		delete temp;
		cout << "Candidato " << nome << " removido!\n";
		cin.get();
	}
}

void alterarCandidato(int numero) {

	BSTItrIn<candidato*> it(candidatosGlobal);

	if ((it = procuraCandidato(numero)).isAtEnd()) {
		throw candidatoNaoExiste(numero);
	}

	candidato* temp = it.retrieve();
	candidatosGlobal.remove(it.retrieve());

	char opcao;
	do {
		cout << "Alterar morada ? (S/N) ";
		cin >> opcao;
		if (cinTeste())
			continue;

		if(opcao == 'S' || opcao == 'N') {
			break;
		}

	} while(1);

	if(opcao == 'S') {
		string morada;
		cout << "Nova morada: ";
		cin.ignore(1000, '\n');
		getline(cin, morada);
		temp->setMorada(morada);
	}

	do {
		cout << "Alterar arte perfomativa ? (S/N) ";
		cin >> opcao;
		if (cinTeste())
			continue;

		if (opcao == 'S' || opcao == 'N') {
			break;
		}

	} while (1);

	if (opcao == 'S') {
		string arte;
		cout << "Nova arte: ";
		cin.ignore(1000, '\n');
		getline(cin, arte);
		temp->setArte(arte);
	}

	pair<candidato*, string> p;

	do {
		cout << "Candidato desistiu ? (S/N) ";
		cin >> opcao;
		if (cinTeste())
			continue;

		if (opcao == 'S' || opcao == 'N') {
			break;
		}

	} while (1);

	if (opcao == 'S') {
		bool d = true;
		string s = "";
		p.first = temp;
		p.second = s;
	}


	if(temp->getDesistiu())
		indisponibilidades.insert(p);
	else
		candidatosGlobal.insert(temp);

}

void alterarCandidato(string nome) {

	BSTItrIn<candidato*> it(candidatosGlobal);

	if ((it = procuraCandidato(nome)).isAtEnd()) {
		throw candidatoNaoExiste(nome);
	}

	candidato* temp = it.retrieve();
	candidatosGlobal.remove(it.retrieve());

	char opcao;
	do {
		cout << "Alterar morada ? (S/N) ";
		cin >> opcao;
		if (cinTeste())
			continue;

		if (opcao == 'S' || opcao == 'N') {
			break;
		}

	} while (1);

	if (opcao == 'S') {
		string morada;
		cout << "Nova morada: ";
		cin.ignore(1000, '\n');
		getline(cin, morada);
		temp->setMorada(morada);
	}

	do {
		cout << "Alterar arte perfomativa ? (S/N) ";
		cin >> opcao;
		if (cinTeste())
			continue;

		if (opcao == 'S' || opcao == 'N') {
			break;
		}

	} while (1);

	if (opcao == 'S') {
		string arte;
		cout << "Nova arte: ";
		cin.ignore(1000, '\n');
		getline(cin, arte);
		temp->setArte(arte);
	}

	pair<candidato*, string> p;

	do {
		cout << "Candidato desistiu ? (S/N) ";
		cin >> opcao;
		if (cinTeste())
			continue;

		if (opcao == 'S' || opcao == 'N') {
			break;
		}

	} while (1);

	if (opcao == 'S') {
		bool d = true;
		string s = "";
		p.first = temp;
		p.second = s;
	}

	if (temp->getDesistiu())
		indisponibilidades.insert(p);
	else
		candidatosGlobal.insert(temp);
}


void infoCandidato(int numero) {

	BSTItrIn<candidato*> it(candidatosGlobal);

	it= procuraCandidato(numero);
	if (it.isAtEnd()) {
		throw candidatoNaoExiste(numero);

	}
	cout << it.retrieve() << endl;

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
			jurado* temp = juradosGlobal.at(i);
			juradosGlobal.erase(juradosGlobal.begin() + i);
			delete temp;
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

BSTItrIn<candidato*> procuraCandidato(candidato *c) {

	BSTItrIn<candidato*> it(candidatosGlobal);

	while(! it.isAtEnd()) {
		if (it.retrieve()->getNumero() == c->getNumero() && it.retrieve()->getNome() == c->getNome())
			return it; // encontrou
		it.advance();
	}

	return it;

}

BSTItrIn<candidato*> procuraCandidato(int numero) {

	BSTItrIn<candidato*> it(candidatosGlobal);

	while(! it.isAtEnd()) {
		if (it.retrieve()->getNumero() == numero)
			return it; // encontrou
		it.advance();
	}

	return it;
}

BSTItrIn<candidato*> procuraCandidato(string nome) {

	BSTItrIn<candidato*> it(candidatosGlobal);

	while(! it.isAtEnd()) {
		if (it.retrieve()->getNome() == nome)
			return it; // encontrou
		it.advance();
	}

	return it;

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

int procuraSessao(string generoArte,vector<int> data) {

	for (unsigned int i = 0; i < sessaoGlobal.size(); i++){
		if (sessaoGlobal.at(i)->getGeneroArte() == generoArte && sessaoGlobal.at(i)->getData() == data)
			return i; // encontrou
	}
	return -1;

}

int procuraSessao(sessao *s) {

	for (unsigned int i = 0; i < sessaoGlobal.size(); i++){
		if (sessaoGlobal.at(i)->getGeneroArte() == s->getGeneroArte() && sessaoGlobal.at(i)->getData() == s->getData())
			return i; // encontrou
	}
	return -1;

}

void adicionaSessao(sessao *s) {

	if (procuraSessao(s) != -1) {
		throw sessaoJaExiste(s->getGeneroArte(), s->getData());
	} else {
		sessaoGlobal.push_back(s);
		cout << "Sessao adicionada com sucesso!\n";
		cin.get();
	}
}

void removeSessao(string generoArte,vector<int> data) {

	int i = procuraSessao(generoArte, data);
	if (i == -1) {
		throw sessaoNaoExiste(generoArte, data);
	} else {

		sessao* temp = sessaoGlobal.at(i);
		if(sessaoGlobal.at(i)->sessaoConcluida()) {
			removeFases(sessaoGlobal.at(i));
		}

		sessaoGlobal.erase(sessaoGlobal.begin() + i);
		delete temp;
		cout << "Sessao removida com sucesso!\n";
		cin.get();
	}
}

void removeFases(sessao* s) {

	int i;
	if((i = procuraFase1(s)) != -1) {
		fases1.erase(fases1.begin()+ i);
	}
	if((i = procuraFase2(s)) != -1) {
		fases2.erase(fases2.begin()+ i);
	}
}


vector<int> candidatosDisponiveis(sessao* s) {

	BSTItrIn<candidato*> it(candidatosGlobal);

	vector<int> numeros;
	while(!it.isAtEnd()) {
		if(it.retrieve()->getArte() == s->getGeneroArte() && !it.retrieve()->candidatoOcupado(s->getData())) {
			cout << it.retrieve() << endl;
			numeros.push_back(it.retrieve()->getNumero());
			it.advance();
		}
	}

	return numeros;
}

vector<string> juradosDisponiveis(sessao* s) {

	vector<string> nomes;
	for(unsigned int i = 0;  i < juradosGlobal.size(); i++) {
		if(juradosGlobal.at(i)->getArte() == s->getGeneroArte() && !juradosGlobal.at(i)->juradoOcupado(s->getData())) {
			cout << juradosGlobal.at(i) << endl;
			nomes.push_back(juradosGlobal.at(i)->getNome());
		}
	}

	return nomes;
}

void adicionaCandidatoSessao(int n, sessao* s) {

	BSTItrIn<candidato*> it(candidatosGlobal);

	it = procuraCandidato(n);
	if(it.retrieve()->candidatoOcupado(s->getData())) {
		throw candidatoOcupado(n, s->getData());
	}

	s->adicionaCandidato(it.retrieve());
	it.retrieve()->adicionaSessao(s);
	cout << "Candidato Adicionado!\n";


}

void adicionaJuradoSessao(string nome, sessao* s) {

	int i = procuraJurado(nome);
	if(juradosGlobal.at(i)->juradoOcupado(s->getData())) {
		throw juradoOcupado(nome, s->getData());
	}

	s->adicionaJurado(juradosGlobal.at(i));
	juradosGlobal.at(i)->adicionaSessao(s);
	cout << "Jurado Adicionado!\n";
}

void displayInfoSessao(string arte, vector<int> data) {

	int i = procuraSessao(arte, data);
	if (i == -1) {
		throw sessaoNaoExiste(arte, data);
	}

	cout << sessaoGlobal.at(i) << endl;

	if(sessaoGlobal.at(i)->sessaoConcluida() == true) {
		cout << "\nEsta sessao já foi concluida!\n\n";

		int j = procuraFase2(sessaoGlobal.at(i));
		fases2.at(j).displayVencedor();
	}

	cin.get();


}

void comecarSessao(string arte, vector<int> data) {

	int i = procuraSessao(arte, data);
	if (i == -1) {
		throw sessaoNaoExiste(arte, data);
	}

	if(sessaoGlobal.at(i)->sessaoConcluida() == true) {
		cout << "Esta sessao já foi concluida!\n\n";

		return;
	}

	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Vamos comecar a 1 fase                        |\n";
	cout << "+------------------------------------------------+\n\n";

	fase1 novafase1(sessaoGlobal.at(i));
	novafase1.atribuiPontuacoes();
	novafase1.ordenaPontuacoes();
	fases1.push_back(novafase1);


	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Vamos comecar a 2 fase                        |\n";
	cout << "+------------------------------------------------+\n\n";

	fase2 novafase2(novafase1, sessaoGlobal.at(i));
	novafase2.atribuiPontuacoes();
	novafase2.displayVencedor();

	fases2.push_back(novafase2);

	sessaoGlobal.at(i)->setConcluida(true);

}

int procuraFase1 (sessao *s){

	for (unsigned int i = 0; i < fases1.size(); i++)
			if (fases1.at(i).getSessao() == s)
				return i; // encontrou
	return -1;

}

int procuraFase2 (sessao *s){

	for (unsigned int i = 0; i < fases2.size(); i++)
			if (fases2.at(i).getSessao() == s)
				return i; // encontrou
	return -1;

}

