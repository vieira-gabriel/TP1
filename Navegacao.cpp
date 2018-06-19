
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

	// pre-made data.
	Nome nome, sobrenome;
	Email email;
	Senha senha;
	Data nascimento;
	Telefone telefone;
	Endereco endereco;
	Vocabulario_controlado pvocab;
	Termo ptermo;
	Definicao pdefin;
	
	nome.setNome("Leitor");
	sobrenome.setNome("Leitor");
	email.setEmail("l@dom");
	senha.setSenha("Senha123");
	CmdSULeitor cmd1(nome, sobrenome, email, senha);
	cmd1.execute();
	nome.setNome("Dev");
	sobrenome.setNome("Dev");
	email.setEmail("d@dom");
	senha.setSenha("Senha123");
	nascimento.setData(21, 12, 1990);
	CmdSUDev cmd2(nome, sobrenome, email, senha, nascimento);
	cmd2.execute();
	nome.setNome("Admin");
	sobrenome.setNome("Admin");
	email.setEmail("a@dom");
	senha.setSenha("Senha123");
	nascimento.setData(6, 6, 2006);
	telefone.setTelefone("12345678901");
	endereco.setEndereco("Casa da sua mae");
	CmdSUAdmin cmd3(nome, sobrenome, email, senha, nascimento, telefone, endereco);
	cmd3.execute();

	pvocab.setNome("Vocabulario");
	pvocab.setIdioma("SPA");
	pvocab.setDataCriacao(1, 1, 2000);
	pdefin.setTexto("definicao vocab.");
	pdefin.setDataCriacao(1, 1, 2001);
	email.setEmail("a@dom");
	CmdNewVocab cmd4(pvocab, pdefin, email);
	cmd4.execute();
	ptermo.setNome("Termo");
	ptermo.setClasse("NP");
	ptermo.setDataCriacao(2, 2, 2002);
	nome.setNome("Vocabulario");
	CmdNewTermo cmd5(ptermo, nome, email);
	cmd5.execute();
	pdefin.setTexto("definicao termo");
	pdefin.setDataCriacao(3, 3, 2003);
	sobrenome.setNome("Termo");
	CmdNewDefin cmd6(pdefin, nome, sobrenome, email);
	cmd6.execute();
	// -----------------------	

	while (true) {
		showOption();
		cout << "Escolha opcao: ";
		cin >> opcao;

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		getline(cin, iemail);
		//cin >> iemail;
		cout << "Senha: ";
		getline(cin, isenha);
		//cin >> isenha;

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

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		getline(cin, inome);
		//cin >> inome;
		cout << "Sobrenome: ";
		getline(cin, isobre);
		//cin >> isobre;
		cout << "E-mail: ";
		getline(cin, iemail);
		//cin >> iemail;
		cout << "Senha: ";
		getline(cin, isenha);
		//cin >> isenha;

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
		getline(cin, inome);
		//cin >> inome;
		cout << "Sobrenome: ";
		getline(cin, isobre);
		//cin >> isobre;
		cout << "E-mail: ";
		getline(cin, iemail);
		//cin >> iemail;
		cout << "Senha: ";
		getline(cin, isenha);
		//cin >> isenha;
		cout << "Dia nascimento: ";
		cin >> idia;
		cout << "Mes nascimento: ";
		cin >> imes;
		cout << "Ano nascimento: ";
		cin >> iano;

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		getline(cin, inome);
		//cin >> inome;
		cout << "Sobrenome: ";
		getline(cin, isobre);
		//cin >> isobre;
		cout << "E-mail: ";
		getline(cin, iemail);
		//cin >> iemail;
		cout << "Senha: ";
		getline(cin, isenha);
		//cin >> isenha;
		cout << "Telefone: ";
		getline(cin, itelefone);
		//cin >> itelefone;
		cout << "Endereco: ";
		getline(cin, iendereco);
		//cin >> iendereco;
		cout << "Dia nascimento: ";
		cin >> idia;
		cout << "Mes nascimento: ";
		cin >> imes;
		cout << "Ano nascimento: ";
		cin >> iano;

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (opcao) {
			case US_SHOW_USER:
			break;

			case US_EDIT_USER:
			break;

			case US_DELETE_USER:
			{
				CmdDeleteUser cmd(email);
				cmd.execute();

				cout << "Usuario deletado." << endl;
				return;
				break;
			}

			case US_LIST_VOCAB:
			{
				NavListVocab nav;
				nav.execute();
				break;
			}

			case US_SHOW_VOCAB:
			{
				NavShowVocab nav;
				nav.execute();
				break;
			}

			case US_SHOW_TERMO:
			{
				NavShowTermo nav;
				nav.execute();
				break;
			}

			case US_SHOW_DEFIN:
			{
				NavShowDefin nav;
				nav.execute();
				break;
			}

			case US_EXIT:
				return;
			break;
			
			default:
				cout << endl << "***Opcao invalida." << endl;
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

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (opcao) {
			case US_SHOW_USER:
			break;

			case US_EDIT_USER:
			break;

			case US_DELETE_USER:
			{
				CmdDeleteUser cmd(email);
				cmd.execute();

				cout << "Usuario deletado." << endl;
				return;
				break;
			}

			case US_LIST_VOCAB:
			{
				NavListVocab nav;
				nav.execute();
				break;
			}

			case US_SHOW_VOCAB:
			{
				NavShowVocab nav;
				nav.execute();
				break;
			}

			case US_SHOW_TERMO:
			{
				NavShowTermo nav;
				nav.execute();
				break;
			}

			case US_SHOW_DEFIN:
			{
				NavShowDefin nav;
				nav.execute();
				break;
			}

			case US_SU_VOCAB:
			{
				NavSUVocab nav(email);
				nav.execute();
				break;
			}

			case US_NEW_TERMO:
			{
				NavNewTermo nav(email);
				nav.execute();
				break;
			}

			case US_EDIT_TERMO:
			{
				NavEditTermo nav(email);
				nav.execute();
				break;
			}

			case US_DELETE_TERMO:
			{
				NavDeleteTermo nav(email);
				nav.execute();
				break;
			}

			case US_NEW_DEFIN:
			{
				NavNewDefin nav(email);
				nav.execute();
				break;
			}
			
			case US_EDIT_DEFIN:
			{
				NavEditDefin nav(email);
				nav.execute();
				break;
			}
			
			case US_DELETE_DEFIN:
			{
				NavDeleteDefin nav(email);
				nav.execute();
				break;
			}
			
			case US_EXIT:
				return;
			break;

			default:
				cout << endl << "***Opcao invalida." << endl;
			break;
		}
	}
}

