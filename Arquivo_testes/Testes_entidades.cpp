#include "Testes_entidades.hpp"

void TestesEnt::iniciar(){
	resultado_teste = SUCESSO;
}

//--------------------------------------------------------------------------- 
//Teste Entidade Leitor.

void Teste_Leitor::leitorValido(){
	Nome joao;
	Nome marques;
	Email email;
	Senha senha;

	joao.setNome("Joao");
	marques.setNome("Marques");
	email.setEmail("JoaoMarques@email");
	senha.setSenha("Senha123", joao.getNome());
	try{

		leitor.setNome(joao);
		if (leitor.getNome().getNome() != "Joao"){
			resultado_teste = FALHA;
		}

		leitor.setSobrenome(marques);
		if (leitor.getSobrenome().getNome() != "Marques"){
			resultado_teste = FALHA;
		}

		leitor.setEmail(email);
		if (leitor.getEmail().getEmail() != "JoaoMarques@email"){
			resultado_teste = FALHA;
		}

		leitor.setSenha(senha);
		if (leitor.getSenha().getSenha() != "Senha123"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Leitor::run(){
	iniciar();

	leitorValido();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Entidade Leitor: Sucesso.\n");
    }
    else
    {
        printf("Teste da Entidade Leitor: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Entidade Desenvolvedor.

void Teste_Desenvolvedor::desenvolvedorValido(){
	Nome maria;
	Nome julia;
	Email email;
	Senha senha;
	Data data;

	maria.setNome("Maria");
	julia.setNome("Julia");
	email.setEmail("MaJu45@email");
	senha.setSenha("Senha123", maria.getNome());
	data.setData(10, 9, 2018);

	try{
		desenvolvedor.setNome(maria);
		if (desenvolvedor.getNome().getNome() != "Maria"){
			resultado_teste = FALHA;
		}

		desenvolvedor.setSobrenome(julia);
		if (desenvolvedor.getSobrenome().getNome() != "Julia"){
			resultado_teste = FALHA;
		}

		desenvolvedor.setEmail(email);
		if (desenvolvedor.getEmail().getEmail() != "MaJu45@email"){
			resultado_teste = FALHA;
		}

		desenvolvedor.setSenha(senha);
		if (desenvolvedor.getSenha().getSenha() != "Senha123"){
			resultado_teste = FALHA;
		}

		desenvolvedor.setData(data);
		if (desenvolvedor.getData().getDay() != 10 || desenvolvedor.getData().getMonth() != 9 || desenvolvedor.getData().getYear() != 2018){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Desenvolvedor::run(){
	iniciar();

	desenvolvedorValido();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Entidade Desenvolvedor: Sucesso.\n");
    }
    else
    {
        printf("Teste da Entidade Desenvolvedor: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Entidade Administrador.

void Teste_Administrador::admValido(){
	Nome mario;
	Nome olavo;
	Email email;
	Senha senha;
	Data data;
	Telefone telefone;

	mario.setNome("Mario");
	olavo.setNome("Olavo");
	email.setEmail("MaOlav@email");
	senha.setSenha("123Senha", mario.getNome());
	data.setData(10, 9, 2018);
	telefone.setTelefone("61981705486");

	try{
		adm.setNome(mario);
		if (adm.getNome().getNome() != "Mario"){
			resultado_teste = FALHA;
		}

		adm.setSobrenome(olavo);
		if (adm.getSobrenome().getNome() != "Olavo"){
			resultado_teste = FALHA;
		}

		adm.setEmail(email);
		if (adm.getEmail().getEmail() != "MaOlav@email"){
			resultado_teste = FALHA;
		}

		adm.setSenha(senha);
		if (adm.getSenha().getSenha() != "123Senha"){
			resultado_teste = FALHA;
		}

		adm.setData(data);
		if (adm.getData().getDay() != 10 || adm.getData().getMonth() != 9 || adm.getData().getYear() != 2018){
			resultado_teste = FALHA;
		}

		adm.setTelefone(telefone);
		if (adm.getTelefone().getTelefone() != "61 98170-5486"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Administrador::run(){
	iniciar();

	admValido();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Entidade Administrador: Sucesso.\n");
    }
    else
    {
        printf("Teste da Entidade Administrador: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Entidade DataCriacao.

void Teste_DataCriacao::dataValido(){
	Data criacao;

	criacao.setData(20, 4, 2015);

	try{
		data.setDataCriacao(criacao);
		if (data.getDataCriacao().getDay() != 20 || data.getDataCriacao().getMonth() != 4 || data.getDataCriacao().getYear() != 2015){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_DataCriacao::run(){
	iniciar();

	dataValido();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Entidade DataCriacao: Sucesso.\n");
    }
    else
    {
        printf("Teste da Entidade DataCriacao: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Entidade Vocabulário Controlado.

void Teste_Vocabulario::vocabValido(){
	Data criacao;
	Nome nome;
	Idioma idioma;

	nome.setNome("Vocabul");
	criacao.setData(20, 4, 2015);
	idioma.setIdioma("ENG");

	try{
		vocab.setDataCriacao(criacao);
		if (vocab.getDataCriacao().getDay() != 20 || vocab.getDataCriacao().getMonth() != 4 || vocab.getDataCriacao().getYear() != 2015){
			resultado_teste = FALHA;
		}

		vocab.setNome(nome);
		if (vocab.getNome().getNome() != "Vocabul"){
			resultado_teste = FALHA;
		}

		vocab.setIdioma(idioma);
		if (vocab.getIdioma().getIdioma() != "ENG"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Vocabulario::run(){
	iniciar();

	vocabValido();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Entidade Vocabulario: Sucesso.\n");
    }
    else
    {
        printf("Teste da Entidade Vocabulario: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Entidade Termo.

void Teste_Termo::termoValido(){
	Data criacao;
	Nome nome;
	Classe_de_termo classe;

	criacao.setData(20, 4, 2015);
	nome.setNome("Essenome");
	classe.setClasse("PT");

	try{
		termo.setDataCriacao(criacao);
		if (termo.getDataCriacao().getDay() != 20 || termo.getDataCriacao().getMonth() != 4 || termo.getDataCriacao().getYear() != 2015){
			resultado_teste = FALHA;
		}

		termo.setNome(nome);
		if (termo.getNome().getNome() != "Essenome"){
			resultado_teste = FALHA;
		}

		termo.setClasse(classe);
		if (termo.getClasse().getClasse() != "PT"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Termo::run(){
	iniciar();

	termoValido();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Entidade Termo: Sucesso.\n");
    }
    else
    {
        printf("Teste da Entidade Termo: Falha.\n");
    }
}

//--------------------------------------------------------------------------- 
//Teste Entidade Definicao.

void Teste_Definicao::defValido(){
	Data criacao;
	Texto texto;

	criacao.setData(20, 4, 2015);
	texto.setTexto("Esse é a definição");

	try{
		def.setDataCriacao(criacao);
		if (def.getDataCriacao().getDay() != 20 || def.getDataCriacao().getMonth() != 4 || def.getDataCriacao().getYear() != 2015){
			resultado_teste = FALHA;
		}

		def.setTexto(texto);
		if (def.getTexto().getTexto() != "Esse é a definição"){
			resultado_teste = FALHA;
		}
	}
	catch(invalid_argument){
		resultado_teste = FALHA;
	}
}

void Teste_Definicao::run(){
	iniciar();

	defValido();

	if(resultado_teste == SUCESSO)
    {
        printf("Teste da Entidade Definicao: Sucesso.\n");
    }
    else
    {
        printf("Teste da Entidade Definicao: Falha.\n");
    }
}