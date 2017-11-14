#include "funcoes.h"
#include "menus.h"
using namespace std;


int main()
{
	cout <<"___________________________________________________________________________\n";
	cout <<"            __   ____  _____ ______  ____  ___     ____  _____       \n";
	cout <<"	   /  ] /    |/ ___/|      ||    ||    \\  /    |/ ___/       \n";
	cout <<"	  /  / |  o  (   \\_ |      | |  | |  _  ||   __(   \\_        \n";
	cout <<"	 /  /  |     |\\__  ||_|  |_| |  | |  |  ||  |  |\\__  \|       \n";
	cout <<"	/   \\_ |  _  |/  \\ |  |  |   |  | |  |  ||  |_ |/  \\ |       \n";
	cout <<"	\\     ||  |  |\\    |  |  |   |  | |  |  ||     |\\    |       \n";
	cout <<"	 \\____||__|__| \\___|  |__|  |____||__|__||___,_| \\___|       \n";
	cout <<"___________________________________________________________________________\n\n";

	string candidatos;
	string jurados;
	string sessoes;

	cout << "Ficheiro com a informacao dos candidatos: " ; getline(cin, candidatos);

	if(lerFicheiroCandidatos(candidatos)) {
		cerr << "\nEndereco invalido!";
		cin.get();
		return 1;
	}

	cout << "Ficheiro com a informacao dos jurados   : " ; getline(cin, jurados);

	if (lerFicheiroJurados(jurados)) {
		cerr << "\nEndereco invalido!";
		cin.get();
		return 1;
	}

	cout << "Ficheiro com a informacao das sessoes   : " ; getline(cin, sessoes);

	if (lerFicheiroSessoes(sessoes)) {
		cerr << "\nEndereco invalido!";
		cin.get();
		return 1;
	}

	menu();

	return 0;
}