//--------------------------------------------------------------------------- 
// Classe NavUserAdmin.

void NavUserAdmin::showOption(){
	cout << endl << "Pagina de usuario administrador - acoes disponiveis:" << endl;
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

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (opcao) {
			case US_SHOW_USER:
			break;

			case US_EDIT_USER:
			break;

			case US_DELETE_USER:
			{
				CmdDeleteUser cmd(email);
				cmd.execute();

				cout << "Usuario deletado." << endl;
				return;
				break;
			}

			case US_LIST_VOCAB:
			{
				NavListVocab nav;
				nav.execute();
				break;
			}

			case US_SHOW_VOCAB:
			{
				NavShowVocab nav;
				nav.execute();
				break;
			}

			case US_SHOW_TERMO:
			{
				NavShowTermo nav;
				nav.execute();
				break;
			}

			case US_SHOW_DEFIN:
			{
				NavShowDefin nav;
				nav.execute();
				break;
			}

			case US_SU_VOCAB:
			{
				NavSUVocab nav(email);
				nav.execute();
				break;
			}

			case US_NEW_TERMO:
			{
				NavNewTermo nav(email);
				nav.execute();
				break;
			}

			case US_EDIT_TERMO:
			{
				NavEditTermo nav(email);
				nav.execute();
				break;
			}

			case US_DELETE_TERMO:
			{
				NavDeleteTermo nav(email);
				nav.execute();
				break;
			}
			
			case US_NEW_DEFIN:
			{
				NavNewDefin nav(email);
				nav.execute();
				break;
			}
			
			case US_EDIT_DEFIN:
			{
				NavEditDefin nav(email);
				nav.execute();
				break;
			}
			
			case US_DELETE_DEFIN:
			{
				NavDeleteDefin nav(email);
				nav.execute();
				break;
			}

			case US_NEW_VOCAB:
			{
				NavNewVocab nav(email);
				nav.execute();
				break;
			}
			
			case US_EDIT_VOCAB:
			{
				NavEditVocab nav(email);
				nav.execute();
				break;
			}
			
			case US_DELETE_VOCAB:
			{
				NavDeleteVocab nav(email);
				nav.execute();
				break;
			}

			case US_EXIT:
				return;
			break;
			
			default:
				cout << endl << "***Opcao invalida." << endl;
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
		getline(cin, ivocab);
		//cin >> ivocab;
		cout << "-opcao de idioma: ENG, FRA, GER, ITA, POR e SPA." << endl;
		cout << "Idioma do vocabulario: ";
		getline(cin, iidioma);
		//cin >> iidioma;
		cout << "Definicao do vocabulario: ";
		getline(cin, idefin);
		//cin >> idefin;
		cout << "Dia: ";
		cin >> idia;
		cout << "Mes: ";
		cin >> imes;
		cout << "Ano: ";
		cin >> iano;


		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		try{
			vocab.setNome(ivocab);
			vocab.setIdioma(iidioma);
			defin.setTexto(idefin);
			vocab.setDataCriacao(idia, imes, iano);
			defin.setDataCriacao(idia, imes, iano);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
		}
	}

	CmdNewVocab cmd(vocab, defin, user);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
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
		getline(cin, ivocab);
		//cin >> ivocab;
		cout << "-opcao de idioma: ENG, FRA, GER, ITA, POR e SPA." << endl;
		cout << "Novo idioma do vocabulario: ";
		getline(cin, iidioma);
		//cin >> iidioma;
		cout << "Nova definicao do vocabulario: ";
		getline(cin, idefin);
		//cin >> idefin;
		cout << "Novo dia: ";
		cin >> idia;
		cout << "Novo mes: ";
		cin >> imes;
		cout << "Novo ano: ";
		cin >> iano;


		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		try{
			vocab.setNome(ivocab);
			vocab.setIdioma(iidioma);
			defin.setTexto(idefin);
			vocab.setDataCriacao(idia, imes, iano);
			defin.setDataCriacao(idia, imes, iano);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
		}
	}

	CmdEditVocab cmd(vocab, defin, user);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
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
		getline(cin, ivocab);
		//cin >> ivocab;


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
	
	CmdDeleteVocab cmd(nome, user);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	cout << "Vocabulario controlado excluido." << endl;
}


