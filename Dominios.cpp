#include "Dominios.hpp"
#include <stdbool.h>

//Essas variáveis serão usadas para saber que parte do email é o dominio ou a parte local
#define E_DOMINIO 1
#define NAO_E_DOMINIO 0

//--------------------------------------------------------------------------- 
//Classe Nome.

void Nome::validar(string nome) throw (invalid_argument){
	// Lança exceção se o nome possuir menos que 1 caracteres ou se nome maior que 20 caracteres.
	// nome.length() retorna o tamanho da string nome
	if (nome.length() > 20 || nome.length() < 1) {
		throw invalid_argument("Nome inválido. Nome precisa ter entre 1 a 20 caracteres.");
	}

	// Lanca excecao se nao for um alfabetico.
	for (int i = 0; i < nome.size(); i++) {
		if (!isalpha(nome.at(i))) {
			throw invalid_argument("Nome inválido. Usar apenas caracteres alfabéticos.");
		}
	}

	// Lança exceção se a primeira letra não for maiúscula (segundo tabela ASCII).
	if (!isupper(nome[0])) {
		throw invalid_argument("Nome inválido. Primeira letra deve ser maiúscula.");
	}
}

void Nome::setNome(string nome) throw (invalid_argument){
	validar(nome);
	this->nome = nome;
}

string Nome::getNome(){
	return nome;
}

//--------------------------------------------------------------------------- 
//Classe Telefone.

void Telefone::validar(string telefone) throw (invalid_argument){ 
	if (telefone.size() != 11) { 
		throw invalid_argument("Telefone inválido. O telefone deve ter 11 digitos."); 
	} 
	for (int i = 0; i < telefone.size(); i++) { 
		if (!isdigit(telefone.at(i))) { 
			throw invalid_argument("Telefone inválido. É valido apenas digitos de 0 a 9."); 
		} 
	}
}

void Telefone::setTelefone(string telefone) throw (invalid_argument){  
	validar(telefone);

	string valor = "AA NNNNN-NNNN";
	valor[2] = ' ';
	valor[8] = '-';
	valor[13] = '\0';
   
	//Esse loop for é para guardar o valor no formato AA NNNNN-NNNN. 
	for (int posicao1 = 0, posicao2 = 0; posicao2 < telefone.size(); posicao1++, posicao2++){ 
		if (posicao1 == 2 || posicao1 == 8) {
			posicao1++;
		}
		valor[posicao1] = telefone[posicao2];
	}

	this->telefone = valor;
}

string Telefone::getTelefone(){
	return telefone;
}

//--------------------------------------------------------------------------- 
//Classe Endereco.

void Endereco::validar(string endereco) throw (invalid_argument){
	// Lança exceção se o endereco possuir menos que 1 caracteres ou se nome maior que 20 caracteres.
	if (endereco.length() > 20 || endereco.length() < 1) {
		throw invalid_argument("Endereço inválido. Endereço precisa ter entre 1 a 20 caracteres.");
	}

	// Lança exceção se a primeira ou ultima letra for espaço.
	if (endereco[0] == ' ' || endereco[endereco.size() - 1] == ' ') {
		throw invalid_argument("Endereço inválido. Primeira e a última letra não podem ser espaço.");
	}

	// Lanca excecao se nao for um alfabetico ou tiver espaços seguidos.
	for (int i = 0; i < endereco.size(); i++) {
		if (!isalpha(endereco.at(i))) {
			if (endereco.at(i) == ' ') {
				if (endereco.at(i - 1) == ' ') {
					throw invalid_argument("Endereço inválido. Não pode utilizar espaços seguidos.");
				}
			}
			else {
				throw invalid_argument("Endereço inválido. Usar apenas caracteres alfabeticos e espaço.");
			}
		}
	}
}

void Endereco::setEndereco(string endereco) throw (invalid_argument){
	validar(endereco);
	this->endereco = endereco;
}

string Endereco::getEndereco(){
	return endereco;
}

//--------------------------------------------------------------------------- 
//Classe Data.

