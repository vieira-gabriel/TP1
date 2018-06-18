
#include "Navegacao.hpp"

//--------------------------------------------------------------------------- 
// Classe FrontPage.

void NavFrontPage::showOption(){
	cout << endl << "Pagina inicial - Opcoes:" << endl;
	cout << "1 - \tLogin." << endl;
	cout << "2 - \tSign Up." << endl;
	cout << "3 - \tExit." << endl;
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
				cout << endl << "***Opcao invalida." << endl;
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

	CmdLogin cmd(email, senha);
	try {
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}


	switch (cmd.getResult()){
		case CmdLogin::LG_LEITOR:
		{
			NavUserLeitor user(email);
			user.execute();
			break;
		}

		case CmdLogin::LG_DEV:
		{
			NavUserDev user(email);
			user.execute();
			break;
		}

		case CmdLogin::LG_ADMIN:
		{
			NavUserAdmin user(email);
			user.execute();
			break;
		}

		default:
		break;
	}
}

//--------------------------------------------------------------------------- 
// Classe SignUp.

void NavSignUp::showOption(){
	cout << endl << "Pagina de cadastro - Qual nivel de usuario deseja cadastrar:" << endl;
	cout << "1 - \tLeitor." << endl;
	cout << "2 - \tDesenvolvedor." << endl;
	cout << "3 - \tAdministrador." << endl;
	cout << "4 - \tRetornar pagina inicial." << endl;
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
				cout << endl << "***Opcao invalida." << endl;
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

	CmdSULeitor cmd(nome, sobrenome, email, senha);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	cout << "Conta de leitor criada." << endl;
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

	CmdSUDev cmd(nome, sobrenome, email, senha, nascimento);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	cout << "Conta de desenvolvedor criada." << endl;
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

	CmdSUAdmin cmd(nome, sobrenome, email, senha, nascimento, telefone, endereco);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	cout << "Conta de administrador criada." << endl;
}

//--------------------------------------------------------------------------- 
// Classe NavUserLeitor.

void NavUserLeitor::showOption(){
	cout << endl << "Pagina de usuario leitor - acoes disponiveis:" << endl;
	cout << "1 - \tApresentar dados do usuario." << endl;
	cout << "2 - \tEditar dados do usario." << endl;
	cout << "3 - \tExcluir conta." << endl;
	cout << "4 - \tListar vocabularios controlados." << endl;
	cout << "5 - \tConsultar vocabulario controlado." << endl;
	cout << "6 - \tConsultar termo." << endl;
	cout << "7 - \tConsultar definicao de termo." << endl;
	cout << "8 - \tSair da conta." << endl;
}