//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
// Classe NavNewTermo.

void NavNewTermo::showOption(){
	cout << endl << "Criacao de termo - Informe os dados a seguir:" << endl;
}

void NavNewTermo::execute(){
	string itermo, iclasse, ivocab;
	int idia, imes, iano;

	Termo termo;
	Nome vocab;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "De qual vocabulario eh: ";
		getline(cin, ivocab);
		cout << "Nome do termo: ";
		getline(cin, itermo);
		cout << "-opcao de classe: PT ou NP." << endl;
		cout << "Classe do termo: ";
		getline(cin, iclasse);
		cout << "Dia: ";
		cin >> idia;
		cout << "Mes: ";
		cin >> imes;
		cout << "Ano: ";
		cin >> iano;

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		try{
			termo.setNome(itermo);
			termo.setClasse(iclasse);
			termo.setDataCriacao(idia, imes, iano);
			vocab.setNome(ivocab);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
		}
	}

	CmdNewTermo cmd(termo, vocab, user);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	cout << "Termo criado." << endl;
}

//--------------------------------------------------------------------------- 
// Classe NavEditTermo.

void NavEditTermo::showOption(){
	cout << endl << "Edicao de termo - Informe os dados a seguir:" << endl;
}

void NavEditTermo::execute(){
	string itermo, iclasse, ivocab;
	int idia, imes, iano;

	Termo termo;
	Nome vocab;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "De qual vocabulario eh: ";
		getline(cin, ivocab);
		cout << "Nome do termo: ";
		getline(cin, itermo);
		cout << "-opcao de classe: PT ou NP." << endl;
		cout << "Nova classe do termo: ";
		getline(cin, iclasse);
		cout << "Novo dia: ";
		cin >> idia;
		cout << "Novo mes: ";
		cin >> imes;
		cout << "Novo ano: ";
		cin >> iano;


		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		try{
			termo.setNome(itermo);
			termo.setClasse(iclasse);
			termo.setDataCriacao(idia, imes, iano);
			vocab.setNome(ivocab);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
		}
	}

	CmdEditTermo cmd(termo, vocab, user);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	cout << "Termo editado." << endl;
}

//--------------------------------------------------------------------------- 
// Classe NavDeleteTermo.

void NavDeleteTermo::showOption(){
	cout << endl << "Exclusao de termo - Informe os dados a seguir:" << endl;
}

void NavDeleteTermo::execute(){
	string itermo, ivocab;
	Nome nome, vocab;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "De qual vocabulario eh: ";
		getline(cin, ivocab);
		cout << "Nome do termo: ";
		getline(cin, itermo);


		try{
			nome.setNome(itermo);
			vocab.setNome(ivocab);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}	
	
	CmdDeleteTermo cmd(nome, vocab, user);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	cout << "Termo excluido." << endl;
}