void Data::validar(int dia, int mes, int ano) throw (invalid_argument){
	// Validação quanto ao ano.
	if(ano < 1900 || ano > 2099) {
		throw invalid_argument("Ano inválido. Ano deve ser um valor inteiro entre 1900 e 2099.");
	}

	// Validação quanto ao mês.
	if(mes < 1 || mes > 12) {
		throw invalid_argument("Mês inválido. Mês deve ser um valor inteiro entre 1 e 12.");
	}

	// Validação quanto ao dia.
	switch(mes){
		case 1:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Janeiro.");
			}
		break;

		case 2:		// Verificar ano bissexto.
			if (ano%4 == 0) {		// Multiplo de 4.
				if (ano%100 == 0) {		// Multiplo de 4 e 100.
					if (ano%400 == 0) {		// Multiplo de 4 e 100 e 400.
						if(dia < 1 || dia > 29) {
							throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 29 nesse mês de Fevereiro.");
						}
						break;
					}
					
					if(dia < 1 || dia > 28) {
						throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 28 nesse mês de Fevereiro.");
					}
					break;
				}

				if(dia < 1 || dia > 29) {
					throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 29 nesse mês de Fevereiro.");
				}
			}
			else {
				if(dia < 1 || dia > 28) {
					throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 28 nesse mês de Fevereiro.");
				}
			}
		break;
		
		case 3:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Março.");
			}
		break;

		case 4:
			if(dia < 1 || dia > 30) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 30 em Abril.");
			}
		break;
		
		case 5:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Maio.");
			}
		break;
		
		case 6:
			if(dia < 1 || dia > 30) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 30 em Junho.");
			}
		break;
		
		case 7:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Julho.");
			}
		break;
		
		case 8:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Agosto.");
			}
		break;
		
		case 9:
			if(dia < 1 || dia > 30) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 30 em Setembro.");
			}
		break;
		
		case 10:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Outubro.");
			}
		break;
		
		case 11:
			if(dia < 1 || dia > 30) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 30 em Novembro.");
			}
		break;
		
		case 12:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Dezembro.");
			}
		break;
		
		default:
		break;	
	}
}

