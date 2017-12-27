#include <utility>
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
	cout << "| 3. Alterar Candidato                           |\n";
	cout << "| 4. Infomacao dos Candidatos                    |\n";
	cout << "|                                                |\n";
	cout << "| 8. Voltar                                      |\n";
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
			menuAlterarCandidato();
			break;
		case 4:
			menuInfoCandidato();
			break;
		case 8:
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
	cout << "|  Jurados                                       |\n";
	cout << "+------------------------------------------------+\n";
	cout << "| 1. Adicionar Jurado                            |\n";
	cout << "| 2. Remover Jurado                              |\n";
	cout << "| 3. Infomacao dos Jurados                       |\n";
	cout << "|                                                |\n";
	cout << "| 8. Voltar                                      |\n";
	cout << "+------------------------------------------------+\n\n";

	int opcao;

		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			menuAdicionaJurado();
			break;
		case 2:
			menuRemoveJurado();
			break;
		case 3:
			menuInfoJurado();
			break;
		case 8:
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
	cout << "| 1. Adicionar Sessao                            |\n";
	cout << "| 2. Remover Sessao                              |\n";
	cout << "| 3. Informacao das Sessoes                      |\n";
	cout << "| 4. Iniciar sessao                              |\n";
	cout << "|                                                |\n";
	cout << "| 8. Voltar                                      |\n";
	cout << "+------------------------------------------------+\n\n";

		int opcao;

		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			menuAdicionaSessao();
			break;
		case 2:
			menuRemoveSessao();
			break;
		case 3:
			menuInfoSessoes();
			break;
		case 4 :
			menuIniciarSessao();
			break;
		case 8:
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
	cin.ignore(1000, '\n');;
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
	cin.ignore(1000, '\n');
	getline(cin, arte);


	vector<pair<vector<int>,string>> indisp;

	unsigned int n;

	do {
		cout << "Numero de dias em que se encontra indisponivel ? ";
		cin >> n;
		if (cinTeste()) {
			cout << "Valor Invalido!\n";
			continue;
		} else {
			break;
		}
	} while (1);

	for (unsigned int i = 0; i < n; i++) {
		do {
			pair<vector<int>, string> a;
			cout << "Dia " << i + 1 << " :";
			int n1, n2, n3;
			cin >> n1 >> n2 >> n3;
			if (cinTeste()) {
				cout << "Valor Invalido!\n";
				continue;
			} else {
				vector<int> dia;
				dia.push_back(n1);
				dia.push_back(n2);
				dia.push_back(n3);
				a.first = dia;
				cout << "Razao: ";
				cin.ignore(1000, '\n');
				getline(cin, a.second);

				indisp.push_back(a);
				break;
			}
		} while (1);
	}


	candidato *c = new candidato(nome, morada, dia, mes, ano, arte, indisp);

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
		cin.ignore(1000, '\n');
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
		cin.ignore(1000, '\n');
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

void menuAlterarCandidato() {
	do {
		cout << "\n\n\n\n\n+------------------------------------------------+\n";
		cout << "|  Alterar Candidato                             |\n";
		cout << "+------------------------------------------------+\n";
		cout << "| 1. Procurar por Numero                         |\n";
		cout << "| 2. Procurar por Nome                           |\n";
		cout << "+------------------------------------------------+\n\n";

		int opcao;
		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			menuAlterarCandidatoNumero();
			return;
			break;
		case 2:
			menuAlterarCandidatoNome();
			return;
			break;
		default:
			break;
		}

		} while(1);
}

void menuAlterarCandidatoNumero() {

	int numero;
	do {
		cout << "\n\n\n\n\n+------------------------------------------------+\n";
		cout << "|  Alterar Candidato                             |\n";
		cout << "+------------------------------------------------+\n\n";

		cout << "Numero do candidato: ";
		cin >> numero;
		if (cinTeste()) {
			continue;
		}
		break;

	} while (1);

	try {
		alterarCandidato(numero);
	} catch (candidatoNaoExiste &c) {
		cout << c;
		cin.ignore(1000, '\n');
		cin.get();
		return;
	}
}

void menuAlterarCandidatoNome() {

	string nome;
	do {
		cout << "\n\n\n\n\n+------------------------------------------------+\n";
		cout << "|  Alterar Candidato                             |\n";
		cout << "+------------------------------------------------+\n\n";

		cout << "Nome: ";
		cin.ignore(1000, '\n');
		getline(cin,nome);
		if (cinTeste()) {
			continue;
		}
		break;

	} while (1);

	try {
		alterarCandidato(nome);
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
	cout << "| 2. Procurar por arte                           |\n";
	cout << "| 3. Todos os candidatos                         |\n";
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
		menuInfoCandidatosArte();
		return;
		break;
	case 3:
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
		cin.ignore(1000, '\n');
		cin.get();
		return;
	}
	cin.ignore(1000, '\n');

	cin.get();

}

