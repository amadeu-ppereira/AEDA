#include "menus.h"

int menu(Casting &c) {

	cout<< "+------------------------------------------------+\n";
	cout<< "|  Castings TV                                   |\n";
	cout<< "+------------------------------------------------+\n";
	cout<< "| 1. Candidatos                                  |\n";
	cout<< "| 2. Jurados                                     |\n";
	cout<< "| 3. Sessoes                                     |\n";
	cout<< "|                                                |\n";
	cout<< "| 9. Sair                                        |\n";
	cout<< "+------------------------------------------------+\n\n";

	int opcao;
	bool opcaoValida = true;
	while (opcaoValida) {
		opcaoValida = true;
		cout << "Opcao: ";
		cin >> opcao;
		switch (opcao) {
		case 1:
			menuCandidatos(c);
			break;
		case 2:
			menuJurados(c);
			break;
		case 3:
			menuSessoes(c);
			break;
		case 9:
			return 0;
			break;
		}
		opcaoValida = false;
	}
}

void menuCandidatos(Casting &c) {
	cout << "+------------------------------------------------+\n";
	cout << "|  Candidatos                                    |\n";
	cout << "+------------------------------------------------+\n";
	cout << "| 1. Adicionar Candidato                         |\n";
	cout << "| 2. Remover Candidato                           |\n";
	cout << "| 3. Infomacao dos Candidatos                    |\n";
	cout << "|                                                |\n";
	cout << "| 8. Voltar                                      |\n";
	cout << "| 9. Sair                                        |\n";
	cout << "+------------------------------------------------+\n\n";

	int opcao;
	bool opcaoValida = true;
	while (opcaoValida) {
		opcaoValida = true;
		cout << "Opcao: ";
		cin >> opcao;
		switch (opcao) {
		case 1:
			//adicionar candidato;
			break;
		case 2:
			//remover candidato;
			break;
		case 3:
			//informacao candidatos;
			break;
		case 8:
			return;
			break;
		}
		opcaoValida = false;
	}
}