void NavUserLeitor::execute() {
	int opcao;

	while (true) {
		showOption();
		cout << "Escolha opcao: ";
		cin >> opcao;

		switch (opcao) {
			case US_SHOW_USER:
			break;

			case US_EDIT_USER:
			break;

			case US_DELETE_USER:
			break;

			case US_LIST_VOCAB:
			break;

			case US_SHOW_VOCAB:
			break;

			case US_SHOW_TERMO:
			break;

			case US_SHOW_DEFIN:
			break;

			case US_EXIT:
				return;
			break;
			
			default:
				cout << endl << "***Opcao invalida." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}

//--------------------------------------------------------------------------- 
// Classe NavUserDev.

void NavUserDev::showOption(){
	cout << endl << "Pagina de usuario desenvolvedor - acoes disponiveis:" << endl;
	cout << "1 - \tApresentar dados do usuario." << endl;
	cout << "2 - \tEditar dados do usario." << endl;
	cout << "3 - \tExcluir conta." << endl;
	cout << "4 - \tListar vocabularios controlados." << endl;
	cout << "5 - \tConsultar vocabulario controlado." << endl;
	cout << "6 - \tConsultar termo." << endl;
	cout << "7 - \tConsultar definicao de termo." << endl;
	cout << "8 - \tCadastrar como desenvolvedor de vocabulario." << endl;
	cout << "9 - \tCriar termo." << endl;
	cout << "10 - \tEditar termo." << endl;
	cout << "11 - \tExcluir termo." << endl;
	cout << "12 - \tCriar definicao de termo." << endl;
	cout << "13 - \tEditar definicao de termo." << endl;
	cout << "14 - \tExcluir definicao de termo." << endl;
	cout << "15 - \tSair da conta." << endl;
}

void NavUserDev::execute() {
	int opcao;

	while (true) {
		showOption();
		cout << "Escolha opcao: ";
		cin >> opcao;

		switch (opcao) {
			case US_SHOW_USER:
			break;

			case US_EDIT_USER:
			break;

			case US_DELETE_USER:
			break;

			case US_LIST_VOCAB:
			break;

			case US_SHOW_VOCAB:
			break;

			case US_SHOW_TERMO:
			break;

			case US_SHOW_DEFIN:
			break;

			case US_SU_VOCAB:
			break;

			case US_NEW_TERMO:
			break;
			
			case US_EDIT_TERMO:
			break;
			
			case US_DELETE_TERMO:
			break;
			
			case US_NEW_DEFIN:
			break;
			
			case US_EDIT_DEFIN:
			break;
			
			case US_DELETE_DEFIN:
			break;

			case US_EXIT:
				return;
			break;
			
			default:
				cout << endl << "***Opcao invalida." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}

//--------------------------------------------------------------------------- 
// Classe NavUserAdmin.

void NavUserAdmin::showOption(){
	cout << endl << "Pagina de usuario desenvolvedor - acoes disponiveis:" << endl;
	cout << "1 - \tApresentar dados do usuario." << endl;
	cout << "2 - \tEditar dados do usario." << endl;
	cout << "3 - \tExcluir conta." << endl;
	cout << "4 - \tListar vocabularios controlados." << endl;
	cout << "5 - \tConsultar vocabulario controlado." << endl;
	cout << "6 - \tConsultar termo." << endl;
	cout << "7 - \tConsultar definicao de termo." << endl;
	cout << "8 - \tCadastrar como desenvolvedor de vocabulario." << endl;
	cout << "9 - \tCriar termo." << endl;
	cout << "10 - \tEditar termo." << endl;
	cout << "11 - \tExcluir termo." << endl;
	cout << "12 - \tCriar definicao de termo." << endl;
	cout << "13 - \tEditar definicao de termo." << endl;
	cout << "14 - \tExcluir definicao de termo." << endl;
	cout << "15 - \tCriar vocabulario." << endl;
	cout << "16 - \tEditar vocabulario." << endl;
	cout << "17 - \tExcluir vocabulario." << endl;
	cout << "18 - \tSair da conta." << endl;
}

void NavUserAdmin::execute() {
	int opcao;

	while (true) {
		showOption();
		cout << "Escolha opcao: ";
		cin >> opcao;

		switch (opcao) {
			case US_SHOW_USER:
			break;

			case US_EDIT_USER:
			break;

			case US_DELETE_USER:
			break;

			case US_LIST_VOCAB:
			break;

			case US_SHOW_VOCAB:
			break;

			case US_SHOW_TERMO:
			break;

			case US_SHOW_DEFIN:
			break;

			case US_SU_VOCAB:
			break;

			case US_NEW_TERMO:
			break;
			
			case US_EDIT_TERMO:
			break;
			
			case US_DELETE_TERMO:
			break;
			
			case US_NEW_DEFIN:
			break;
			
			case US_EDIT_DEFIN:
			break;
			
			case US_DELETE_DEFIN:
			break;

			case US_NEW_VOCAB:
			{
				NavNewVocab nav(email);
				nav.execute();
			}
			
			case US_EDIT_VOCAB:
			break;
			
			case US_DELETE_VOCAB:
			break;

			case US_EXIT:
				return;
			break;
			
			default:
				cout << endl << "***Opcao invalida." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}



//##############################################################################################
//############################### Acoes de usuario #############################################
//##############################################################################################

//--------------------------------------------------------------------------- 
// Classe NavNewVocab.

void NavNewVocab::showOption(){
	cout << endl << "Criacao de vocabulario controlado - Informe os dados a seguir:" << endl;
}

void NavNewVocab::execute(){
	string ivocab, iidioma, idefin;
	int idia, imes, iano;

	Vocabulario_controlado vocab;
	Definicao defin;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "Nome do vocabulario: ";
		cin >> ivocab;
		cout << "-opcao de idioma: ENG, FRA, GER, ITA, POR e SPA." << endl;
		cout << "Idioma do vocabulario: ";
		cin >> iidioma;
		cout << "Definicao do vocabulario: ";
		cin >> idefin;
		cout << "dia: ";
		cin >> idia;
		cout << "mes: ";
		cin >> imes;
		cout << "ano: ";
		cin >> iano;


		try{
			vocab.getNome().setNome(ivocab);
			vocab.getIdioma().setIdioma(iidioma);
			defin.getTexto().setTexto(idefin);
			vocab.getDataCriacao().setData(idia, imes, iano);
			defin.getDataCriacao().setData(idia, imes, iano);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	cout << "Vocabulario controlado criado." << endl;
}

//--------------------------------------------------------------------------- 
// Classe NavEditVocab.

void NavEditVocab::showOption(){
	cout << endl << "Edicao de vocabulario controlado - Informe os dados a seguir:" << endl;
}

void NavEditVocab::execute(){
	string ivocab, iidioma, idefin;
	int idia, imes, iano;

	Vocabulario_controlado vocab;
	Definicao defin;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "Nome do vocabulario: ";
		cin >> ivocab;
		cout << "-opcao de idioma: ENG, FRA, GER, ITA, POR e SPA." << endl;
		cout << "Idioma do vocabulario: ";
		cin >> iidioma;
		cout << "Definicao do vocabulario: ";
		cin >> idefin;
		cout << "dia: ";
		cin >> idia;
		cout << "mes: ";
		cin >> imes;
		cout << "ano: ";
		cin >> iano;


		try{
			vocab.getNome().setNome(ivocab);
			vocab.getIdioma().setIdioma(iidioma);
			defin.getTexto().setTexto(idefin);
			vocab.getDataCriacao().setData(idia, imes, iano);
			defin.getDataCriacao().setData(idia, imes, iano);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	cout << "Vocabulario controlado editado." << endl;
}

//--------------------------------------------------------------------------- 
// Classe NavDeleteVocab.

void NavDeleteVocab::showOption(){
	cout << endl << "Exclusao de vocabulario controlado - Informe os dados a seguir:" << endl;
}

void NavDeleteVocab::execute(){
	string ivocab;
	Nome nome;
	showOption();

	// Obtem input valido.
	while(true) {
		cout << "Nome do vocabulario: ";
		cin >> ivocab;


		try{
			nome.setNome(ivocab);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}	
	
	cout << "Vocabulario controlado excluido." << endl;
}