//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
// Classe NavNewDefin.

void NavNewDefin::showOption(){
	cout << endl << "Criacao de definicao de termo - Informe os dados a seguir:" << endl;
}

void NavNewDefin::execute(){
	string itexto, ivocab, itermo;
	int idia, imes, iano;

	Definicao defin;
	Nome vocab, termo;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "De qual vocabulario eh: ";
		getline(cin, ivocab);
		cout << "De qual termo eh: ";
		getline(cin, itermo);
		cout << "Definicao: ";
		getline(cin, itexto);
		cout << "Dia: ";
		cin >> idia;
		cout << "Mes: ";
		cin >> imes;
		cout << "Ano: ";
		cin >> iano;

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		try{
			defin.setTexto(itexto);
			defin.setDataCriacao(idia, imes, iano);
			vocab.setNome(ivocab);
			termo.setNome(itermo);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
		}
	}

	CmdNewDefin cmd(defin, vocab, termo, user);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	cout << "Definicao criado." << endl;
}

//--------------------------------------------------------------------------- 
// Classe NavEditDefin.

void NavEditDefin::showOption(){
	cout << endl << "Edicao de definicao de termo - Informe os dados a seguir:" << endl;
}

void NavEditDefin::execute(){
	string itexto, ivocab, itermo, iotexto;
	int idia, imes, iano;

	Definicao defin;
	Nome vocab, termo;
	Texto old;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "De qual vocabulario eh: ";
		getline(cin, ivocab);
		cout << "De qual termo eh: ";
		getline(cin, itermo);
		cout << "Qual definicao eh: ";
		getline(cin, iotexto);
		cout << "Nova definicao: ";
		getline(cin, itexto);
		cout << "Novo dia: ";
		cin >> idia;
		cout << "Novo mes: ";
		cin >> imes;
		cout << "Novo ano: ";
		cin >> iano;

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		try{
			defin.setTexto(itexto);
			defin.setDataCriacao(idia, imes, iano);
			vocab.setNome(ivocab);
			termo.setNome(itermo);
			old.setTexto(iotexto);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
		}
	}

	CmdEditDefin cmd(defin, old, vocab, termo, user);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	cout << "Definicao editado." << endl;
}

//--------------------------------------------------------------------------- 
// Classe NavDeleteDefin.

void NavDeleteDefin::showOption(){
	cout << endl << "Exclusao de definicao de termo - Informe os dados a seguir:" << endl;
}

void NavDeleteDefin::execute(){
	string itermo, ivocab, idefin;
	Nome vocab, termo;
	Texto defin;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "De qual vocabulario eh: ";
		getline(cin, ivocab);
		cout << "De qual termo eh: ";
		getline(cin, itermo);
		cout << "Definicao: ";
		getline(cin, idefin);


		try{
			defin.setTexto(idefin);
			vocab.setNome(ivocab);
			termo.setNome(itermo);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}	
	
	CmdDeleteDefin cmd(defin, vocab, termo, user);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	cout << "Definicao excluido." << endl;
}



//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
//--------------------------------------------------------------------------- 
// Classe NavSUVocab.

void NavSUVocab::showOption(){
	cout << endl << "Cadastro de desenvolvedor em vocabulario - Informe os dados a seguir:" << endl;
}

