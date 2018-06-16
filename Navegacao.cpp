
#include "Navegacao.hpp"

//--------------------------------------------------------------------------- 
// Classe FrontPage.

void NavFrontPage::showOption(){
	cout << endl << "Pagina inicial - Opcoes:" << endl;
	cout << "1 - Login." << endl;
	cout << "2 - Sign Up." << endl;
	cout << "3 - Exit." << endl;
}
void NavFrontPage::execute(){
	unsigned int opcao;
	NavLogin nLogin;
	NavSignUp nSignUp;

	while (true) {
		showOption();
		cout << "Escolha opcao: ";
		cin >> opcao;

		switch (opcao) {
			case OP_LOGIN:
				nLogin.execute();
			break;

			case OP_SIGNUP:
				nSignUp.execute();
			break;
			
			case OP_EXIT:
				return;
			break;
			
			default:
				cout << endl << "Opcao invalida." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}

//--------------------------------------------------------------------------- 
// Classe Login.

void NavLogin::showOption(){
	cout << endl << "Pagina de login - Informe os seguintes dados:" << endl;
}
void NavLogin::execute(){
	string iemail, isenha;

	Email email;
	Senha senha;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "E-mail: ";
		cin >> iemail;
		cout << "Senha: ";
		cin >> isenha;

		try{
			email.setEmail(iemail);
			senha.setSenha(isenha);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

//--------------------------------------------------------------------------- 
// Classe SignUp.

void NavSignUp::showOption(){
	cout << endl << "Pagina de cadastro - Qual nivel de usuario deseja cadastrar:" << endl;
	cout << "1 - Leitor." << endl;
	cout << "2 - Desenvolvedor." << endl;
	cout << "3 - Administrador." << endl;
	cout << "4 - Retornar pagina inicial." << endl;
}
void NavSignUp::execute(){
	unsigned int opcao;
	NavSULeitor	nLeitor;
	NavSUDev	nDev;
	NavSUAdmin	nAdmin;

	while (true) {
		showOption();
		cout << "Escolha opcao: ";
		cin >> opcao;

		switch (opcao) {
			case SU_LEITOR:
				nLeitor.execute();
				return;
			break;

			case SU_DEV:
				nDev.execute();
				return;
			break;

			case SU_ADMIN:
				nAdmin.execute();
				return;
			break;

			case SU_EXIT:
				return;
			break;
			
			default:
				cout << endl << "Opcao invalida." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}

//--------------------------------------------------------------------------- 
// Classe SULeitor.

void NavSULeitor::showOption(){
	cout << endl << "Cadastro de leitor - Informe os dados para cadastro:" << endl;
}
void NavSULeitor::execute(){
	string inome, isobre, iemail, isenha;

	Nome nome, sobrenome;
	Email email;
	Senha senha;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "Nome: ";
		cin >> inome;
		cout << "Sobrenome: ";
		cin >> isobre;
		cout << "E-mail: ";
		cin >> iemail;
		cout << "Senha: ";
		cin >> isenha;

		try{
			nome.setNome(inome);
			sobrenome.setNome(isobre);
			email.setEmail(iemail);
			senha.setSenha(isenha, inome);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

//--------------------------------------------------------------------------- 
// Classe SUDev.

void NavSUDev::showOption(){
	cout << endl << "Cadastro de desenvolvedor - Informe os dados para cadastro:" << endl;
}
void NavSUDev::execute(){
	string inome, isobre, iemail, isenha;
	int idia, imes, iano;

	Nome nome, sobrenome;
	Email email;
	Senha senha;
	Data nascimento;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "Nome: ";
		cin >> inome;
		cout << "Sobrenome: ";
		cin >> isobre;
		cout << "E-mail: ";
		cin >> iemail;
		cout << "Senha: ";
		cin >> isenha;
		cout << "Dia nascimento: ";
		cin >> idia;
		cout << "Mes nascimento: ";
		cin >> imes;
		cout << "Ano nascimento: ";
		cin >> iano;

		try{
			nome.setNome(inome);
			sobrenome.setNome(isobre);
			email.setEmail(iemail);
			senha.setSenha(isenha, inome);
			nascimento.setData(idia, imes, iano);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

//--------------------------------------------------------------------------- 
// Classe SUAdmin.

void NavSUAdmin::showOption(){
	cout << endl << "Cadastro de administrador - Informe os dados para cadastro:" << endl;
}
void NavSUAdmin::execute(){
	string inome, isobre, iemail, isenha, itelefone, iendereco;
	int idia, imes, iano;

	Nome nome, sobrenome;
	Email email;
	Senha senha;
	Data nascimento;
	Telefone telefone;
	Endereco endereco;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "Nome: ";
		cin >> inome;
		cout << "Sobrenome: ";
		cin >> isobre;
		cout << "E-mail: ";
		cin >> iemail;
		cout << "Senha: ";
		cin >> isenha;
		cout << "Dia nascimento: ";
		cin >> idia;
		cout << "Mes nascimento: ";
		cin >> imes;
		cout << "Ano nascimento: ";
		cin >> iano;
		cout << "Telefone: ";
		cin >> itelefone;
		cout << "Endereco: ";
		cin >> iendereco;

		try{
			nome.setNome(inome);
			sobrenome.setNome(isobre);
			email.setEmail(iemail);
			senha.setSenha(isenha, inome);
			nascimento.setData(idia, imes, iano);
			telefone.setTelefone(itelefone);
			endereco.setEndereco(iendereco);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}