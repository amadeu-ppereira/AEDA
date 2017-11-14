#include "candidato.h"

int candidato::numeroInsc = 0;


candidato::candidato(int dia = 0 , int mes = 0 , int ano = 0) : numero(++numeroInsc){
	this-> dia = dia;
	this->mes = mes;
	this->ano = ano;

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