void Data::setData(int dia, int mes, int ano) throw (invalid_argument){
	validar(dia, mes, ano);
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

void Data::getData(int* data){
	data[0] = dia;
	data[1] = mes;
	data[2] = ano;
}
/*
//--------------------------------------------------------------------------- 
//Classe Email.

void Email::validar(string email) throw (invalid_argument){
	int dominio = NAO_E_DOMINIO; //Como o código vai percorrer cada caractere da string, quando ele achar o @ ele mudará essa variável para E_DOMINIO
	int fim_local, inicio_dominio, quantidade_numeros_dominio = 0; //essa ultima variável servirá para verificar se no dominio existem caracteres q n são só números

	for (int i = 0; i < email.length(); ++i){
		if (dominio == NAO_E_DOMINIO){
			if(email[i] == '@') dominio = E_DOMINIO;
			fim_local = i - 1;
			inicio_dominio = i + 1;
		}
		else if (dominio == E_DOMINIO){
			if(!(eh_maiusculo(email[i]) || eh_minusculo(email[i]) || isdigit(email[i]))) throw invalid_argument("Argumento inválido. Dominio com caracteres inválidos");
			if (email[i] >= '0' && email[i] <= '9') ++quantidade_numeros_dominio;

			//Nessa parte, verifica-se se o dominio é composto somente por números
			if (quantidade_numeros_dominio == email.length() - inicio_dominio) throw invalid_argument("Argumento inválido. Dominio não pode possuir somente números");
		}
	}
	if(email[0] == '.' || email[fim_local] == '.') throw invalid_argument("Argumento inválido. Primeiro e ultimo caractere da parte local não pode ser '.'");
	if(email[inicio_dominio] == '-' || email[email.length() - 1] == '-') throw invalid_argument("Argumento inválido. Primeiro e ultimo caractere do domínio não pode ser '-'");
}

void Email::setEmail(string email) throw (invalid_argument){
	validar(email);
	this->email = email
}

void Email::getEmail(Email objeto){
	//FAZER ESSE CÓDIGO
}
*/
//--------------------------------------------------------------------------- 
//Classe Senha.

void Senha::validar(string senha, string nome) throw (invalid_argument){
	bool digit_ok = false, upper_ok = false, lower_ok = false;

	// Verifica tamanho da senha.
	if (senha.size() != 8) {
		throw invalid_argument("Senha inválida. Senha deve possuir 8 caracteres.");
	}

	// Verifica conteúdo de senha.
	for (int i = 0; i < senha.size(); i++) {
		if (isdigit(senha.at(i))) {
			digit_ok = true;
		}
		else if (isupper(senha.at(i))) {
			upper_ok = true;
		}
		else if (islower(senha.at(i))) {
			lower_ok = true;
		}
		else {
			throw invalid_argument("Senha inválida. Senha deve possuir apenas caracteres alfabéticos e digitos de 0 a 9.");
		}
	}
	if (!digit_ok) {
		throw invalid_argument("Senha inválida. Senha precisa conter no mínimo um número.");
	}
	if (!upper_ok) {
		throw invalid_argument("Senha inválida. Senha precisa conter no mínimo uma letra maiúscula.");
	}
	if (!lower_ok) {
		throw invalid_argument("Senha inválida. Senha precisa conter no mínimo uma letra minúscula.");
	}

	// Verifica se nome do usuário está contido na senha. Sem muita persistência.
	if (strstr(senha.c_str(), nome.c_str()) != NULL) {
		throw invalid_argument("Senha inválida. Senha não pode conter o nome do usuário.");
	}
	nome.at(0) = nome.at(0) + 32;	// Transforma primeira letra em mińúscula e compara novamente.
	if (strstr(senha.c_str(), nome.c_str()) != NULL) {
		throw invalid_argument("Senha inválida. Senha não pode conter o nome do usuário.");
	}
}

void Senha::setSenha(string senha, string nome) throw (invalid_argument){
	validar(senha, nome);
	this->senha = senha;
}

string Senha::getSenha(){
	return senha;
}

//--------------------------------------------------------------------------- 
//Classe Texto.

void Texto::validar(string texto) throw (invalid_argument){
	// Verifica o tamanho do texto de definição.
	if (texto.length() < 1 || texto.length() > 30) {
		throw invalid_argument("Texto de definição inválido. Texto deve possuir de 1 a 30 caracteres.");
	}
}

void Texto::setTexto(string texto) throw (invalid_argument){
	validar(texto);
	this->texto = texto;
}

string Texto::getTexto(){
	return texto;
}

//--------------------------------------------------------------------------- 
//Classe Idioma.

void Idioma::validar(string idioma) throw (invalid_argument){
	// Verifica se é uma entrada válida.
	if(	strcmp(idioma.c_str(), "ENG") && 
		strcmp(idioma.c_str(), "FRA") && 
		strcmp(idioma.c_str(), "GER") && 
		strcmp(idioma.c_str(), "ITA") && 
		strcmp(idioma.c_str(), "POR") && 
		strcmp(idioma.c_str(), "SPA") ) {
		throw invalid_argument("Idioma inválido. As entradas válidas são ENG(inglês), FRA(francês), GER(alemão), ITA(italiano), POR(português) ou SPA(espanhol).");
	}
}

void Idioma::setIdioma(string idioma) throw (invalid_argument){
	validar(idioma);
	this->idioma = idioma;
}

string Idioma::getIdioma(){
	return idioma;
}

//--------------------------------------------------------------------------- 
//Classe Classe_de_Termo.

void Classe_de_termo::validar(string classe) throw (invalid_argument){
	// Verifica se é uma entrada válida.
	if(strcmp(classe.c_str(), "PT") && strcmp(classe.c_str(), "NP")) {
		throw invalid_argument("Classe de termo inválido. As entradas válidas são PT(preferred term) ou NP(non preferred term).");
	}
}

void Classe_de_termo::setClasse(string classe) throw (invalid_argument){
	validar(classe);
	this->classe = classe;
}

string Classe_de_termo::getClasse(){
	return classe;
}



//---------------------------------------------------------------------------
// Main de teste.
int main(){
	Nome nome;
	Telefone numero;
	Endereco ende;
	Data date;
	Senha senha;
	Texto texto;
	Idioma idioma;
	Classe_de_termo classe;

	string number = "11222223333"; 
	string carlos = "Carl";
	string alex = "alex";
	string local = "uni ceub";
	string unb = "UnB";
	int data[3] = {0, 0, 0};
	string password = "";
	string txt = "abc";
	string speek = "";
	string claxe = "";

	numero.setTelefone(number);
	nome.setNome(carlos);
	ende.setEndereco(local);
	date.setData(7, 4, 2018);
	senha.setSenha("A2cArlg3", nome.getNome());
	texto.setTexto("Qu@lquer cois@ pro texto.");
	idioma.setIdioma("ITA");
	classe.setClasse("NP");

	number = numero.getTelefone();
	alex = nome.getNome();
	unb = ende.getEndereco();
	date.getData(data);
	password = senha.getSenha();
	txt = texto.getTexto();
	speek = idioma.getIdioma();
	claxe = classe.getClasse();

	printf("%s\n", number.c_str());
	printf("%s\n", alex.c_str());
	printf("%s\n", unb.c_str());
	printf("%d/%d/%d\n", data[0], data[1], data[2]);
	printf("%s\n", password.c_str());
	printf("%s\n", txt.c_str());
	printf("%s\n", speek.c_str());
	printf("%s\n", claxe.c_str());

	return 0; 
}