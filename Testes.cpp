#include "Dominios.cpp"
#include "Testes.hpp"

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
	void dataValido();
	void dataBissexto();
	// Casos de falha.
	void dataAnoPequeno();
	void dataAnoGrande();
	void dataMesPequeno();
	void dataMesGrande();
	void dataDiaPequeno();
	void dataDiaGrande();
	void dataNaoBissexto();

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
