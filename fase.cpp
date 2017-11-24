#include "fase.h"
#include "candidato.h"
#include "funcoes.h"



sessao* fase1::getSessao() {
	return s;
}


sessao* fase2::getSessao() {
	return s;
}


fase::fase() {

}

fase::~fase() {

}

fase1::fase1(sessao* s) : fase(){
	this->s = s;
}

fase1::fase1(string info) : fase() {

	stringstream ss(info);
	char virgula;
	string arte;
	vector<int> data(3);
	string nome;
	int c1, c2, c3;

	getline(ss, arte, ',');
	arte = arte.substr(0, arte.size() - 1);
	ss >> data[0] >> virgula >> data[1] >> virgula >> data[2] >> virgula;
	int i = procuraSessao(arte, data);
	this->s = sessaoGlobal.at(i);

	vector<Classificacao> classificacoes;
	Classificacao classif;
	string newInfo;
	while(getline(ss, newInfo, ';')) {
		newInfo = newInfo.substr(1, newInfo.size() - 1);
		stringstream newss(newInfo);
		getline(newss, nome, ',');
		nome = nome.substr(0, nome.size() - 1);
		newss >> c1 >> virgula >> c2 >> virgula >> c3;
		i = procuraCandidato(nome);
		if(i == -1) {
			break;
		}
		classif.c = candidatosGlobal.at(i);
		classif.j1 = c1;
		classif.j2 = c2;
		classif.j3 = c3;
		classif.media = (c1+c2+c3)/3;

		classificacoes.push_back(classif);
	}

	classificacoes1fase = classificacoes;

}


void fase1::atribuiPontuacoes(){

	for(unsigned int i = 0;i < s->getCandidatos().size(); i++) {
		Classificacao cl;
		cl.c = s->getCandidatos().at(i);
		float pontuacao;

		cout << "\n _\\|/^      " << endl;
		cout << "  (_oo \n";
		cout << "   | " << endl;
		cout << "  /|\\ \n";
		cout << "   |\n" ;
		cout << "   LL\n";
		cout << "\nCandidato n "<< s->getCandidatos()[i]->getNumero() << "(" << s->getCandidatos()[i]->getNome() << ")" << endl;
		cout << "-------------------\n";
		cout << "Pontuacao do jurado 1 (principal): ";
		cin >> pontuacao;
		cl.j1 = pontuacao;
		cout << "Pontuacao do jurado 2: ";
		cin >> pontuacao;
		cl.j2 = pontuacao;
		cout << "Pontuacao do jurado 3: ";
		cin >> pontuacao;
		cl.j3 = pontuacao;

		cl.media = (cl.j1 + cl.j2 + cl.j3)/3;

		classificacoes1fase.push_back(cl);

	}
}

void fase1::ordenaPontuacoes(){

	for (unsigned int j = classificacoes1fase.size() - 1; j > 0; j--) {
		bool troca = false;
		for (unsigned int i = 0; i < j; i++)
			if (classificacoes1fase[i + 1].media > classificacoes1fase[i].media) {
				swap(classificacoes1fase[i], classificacoes1fase[i + 1]);
				troca = true;
			}
		if (!troca)
			return;
	}

}

vector<Classificacao> fase1::getClassificacoes() const {
	return classificacoes1fase;
}

fase2::fase2(fase1 f , sessao* s) : fase(){
	this->s = s;

	vector<candidato*> candidatos;
	if (f.getClassificacoes().size() >= 5){
		for (unsigned int i = 0 ; i < 5 ; i++){
			candidatos.push_back(f.getClassificacoes().at(i).c);
		}
	}

	else {
		for (unsigned int i = 0; i < f.getClassificacoes().size(); i++) {
			candidatos.push_back(f.getClassificacoes().at(i).c);
		}
	}

	candidatos2fase = candidatos;
}