void menuInfoCandidatoTodos() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Candidatos                         |\n";
	cout << "+------------------------------------------------+\n\n";

	if(candidatosGlobal.isEmpty()) {
		cout << "Ainda nao ha nenhum candidato...\n";
		cin.ignore(1000, '\n');
		cin.get();
		return;
	}

	BSTItrIn<candidato*> it(candidatosGlobal);
	while (!it.isAtEnd()) {
		infoCandidato(it.retrieve());
		it.advance();
		cout << " ---- \n";
	}
	for(HashTab::iterator it1 = indisponibilidades.begin(); it1 != indisponibilidades.end(); it1++) {
		pair<candidato*, string> p = *(it1);
		infoCandidato(p.first);
		cout << " ---- \n";
	}


	cin.ignore(1000, '\n');
	cin.get();
	return;

}

void menuInfoCandidatosArte() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Candidatos                         |\n";
	cout << "+------------------------------------------------+\n\n";
	cout << "Arte: ";
	string arte;
	cin.ignore(1000, '\n');
	getline(cin, arte);

	cout << endl;

	int cnt = 0;
	BSTItrIn<candidato*> it(candidatosGlobal);
	while (!it.isAtEnd()) {
		if(it.retrieve()->getArte() == arte) {
			infoCandidato(it.retrieve());
			cout << " ---- \n";
			cnt++;
		}
		it.advance();
	}

	if(cnt == 0) {
		cout << "Nao ha candidatos para a arte: " << arte << endl;
	}
	cin.get();
	return;
}

void menuAdicionaJurado() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Adicionar Jurado                              |\n";
	cout << "+------------------------------------------------+\n\n";

	string nome, morada, arte, telemovel;
	cin.ignore(1000, '\n');
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Morada: ";
	getline(cin, morada);
	cout << "Arte: ";
	getline(cin, arte);
	cout << "Telemovel: ";
	getline(cin, telemovel);

	jurado *j = new jurado(nome, morada, telemovel, arte);

	try {
		adicionaJurado(j);
	} catch (JuradoJaExiste &e) {
		cout << e;
		delete j;
		cin.get();
		return;
	}

}

void menuRemoveJurado() {

	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Remover Jurado                                |\n";
	cout << "+------------------------------------------------+\n\n";

	string nome;
	cout << "Nome do jurado: ";
	cin.ignore(1000, '\n');
	getline(cin, nome);

	try {
		removeJurado (nome);
	} catch (JuradoNaoExiste &e) {
		cout << e;
		cin.get();
		return;
	}
}

void menuInfoJurado() {

	do {
		cout
				<< "\n\n\n\n\n+------------------------------------------------+\n";
		cout << "|  Informacao Jurado                             |\n";
		cout << "+------------------------------------------------+\n";
		cout << "| 1. Procurar jurado por nome                    |\n";
		cout << "| 2. Todos os jurados                            |\n";
		cout << "+------------------------------------------------+\n\n";

		int opcao;
		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			menuInfoJuradoNome();
			return;
			break;
		case 2:
			menuInfoJuradoTodos();
			return;
			break;
		default:
			break;
		}

	} while (1);
}

void menuInfoJuradoNome() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Jurado                             |\n";
	cout << "+------------------------------------------------+\n\n";

	string nome;
	cout << "Nome do jurado: ";
	cin.ignore(1000, '\n');
	getline(cin,nome);


	try {
		infoJurado(nome);
	} catch (JuradoNaoExiste &c) {
		cout << c;
		cin.ignore(1000, '\n');
		cin.get();
		return;
	}
}

void menuInfoJuradoTodos() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Jurados                            |\n";
	cout << "+------------------------------------------------+\n\n";

	if(juradosGlobal.size() == 0) {
		cout << "Ainda nao ha nenhum jurado...\n";
		cin.ignore(1000, '\n');
		cin.get();
		return;
	}

	for (unsigned int i = 0; i < juradosGlobal.size(); i++) {
		infoJurado(juradosGlobal.at(i));
		cout << " ---- \n";;
	}
	cin.ignore(1000, '\n');
	cin.get();
	return;

}

void menuAdicionaSessao() {

	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Adicionar Sessao                              |\n";
	cout << "+------------------------------------------------+\n\n";

	string arte;
	vector<int> data(3);
	cin.ignore(1000, '\n');
	cout << "Arte da sessao: ";
	getline(cin, arte);

	do {
		cout << "Data: ";
		cin >> data[0] >> data[1] >> data[2];
		if (cinTeste()) {
			cout << "Valor Invalido!\n";
			continue;
		} else {
			break;
		}

	} while (1);

	sessao *s = new sessao(arte,data);

	try {
		adicionaSessao(s);
	} catch (sessaoJaExiste &sessao) {
		cout << sessao;
		delete s;
		cin.get();
		return;
	}

	if(menuAdicionaJuradosSessao(s)){
		removeSessao(s->getGeneroArte(), s->getData());
		delete s;
		return;
	}
	menuAdicionaCandidatosSessao(s);


}

