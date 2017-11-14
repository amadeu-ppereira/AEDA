#include "candidato.h"

int candidato::numeroInsc = 0;


candidato::candidato() : numero(++numeroInsc){


}

candidato::candidato(string nome , string morada  , int dia , int mes , int ano,  string arte) :
		numero(++numeroInsc)  {
	this->nome = nome;
	this->morada = morada;
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
	this->arte = arte;

}

candidato::~candidato() {
	// TODO Auto-generated destructor stub
}



