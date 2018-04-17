#include "Testes_dominios.hpp"

void Testes::iniciar(){
	resultado_teste = SUCESSO;
}

//--------------------------------------------------------------------------- 
//Teste Classe Nome.

void Teste_Nome::nomeValido(){
	try{
		nome.setNome("Carlos");
		if (nome.getNome() != "Carlos"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Nome::nomeVazio(){
	try{
		nome.setNome("");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Nome::nomeGrande(){
	try{
		nome.setNome("NomeMuitoGrandeMaiorQueVinteCaracteres");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Nome::nomeIniciaMinusculo(){
	try{
		nome.setNome("fabio");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Nome::nomeComNumero(){
	try{
		nome.setNome("Shablau67");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Nome::nomeNaoAlfanum(){
	try{
		nome.setNome("Nao ao esp@co");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Nome::run(){
	iniciar();

	// Casos de sucesso.
	nomeValido();
	// Casos de falha.
	nomeVazio();
	nomeGrande();
	nomeIniciaMinusculo();
	nomeComNumero();
	nomeNaoAlfanum();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Classe Nome: Sucesso.\n");
    }
    else
    {
        printf("Teste da Classe Nome: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Classe Telefone.

void Teste_Telefone::telefoneValido(){
	try{
		telefone.setTelefone("36780054199");
		if (telefone.getTelefone() != "36 78005-4199"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Telefone::telefonePequeno(){
	try{
		telefone.setTelefone("123");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Telefone::telefoneGrande(){
	try{
		telefone.setTelefone("999999999999");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Telefone::telefoneAlfa(){
	try{
		telefone.setTelefone("728y234n914");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Telefone::telefoneNaoAlfanum(){
	try{
		telefone.setTelefone("111?111!111");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Telefone::run(){
	iniciar();

	// Casos de sucesso.
	telefoneValido();
	// Casos de falha.
	telefonePequeno();
	telefoneGrande();
	telefoneAlfa();
	telefoneNaoAlfanum();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Classe Telefone: Sucesso.\n");
    }
    else
    {
        printf("Teste da Classe Telefone: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Classe Endereco.

void Teste_Endereco::enderecoValido(){
	try{
		endereco.setEndereco("UnB Darcy Ribeiro");
		if (endereco.getEndereco() != "UnB Darcy Ribeiro"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Endereco::enderecoVazio(){
	try{
		endereco.setEndereco("");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Endereco::enderecoGrande(){
	try{
		endereco.setEndereco("um lugar muito muito muito muito muuuuuuuito longe meeeeesmo");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Endereco::enderecoIniciaEspaco(){
	try{
		endereco.setEndereco(" ai nao pode");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Endereco::enderecoTerminaEspaco(){
	try{
		endereco.setEndereco("ai tbm nao da ");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Endereco::enderecoEspacoSeguido(){
	try{
		endereco.setEndereco("ta  com  parkson");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Endereco::enderecoNum(){
	try{
		endereco.setEndereco("El Chavo del 8");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Endereco::enderecoNaoAlfanum(){
	try{
		endereco.setEndereco("por ali->");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Endereco::run(){
	iniciar();

	// Casos de sucesso.
	enderecoValido();
	// Casos de falha.
	enderecoVazio();
	enderecoGrande();
	enderecoIniciaEspaco();
	enderecoTerminaEspaco();
	enderecoEspacoSeguido();
	enderecoNum();
	enderecoNaoAlfanum();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Classe Endereco: Sucesso.\n");
    }
    else
    {
        printf("Teste da Classe Endereco: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Classe Data.

void Teste_Data::dataValido(){
	try{
		data.setData(16, 4, 2018);
		if ((data.getDay() != 16)||(data.getMonth() != 4)||(data.getYear() != 2018)){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Data::dataBissexto(){
	try{
		data.setData(29, 2, 2004);
		if ((data.getDay() != 29)||(data.getMonth() != 2)||(data.getYear() != 2004)){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Data::dataAnoPequeno(){
	try{
		data.setData(1, 1, 1899);
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Data::dataAnoGrande(){
	try{
		data.setData(1, 1, 2100);
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Data::dataMesPequeno(){
	try{
		data.setData(1, 0, 2018);
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Data::dataMesGrande(){
	try{
		data.setData(1, 13, 2018);
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Data::dataDiaPequeno(){
	try{
		data.setData(0, 1, 2018);
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Data::dataDiaGrande(){
	try{
		data.setData(40, 1, 2018);
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Data::dataNaoBissexto(){
	try{
		data.setData(29, 2, 2005);
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Data::run(){
	iniciar();

	// Casos de sucesso.
	dataValido();
	dataBissexto();
	// Casos de falha.
	dataAnoPequeno();
	dataAnoGrande();
	dataMesPequeno();
	dataMesGrande();
	dataDiaPequeno();
	dataDiaGrande();
	dataNaoBissexto();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Classe Data: Sucesso.\n");
    }
    else
    {
        printf("Teste da Classe Data: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Classe Email.

void Teste_Email::emailValido(){
	try{
		email.setEmail("lo#c.al@d0mi-ni0");
		if (email.getEmail() != "lo#c.al@d0mi-ni0"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Email::emailLocalIniciaPonto(){
	try{
		email.setEmail(".local@dominio");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Email::emailLocalTerminaPonto(){
	try{
		email.setEmail("local.@dominio");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Email::emailLocalCaracterInvalido(){
	try{
		email.setEmail("lo[]cal@dominio");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Email::emailDominioIniciaHifem(){
	try{
		email.setEmail("local@-dominio");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Email::emailDominioTerminaHifem(){
	try{
		email.setEmail("local@dominio-");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Email::emailDominioOnlyNum(){
	try{
		email.setEmail("local@123");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Email::emailDominioNaoHifemAlfanum(){
	try{
		email.setEmail("local@dom!n!o");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Email::run(){
	iniciar();

	// Casos de sucesso.
	emailValido();
	// Casos de falha.
	emailLocalIniciaPonto();
	emailLocalTerminaPonto();
	emailLocalCaracterInvalido();
	emailDominioIniciaHifem();
	emailDominioTerminaHifem();
	emailDominioOnlyNum();
	emailDominioNaoHifemAlfanum();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Classe Email: Sucesso.\n");
    }
    else
    {
        printf("Teste da Classe Email: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Classe Senha.

void Teste_Senha::iniciar(){
	resultado_teste = SUCESSO;
	nome.setNome("Ana");
}

void Teste_Senha::senhaValido(){
	try{
		senha.setSenha("Senha123", nome.getNome());
		if (senha.getSenha() != "Senha123"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Senha::senhaPequeno(){
	try{
		senha.setSenha("A2c", nome.getNome());
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Senha::senhaGrande(){
	try{
		senha.setSenha("Senha00000000", nome.getNome());
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Senha::senhaNoNum(){
	try{
		senha.setSenha("Senhaaaa", nome.getNome());
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Senha::senhaNoMaiusculo(){
	try{
		senha.setSenha("senha123", nome.getNome());
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Senha::senhaNoMinusculo(){
	try{
		senha.setSenha("SENHA123", nome.getNome());
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Senha::senhaContemUsuario(){
	try{
		senha.setSenha("SenhaAna", nome.getNome());
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Senha::senhaNaoAlfanum(){
	try{
		senha.setSenha("Senh@123", nome.getNome());
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Senha::run(){
	iniciar();

	// Casos de sucesso.
	senhaValido();
	// Casos de falha.
	senhaPequeno();
	senhaGrande();
	senhaNoNum();
	senhaNoMaiusculo();
	senhaNoMinusculo();
	senhaContemUsuario();
	senhaNaoAlfanum();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Classe Senha: Sucesso.\n");
    }
    else
    {
        printf("Teste da Classe Senha: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Classe Texto.

void Teste_Texto::textoValido(){
	try{
		texto.setTexto("Cevadis im ampola pa arma");
		if (texto.getTexto() != "Cevadis im ampola pa arma"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Texto::textoPequeno(){
	try{
		texto.setTexto("");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Texto::textoGrande(){
	try{
		texto.setTexto("A ordem dos tratores não altera o pão duris.");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Texto::run(){
	iniciar();

	// Casos de sucesso.
	textoValido();
	// Casos de falha.
	textoPequeno();
	textoGrande();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Classe Texto: Sucesso.\n");
    }
    else
    {
        printf("Teste da Classe Texto: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Classe Idioma.

void Teste_Idioma::idiomaEng(){
	try{
		idioma.setIdioma("ENG");
		if (idioma.getIdioma() != "ENG"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Idioma::idiomaFra(){
	try{
		idioma.setIdioma("FRA");
		if (idioma.getIdioma() != "FRA"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Idioma::idiomaGer(){
	try{
		idioma.setIdioma("GER");
		if (idioma.getIdioma() != "GER"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Idioma::idiomaIta(){
	try{
		idioma.setIdioma("ITA");
		if (idioma.getIdioma() != "ITA"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Idioma::idiomaPor(){
	try{
		idioma.setIdioma("POR");
		if (idioma.getIdioma() != "POR"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Idioma::idiomaSpa(){
	try{
		idioma.setIdioma("SPA");
		if (idioma.getIdioma() != "SPA"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Idioma::idiomaInvalido(){
	try{
		idioma.setIdioma("Japones");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Idioma::run(){
	iniciar();

	// Casos de sucesso.
	idiomaEng();
	idiomaFra();
	idiomaGer();
	idiomaIta();
	idiomaPor();
	idiomaSpa();
	// Casos de falha.
	idiomaInvalido();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Classe Idioma: Sucesso.\n");
    }
    else
    {
        printf("Teste da Classe Idioma: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Classe Termo.

void Teste_Classe_de_termo::classePT(){
	try{
		classe.setClasse("PT");
		if (classe.getClasse() != "PT"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Classe_de_termo::classeNP(){
	try{
		classe.setClasse("NP");
		if (classe.getClasse() != "NP"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Classe_de_termo::classeInvalido(){
	try{
		classe.setClasse("Preferido");
		resultado_teste = FALHA;
	}
	catch(invalid_argument){
		return;
	}
}

void Teste_Classe_de_termo::run(){
	iniciar();

	// Casos de sucesso.
	classePT();
	classeNP();
	// Casos de falha.
	classeInvalido();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Classe Classe_de_termo: Sucesso.\n");
    }
    else
    {
        printf("Teste da Classe Classe_de_termo: Falha.\n");
    }
}