void menuRemoveSessao() {

	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Remover Sessao                                |\n";
	cout << "+------------------------------------------------+\n\n";

	string arte;
	vector<int> data(3);
	cin.ignore(1000, '\n');
	cout << "Arte da sessao: ";
	getline(cin, arte);

	do {
		cout << "Data: ";
		cin >> data[0] >> data[1] >> data[2];
		if (cinTeste()) {
			cout << "Valor Invalido!\n";
			continue;
		} else {
			break;
		}

	} while (1);

	try {
		removeSessao(arte, data);
	} catch (sessaoNaoExiste &sessao) {
		cout << sessao;
		cin.get();
		return;
	}
}

void menuAdicionaCandidatosSessao(sessao* s) {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Adicionar Candidatos a Sessao                 |\n";
	cout << "+------------------------------------------------+\n\n";
	cout << "Candidatos disponiveis para a sessao:\n";

	vector<int> candidatos = candidatosDisponiveis(s);

	int n;
	do {
		cout << "Adicionar quantos candidatos? \n";
		cin >> n;
		if (cinTeste()) {
			cout << "Valor Invalido!\n";

		} else {
			break;
		}
	} while(1);

	for(unsigned int i = 0; i < n; i++) {
		int numero;
		bool flag = false;
		int temp = i + 1;
		do {
			cout << "Numero do candidato " << temp << "? ";
			cin >> numero;
			if (cinTeste()) {
				cout << "Valor Invalido!\n";

			} else {
				break;
			}
		} while (1);

		for(unsigned int j = 0; j < candidatos.size(); j++) {
			if(candidatos.at(j) == numero) {
				flag = true;
				break;
			}
		}

		if(flag) {
			try {
				adicionaCandidatoSessao(numero, s);
			} catch (candidatoOcupado &c){
				cout << c;
				i--;
			}

		}
		else {
			cout << "Nao podes adicionar esse candidato!\n";
			i--;
		}

	}

	cin.get();
	return;

}

int menuAdicionaJuradosSessao(sessao* s) {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Adicionar Jurados a Sessao                    |\n";
	cout << "+------------------------------------------------+\n\n";

	//int nJurados = s->getNumeroJurados();

	cout << "Jurados disponiveis para a sessao:\n";

	vector<string> jurados = juradosDisponiveis(s);

	if(jurados.size() < 3) {
		cout << "\nNão existem jurados suficientes para criar uma sessao (sao necessarios 3)!\n";
		cin.get();
		return 1;
	}


	for(unsigned int i = 1; i <= 3; i++) {
		string nome;
		bool flag = false;

		if(i == 1)
			cout << "Nome do jurado principal ? ";
		else
			cout << "Nome do jurado " << i << " ? ";
		getline(cin, nome);

		for(unsigned int j = 0; j < jurados.size(); j++) {
			if(nome == jurados.at(j)) {
				flag = true;
				break;
			}
		}
		if(flag) {
			try {
				adicionaJuradoSessao(nome, s);
			} catch (juradoOcupado &j){
				cout << j;
				i--;
			}

		}
		else {
			cout << "Nao podes adicionar esse jurado!\n";
			i--;
		}

	}

	cin.get();
	return 0;

}

void menuInfoSessoes() {

	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Sessao                             |\n";
	cout << "+------------------------------------------------+\n";

	string arte;
	vector<int> data(3);
	cin.ignore(1000, '\n');;
	cout << "Arte da sessao: ";
	getline(cin, arte);

	do {
		cout << "Data: ";
		cin >> data[0] >> data[1] >> data[2];
		if (cinTeste()) {
			cout << "Valor Invalido!\n";
			continue;
		} else {
			break;
		}

	} while (1);

	try {
		displayInfoSessao(arte, data);
	} catch (sessaoNaoExiste &s) {
		cout << s;
		cin.get();
	}




}



void menuIniciarSessao() {

	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Iniciar Sessao                                |\n";
	cout << "+------------------------------------------------+\n";

	string arte;
	vector<int> data(3);
	cin.ignore(1000, '\n');
	;
	cout << "Arte da sessao: ";
	getline(cin, arte);

	do {
		cout << "Data: ";
		cin >> data[0] >> data[1] >> data[2];
		if (cinTeste()) {
			cout << "Valor Invalido!\n";
			continue;
		} else {
			break;
		}

	} while (1);

	try {
		comecarSessao(arte, data);
	} catch (sessaoNaoExiste &s) {
		cout << s;
		cin.get();
	}

}
