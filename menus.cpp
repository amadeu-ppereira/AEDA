#include "menus.h"
#include "funcoes.h"

void menu() {

	do {
	cout<< "\n\n\n\n\n+------------------------------------------------+\n";
	cout<< "|  Castings TV                                   |\n";
	cout<< "+------------------------------------------------+\n";
	cout<< "| 1. Candidatos                                  |\n";
	cout<< "| 2. Jurados                                     |\n";
	cout<< "| 3. Sessoes                                     |\n";
	cout<< "|                                                |\n";
	cout<< "| 9. Sair                                        |\n";
	cout<< "+------------------------------------------------+\n\n";

	int opcao;

		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			menuCandidatos();
			break;
		case 2:
			menuJurados();
			break;
		case 3:
			menuSessoes();
			break;
		case 9:
			sair();
			break;
		default:
			break;
		}

	} while(1);
}

void menuCandidatos() {

	do {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
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

		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			menuAdicionaCandidato();
			break;
		case 2:
			removeCandidato();
			break;
		case 3:
			infoCandidato();
			break;
		case 8:
			return;
			break;
		case 9:
			sair();
			break;
		default:
			break;

		}

	}while (1);
}

void menuJurados() {

	do {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Candidatos                                    |\n";
	cout << "+------------------------------------------------+\n";
	cout << "| 1. Adicionar Jurado                            |\n";
	cout << "| 2. Remover Jurado                              |\n";
	cout << "| 3. Infomacao dos Jurados                       |\n";
	cout << "|                                                |\n";
	cout << "| 8. Voltar                                      |\n";
	cout << "| 9. Sair                                        |\n";
	cout << "+------------------------------------------------+\n\n";

	int opcao;

		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			adicionaJurado();
			break;
		case 2:
			removeJurado();
			break;
		case 3:
			infoJurado();
			break;
		case 8:
			return;
			break;
		case 9:
			sair();
			break;
		default:
			break;
		}

	} while (1);
}

void menuSessoes() {

	do {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Sessoes                                       |\n";
	cout << "+------------------------------------------------+\n";
	cout << "| 1.                                             |\n";
	cout << "| 2.                                             |\n";
	cout << "| 3.                                             |\n";
	cout << "|                                                |\n";
	cout << "| 8. Voltar                                      |\n";
	cout << "| 9. Sair                                        |\n";
	cout << "+------------------------------------------------+\n\n";

	int opcao;

		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 8:
			return;
			break;
		case 9:
			sair();
			break;
		default:
			break;
		}
	} while (1);
}

void menuAdicionaCandidato() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Adicionar Candidato                           |\n";
	cout << "+------------------------------------------------+\n\n";

	string nome, morada, arte;
	int dia, mes, ano;
	cin.ignore();
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Morada: ";
	getline(cin, morada);

	do {
		cout << "Data de nascimento: ";
		cin >> dia >> mes >> ano;
		if (cinTeste()) {
			cout << "Valor Invalido!\n";
			continue;
		} else {
			break;
		}

	} while (1);
	cin.ignore();
	cout << "Arte: ";
	getline(cin, arte);

	candidato *c = new candidato(nome, morada, dia, mes, ano, arte);

	try {
		adicionaCandidato(c);
	} catch (candidatoJaExiste &c) {
		cerr << c;
		cin.get();
		return;
	}


}
