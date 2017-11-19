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

fase1::fase1() {

}

void fase1::atribuiPontuacoes(candidato *c , vector<float> classjurados){

	float m = (classjurados[0] + classjurados[1] + classjurados[2])/3;
	Classificacao cf = {c , classjurados[0] , classjurados[1] , classjurados[2], m};
	classificacoes1fase.push_back(cf);
}

vector<candidato*> fase1::getCandidatos() const {
	vector<candidato*> candidatos1fase;
	for(unsigned int i = 0; i < classificacoes1fase.size(); i++) {
		candidatos1fase.push_back(classificacoes1fase.at(i).c);
	}
	return candidatos1fase;
}

fase2::fase2() {

}

void fase2::passagem2fase(){


	if (classificacoes1fase.size() >= 5){
		for (unsigned int i = 0 ; i < 5 ; i++){
			candidatos2fase.push_back(classificacoes1fase.at(i).c);
		}
	}

	else candidatos2fase = getCandidatos();

}

void fase2::ordenar2fase(){


	for (unsigned int i = 0 ; i < classificacoes2fase.size() ; i++){
		float m = (classificacoes2fase[i].j1 * 2 + classificacoes2fase[i].j2 + classificacoes2fase[i].j3)/3;
		classificacoes2fase[i].media = m;
	}

	bubbleSortClassificacoes(classificacoes2fase);

}

void fase2::atribuiPontuacoes(candidato *c , vector<float> classjurados){

	float m = (classjurados[0]*2 + (classjurados[1] + classjurados[2])/2)/3;
	Classificacao cf = {c , classjurados[0] , classjurados[1] , classjurados[2], m};
	classificacoes1fase.push_back(cf);
}

void fase2::displayVencedor(){

	cout << " _\\|/^              " << classificacoes2fase[0].c->getNome() << endl;
    cout << "  (_oo /\n";
	cout << " /-|--/              Parabéns!! Ganhou !!!" << endl;
	cout << " \\ |\n";
	cout << "   /--i              PONTUACAO :"<< classificacoes2fase[0].media << " P" << endl;
	cout << "  /   L\n";
	cout << "  L\n";


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
			cout << s->getCandidatos().at(i)->getNumero() << endl;
		}
		else {
			cout << s->getCandidatos().at(i)->getNumero() << ", ";
		}
	}
	o << "Jurados: ";
	for (unsigned int i = 0; i < s->getJurados().size(); i++) {
		if(i == 0) {
			cout << s->getJurados().at(i)->getNome() << "(principal), ";
		}
		else if (i == s->getJurados().size() - 1) {
			cout << s->getJurados().at(i)->getNome() << endl;
		}

		else {cout << s->getJurados().at(i)->getNome() << ", ";

		}
	}

	return o;
}

bool sessao::sessaoConcluida() const {
	return concluida;
}



