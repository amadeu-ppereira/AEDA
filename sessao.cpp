#include "sessao.h"
#include "funcoes.h"

sessao::sessao() {
	this->dia=0;
	this->mes=0;
	this->ano=0;
}


sessao::sessao(string generoArte,int data[3]) {
	this->generoArte = generoArte;

}

sessao::~sessao() {
	// TODO Auto-generated destructor stub
}

void sessao::setArte(string generoArte)
{
	this->generoArte=generoArte;
}

void sessao::setData(int data[3])
{
	this->dia=data[0];
	this->mes=data[1];
	this->ano=data[2];
}

vector<int> sessao::getData()
{
	vector<int> data;
	data.push_back(dia);
	data.push_back(mes);
	data.push_back(ano);
	return data;
}

string sessao::getGeneroArte()
{
	return generoArte;
}

void sessao::adicionaCandidato(candidato *c) {
	candidatos.push_back(c);
}

void fase1::atribuiPontuacoes(candidato *c , float classjurados[3]){

	float m = (classjurados[0] + classjurados[1] + classjurados[2])/3;
	Classificacao cf = {c , classjurados[0] , classjurados[1] , classjurados[2], m};
	classificacoes1fase.push_back(cf);
}


void fase2::passagem2fase(){


	if (classificacoes1fase.size() >= 5){
		for (unsigned int i = 0 ; i < 5 ; i++){
			classificacoes2fase.push_back(classificacoes1fase[i]);
		}
	}

	else classificacoes2fase = classificacoes1fase;

}

void fase2::ordenar2fase(){

	for (unsigned int i = 0 ; i < classificacoes2fase.size() ; i++){
		float m = (classificacoes2fase[i].j1 * 2 + classificacoes2fase[i].j2 + classificacoes2fase[i].j3)/3;
		classificacoes2fase[i].media = m;
	}

	bubbleSortClassificacoes(classificacoes2fase);



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




