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
			return;
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
			menuRemoveCandidato();
			break;
		case 3:
			menuInfoCandidato();
			break;
		case 8:
			return;
			break;
		case 9:
			sair();
			return;
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
			return;
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
			return;
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
	cout << "Arte: ";
	cin.ignore();
	getline(cin, arte);

	candidato *c = new candidato(nome, morada, dia, mes, ano, arte);

	try {
		adicionaCandidato(c);
	} catch (candidatoJaExiste &e) {
		cout << e;
		delete c;
		cin.get();
		return;
	}

}

void menuRemoveCandidato() {
	do {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Remover Candidato                             |\n";
	cout << "+------------------------------------------------+\n";
	cout << "| 1. Remover por Numero                          |\n";
	cout << "| 2. Remover por Nome                            |\n";
	cout << "+------------------------------------------------+\n\n";

	int opcao;
	cout << "Opcao: ";
	cin >> opcao;
	if (cinTeste()) {
		continue;
	}
	switch(opcao) {
	case 1:
		menuRemoveCandidatoNumero();
		return;
		break;
	case 2:
		menuRemoveCandidatoNome();
		return;
		break;
	default:
		break;
	}

	} while(1);

}

void menuRemoveCandidatoNumero() {

	int numero;
	do {
		cout << "\n\n\n\n\n+------------------------------------------------+\n";
		cout << "|  Remover Candidato                             |\n";
		cout << "+------------------------------------------------+\n\n";

		cout << "Numero do candidato: ";
		cin >> numero;
		if (cinTeste()) {
			continue;
		}
		break;

	} while (1);

	try {
		removeCandidato(numero);
	} catch (candidatoNaoExiste &c) {
		cout << c;
		cin.ignore();
		cin.get();
		return;
	}
}

void menuRemoveCandidatoNome() {

	string nome;
	do {
		cout << "\n\n\n\n\n+------------------------------------------------+\n";
		cout << "|  Remover Candidato                             |\n";
		cout << "+------------------------------------------------+\n\n";

		cout << "Nome: ";
		cin.ignore();
		getline(cin,nome);
		if (cinTeste()) {
			continue;
		}
		break;

	} while (1);

	try {
		removeCandidato(nome);
	} catch (candidatoNaoExiste &c) {
		cout << c;
		cin.get();
		return;
	}
}

void menuInfoCandidato() {
	do {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Candidato                          |\n";
	cout << "+------------------------------------------------+\n";
	cout << "| 1. Procurar candidato por numero               |\n";
	cout << "| 2. Todos os candidatos                         |\n";
	cout << "+------------------------------------------------+\n\n";

	int opcao;
	cout << "Opcao: ";
	cin >> opcao;
	if (cinTeste()) {
		continue;
	}
	switch(opcao) {
	case 1:
		menuInfoCandidatoNumero();
		return;
		break;
	case 2:
		menuInfoCandidatoTodos();
		return;
		break;
	default:
		break;
	}

	} while(1);

}

void menuInfoCandidatoNumero() {
	int numero;
	do {
		cout << "\n\n\n\n\n+------------------------------------------------+\n";
		cout << "|  Informacao Candidato                          |\n";
		cout << "+------------------------------------------------+\n\n";

		cout << "Numero do candidato: ";
		cin >> numero;
		if (cinTeste()) {
			continue;
		}
		break;

	} while (1);

	try {
		infoCandidato(numero);
	} catch (candidatoNaoExiste &c) {
		cout << c;
		cin.get();
		return;
	}

}

void menuInfoCandidatoTodos() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Candidatos                         |\n";
	cout << "+------------------------------------------------+\n\n";

	if(candidatosGlobal.size() == 0) {
		cout << "Ainda nao ha nenhum candidato...\n";
		cin.ignore();
		cin.get();
		return;
	}

	for (unsigned int i = 0; i < candidatosGlobal.size(); i++) {
		infoCandidato(candidatosGlobal.at(i));
		cout << " ---- \n";;
	}
	cin.ignore();
	cin.get();
	return;

}