fase2::fase2(string info) : fase() {

	stringstream ss(info);
	char virgula;
	string arte;
	vector<int> data(3);
	string nome;
	int c1, c2, c3;

	getline(ss, arte, ',');
	arte = arte.substr(0, arte.size() - 1);
	ss >> data[0] >> virgula >> data[1] >> virgula >> data[2] >> virgula;

	int i = procuraSessao(arte, data);
	this->s = sessaoGlobal.at(i);

	vector<candidato*> candidatos;
	vector<Classificacao> classificacoes;
	Classificacao classif;
	string newInfo;
	while (getline(ss, newInfo, ';')) {
		newInfo = newInfo.substr(1, newInfo.size() - 1);
		stringstream newss(newInfo);
		getline(newss, nome, ',');
		nome = nome.substr(0, nome.size() - 1);
		newss >> c1 >> virgula >> c2 >> virgula >> c3;

		i = procuraCandidato(nome);
		if(i == -1) {
			break;
		}
		candidatos.push_back(candidatosGlobal.at(i));

		classif.c = candidatosGlobal.at(i);
		classif.j1 = c1;
		classif.j2 = c2;
		classif.j3 = c3;
		classif.media = (c1 + c2 + c3) / 3;

		classificacoes.push_back(classif);
	}

	classificacoes2fase = classificacoes;
	candidatos2fase = candidatos;
}


void fase2::ordenaPontuacoes(){

	for (unsigned int j = classificacoes2fase.size() - 1; j > 0; j--) {
		bool troca = false;
		for (unsigned int i = 0; i < j; i++)
			if (classificacoes2fase[i + 1].media > classificacoes2fase[i].media) {
				swap(classificacoes2fase[i], classificacoes2fase[i + 1]);
				troca = true;
			}
		if (!troca)
			return;
	}

}

void fase2::atribuiPontuacoes() {

	for (unsigned int i = 0; i < candidatos2fase.size(); i++) {
		Classificacao cl;
		cl.c = candidatos2fase.at(i);
		float pontuacao;

		cout << "\n _\\|/^      " << endl;
		cout << "  (_oo \n";
		cout << "   | " << endl;
		cout << "  /|\\ \n";
		cout << "   |\n";
		cout << "   LL\n";
		cout << "\nCandidato n " << candidatos2fase[i]->getNumero() << "(" << candidatos2fase[i]->getNome() << ")" << endl;
		cout << "-------------------\n";
		cout << "Pontuacao do jurado 1 (principal): ";
		cin >> pontuacao;
		cl.j1 = pontuacao;
		cout << "Pontuacao do jurado 2: ";
		cin >> pontuacao;
		cl.j2 = pontuacao;
		cout << "Pontuacao do jurado 3: ";
		cin >> pontuacao;
		cl.j3 = pontuacao;

		cl.media = (cl.j1 * 2 + cl.j2 + cl.j3) / 4;

		classificacoes2fase.push_back(cl);

	}
}


void fase2::displayVencedor(){

	ordenaPontuacoes();
	cout << "\n\n _\\|/^                    " << classificacoes2fase[0].c->getNome() << endl;
    cout << "  (_oo /\n";
	cout << " /-|--/              Parabéns!! Ganhou !!!" << endl;
	cout << " \\ |\n";
	cout << "   /--i              PONTUACAO : "<< classificacoes2fase[0].media << endl;
	cout << "  /   L\n";
	cout << "  L\n";

}

vector<Classificacao> fase2::getClassificacoes() const {
	return classificacoes2fase;
}


ostream & operator<<(ostream & o, fase1 f) {

	sessao* s = f.getSessao();
	vector<int> data = s->getData();

	o << s->getGeneroArte();
	o << " , " << data[0] << " , " << data[1] << " , " << data[2] << " , ";

	for(unsigned int i = 0; i < f.getClassificacoes().size(); i++) {
		o << f.getClassificacoes().at(i).c->getNome();
		o << " , " << f.getClassificacoes().at(i).j1 << " , " << f.getClassificacoes().at(i).j2 << " , " << f.getClassificacoes().at(i).j3 << " ; ";
	}

	return o;

}

ostream & operator<<(ostream & o, fase2 f) {

	sessao* s = f.getSessao();
	vector<int> data = s->getData();

	o << s->getGeneroArte();
	o << " , " << data[0] << " , " << data[1]	<< " , " << data[2] << " , ";

	for (unsigned int i = 0; i < f.getClassificacoes().size(); i++) {
		o << f.getClassificacoes().at(i).c->getNome();
		o << " , "<< f.getClassificacoes().at(i).j1 << " , "<< f.getClassificacoes().at(i).j2 << " , "<< f.getClassificacoes().at(i).j3 << " ; ";
	}

	return o;
}

