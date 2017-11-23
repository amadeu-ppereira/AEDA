#include "fase.h"
#include "candidato.h"

fase1::fase1(sessao* s) : fase(s){
	this->s = s;
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
		cout << "\nCandidato n "<< s->getCandidatos()[i]->getNumero() << endl;
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

fase2::fase2(fase1 f , sessao* s) : fase(s){

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
		cout << "\nCandidato n " << candidatos2fase[i]->getNumero() << endl;
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