void NavSUVocab::execute(){
	string ivocab;
	Nome vocab;
	showOption();

	// Obtem input valido.
	while(true) {
		cout << "Vocabulario desejado: ";
		getline(cin, ivocab);

		try{
			vocab.setNome(ivocab);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	CmdSUVocab cmd(vocab, user);

	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	cout << "Registrado como desenvolvedor do vocabulario." << endl;
}

//--------------------------------------------------------------------------- 
// Classe NavListVocab.

void NavListVocab::showOption(){
	cout << endl << "Listagem de vocabularios:" << endl;
}

void NavListVocab::execute(){
	list<Nome> vocab;
	list<Nome>::iterator it;

	showOption();

	CmdListVocab cmd(vocab);
	cmd.execute();

	cout << "Numero de vocabularios registrados - " << vocab.size() << endl;
	for (it = vocab.begin(); it != vocab.end(); it++) {
		cout << "\t- " << it->getNome() << endl;
	}
	cout << "Fim da listagem." << endl;
}

//--------------------------------------------------------------------------- 
// Classe NavShowVocab.

void NavShowVocab::showOption(){
	cout << endl << "Detalhes de vocabulario." << endl;
}

void NavShowVocab::execute(){
	string ivocab;
	Vocabulario_controlado vocab;
	Definicao defin;
	list<Nome> termo;
	list<Nome>::iterator it;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "Vocabulario desejado: ";
		getline(cin, ivocab);

		try{
			vocab.setNome(ivocab);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	CmdShowVocab cmd(vocab.getNome(), termo);
	
	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	vocab = cmd.getResultVocab();
	defin = cmd.getResultDefin();

	cout << endl << "Nome do vocabulario: " << vocab.getNome().getNome() << endl;
	cout << "Idioma do vocabulario: " << vocab.getIdioma().getIdioma() << endl;
	cout << "Definicao do vocabulario: " << defin.getTexto().getTexto() << endl;
	cout << "Ultima modificacao: " 	<< vocab.getDataCriacao().getDay() << "/" \
									<< vocab.getDataCriacao().getMonth() << "/" \
									<< vocab.getDataCriacao().getYear() << endl;
	cout << "Lista de termos: " << endl;
	cout << "Numero de termos registrados - " << termo.size() << endl;
	for (it = termo.begin(); it != termo.end(); it++) {
		cout << "\t- " << it->getNome() << endl;
	}
	cout << "Fim dos detalhes." << endl;
}

//--------------------------------------------------------------------------- 
// Classe NavShowTermo.

void NavShowTermo::showOption(){
	cout << endl << "Detalhes de termo." << endl;
}

void NavShowTermo::execute(){
	string itermo, ivocab;
	Nome vocab;	
	Termo termo;
	list<Texto> defin;
	list<Texto>::iterator it;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "De qual vocabulario eh: ";
		getline(cin, ivocab);
		cout << "Termo desejado: ";
		getline(cin, itermo);

		try{
			vocab.setNome(ivocab);
			termo.setNome(itermo);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	CmdShowTermo cmd(vocab, termo.getNome(), defin);
	
	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	termo = cmd.getResult();

	cout << endl << "Nome do termo: " << termo.getNome().getNome() << endl;
	cout << "Classe do termo: " << termo.getClasse().getClasse() << endl;
	cout << "Ultima modificacao: " 	<< termo.getDataCriacao().getDay() << "/" \
									<< termo.getDataCriacao().getMonth() << "/" \
									<< termo.getDataCriacao().getYear() << endl;
	cout << "Lista de definicoes: " << endl;
	cout << "Numero de definicoes registradas - " << defin.size() << endl;
	for (it = defin.begin(); it != defin.end(); it++) {
		cout << "\t- " << it->getTexto() << endl;
	}
	cout << "Fim dos detalhes." << endl;
}

//--------------------------------------------------------------------------- 
// Classe NavShowDefin.

void NavShowDefin::showOption(){
	cout << endl << "Detalhes de definicao." << endl;
}

void NavShowDefin::execute(){
	string itermo, ivocab, idefin;
	Nome vocab, termo;	
	Definicao defin;
	list<Nome> atermo;
	list<Nome>::iterator it;

	showOption();

	// Obtem input valido.
	while(true) {
		cout << "De qual vocabulario eh: ";
		getline(cin, ivocab);
		cout << "De qual termo eh: ";
		getline(cin, itermo);
		cout << "Definicao desejado: ";
		getline(cin, idefin);

		try{
			vocab.setNome(ivocab);
			termo.setNome(itermo);
			defin.setTexto(idefin);
			break;
		}
		catch (invalid_argument exp) {
			cout << endl << exp.what() << endl;
			cout << "Entrada invalida. Informe novamente os dados:" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	CmdShowDefin cmd(vocab, termo, defin.getTexto(), atermo);
	
	try{
		cmd.execute();
	}
	catch (invalid_argument exp) {
		cout << endl << exp.what() << endl;
		return;
	}

	defin = cmd.getResult();

	cout << endl << "Definicao: " << defin.getTexto().getTexto() << endl;
	cout << "Ultima modificacao: " 	<< defin.getDataCriacao().getDay() << "/" \
									<< defin.getDataCriacao().getMonth() << "/" \
									<< defin.getDataCriacao().getYear() << endl;
	cout << "Lista de termos associados: " << endl;
	cout << "Numero de termos associados - " << atermo.size() << endl;
	for (it = atermo.begin(); it != atermo.end(); it++) {
		cout << "\t- " << it->getNome() << endl;
	}
	cout << "Fim dos detalhes." << endl;
}
