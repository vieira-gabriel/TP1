#include "Dominios.hpp"
#include <stdbool.h>

#define E_DOMINIO 1
#define NAO_E_DOMINIO 0
//Essas variáveis serão usadas para saber que parte do email é o dominio ou a parte local

bool eh_maiusculo(char caractere){
	if(caractere >= 'A' && caractere <= 'Z') return true;
	return false;
}

bool eh_minusculo(char caractere){
	if(caractere >= 'a' && caractere <= 'z') return true;
	return false;
}

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
			throw invalid_argument("Nome inválido. Usar apenas caracteres.");
		}
	}

	// Lança exceção se a primeira letra não for maiúscula (segundo tabela ASCII).
	if (!eh_maiusculo(nome[0])) {
		throw invalid_argument("Nome inválido. Primeira letra deve ser maiúscula.");
	}
}

void Nome::setNome(string nome) throw (invalid_argument){
	validar(nome);
	this->nome = nome;
}

string Nome::callNome(){
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

string Telefone::callTelefone(){
	return telefone;
}

//--------------------------------------------------------------------------- 
//Classe Endereco.

void Endereco::validar(string endereco) throw (invalid_argument){
	// Lança exceção se o endereco possuir menos que 1 caracteres ou se nome maior que 20 caracteres.
	if (endereco.length() > 20 || endereco.length() < 1) {
		throw invalid_argument("Endereço inválido. Endereço precisa ter entre 1 a 20 caracteres.");
	}

	// Lança exceção se a primeira letra for espaço.
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
				throw invalid_argument("Endereço inválido. Usar apenas caracteres e espaço.");
			}
		}
	}
}

void Endereco::setEndereco(string endereco) throw (invalid_argument){
	validar(endereco);
	this->endereco = endereco;
}

string Endereco::callEndereco(){
	return endereco;
}
/*
//--------------------------------------------------------------------------- 
//Classe Data.

void Data::validar(int dia, int mes, int ano) throw (invalid_argument){
	//Validação quanto ao ano
	if(ano < 1900 || ano > 2099) throw invalid_argument("Argumento inválido. Ano deve ser um valor inteiro entre 1900 e 2099");

	//Validação quanto ao mês
	if(mes < 1 || mes > 12) throw invalid_argument("Argumento inválido. Mes deve ser um valor inteiro ente 1 e 12");

	//Validação do dia (considerando que todos os meses possuem 31 dias)
	if(mes < 1 || mes > 12) throw invalid_argument("Argumento inválido. Dia deve ser um valor inteiro ente 1 e 31");
}

void Data::setData(int dia, int mes, int ano) throw (invalid_argument){
	validar(dia, mes, ano);
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

void Data::callData(Email objeto){
	//FAZER ESSE CÓDIGO
}

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

void Email::callEmail(Email objeto){
	//FAZER ESSE CÓDIGO
}

//--------------------------------------------------------------------------- 
//Classe Senha.

void Senha::validar(string senha) throw (invalid_argument){
	int quant_letras_maiusculas = 0;	//Quantidades de letras maiúsculas na senha. É necessário ter pelo menos uma
	int quant_letras_minusculas = 0;	//Quantidades de letras minusculas na senha. É necessário ter pelo menos uma
	int quant_digitos = 0;				//Quantidades de digitos na senha. É necessário ter pelo menos um

	for (int i = 0; i < senha.length(); ++i){
		if (eh_maiusculo(senha[i])) ++quant_letras_maiusculas;
		else if (eh_minusculo(senha[i])) ++quant_letras_minusculas;
		else if (isdigit(senha[i])) ++quant_digitos;
		else throw invalid_argument("Argumento inválido. Senha só pode conter letras e digitos.");
	}
	if(quant_digitos == 0 || quant_letras_minusculas == 0 || quant_letras_maiusculas == 0) throw invalid_argument("Argumento inválido. Senha precisa conter, pelo menos, uma letra
maiúscula, uma letra minúscula e um dígito.");
}

void Senha::setSenha(string senha) throw (invalid_argument){
	validar(senha, usuario);
	this->senha = senha;
}

void Senha::callSenha(Senha objeto){
	//FAZER ESSE CÓDIGO
}

//--------------------------------------------------------------------------- 
//Classe Texto.

void Texto::validar(string texto) throw (invalid_argument){
	if (texto.length() > 30) throw invalid_argument("Argumento inválido. Texto possui mais que 30 caracteres.")
}

void Texto::setTexto(string texto) throw (invalid_argument){
	validar(texto);
	this->texto - texto;
}

void Texto::callTexto(Texto objeto){
	//FAZER ESSE CÓDIGO
}

void Idioma::validar(char idioma[]) throw (invalid_argument){
	if(idioma != "ENG\0" || idioma != "FRA\0" || idioma != "GER\0" || idioma != "ITA\0" || idioma != "POR\0" || idioma != "SPA\0") throw invalid_argument("Argumento inválido. As entradas válidas são ENG (inglês), FRA (francês), GER (alemão), ITA (italiano), POR
(português) ou SPA (espanhol).");
}

//--------------------------------------------------------------------------- 
//Classe Idioma.

void Idioma::setIdioma(char idioma[]) throw (invalid_argument){
	validar(idioma);
	for (int i = 0; i < 3; ++i){ //O valor 3 é o numero de caracteres que define o idioma
		this->idioma[i] = idioma[i];
	}
}

void Idioma::callIdioma(Idioma objeto){
	//FAZER ESSE CÓDIGO
}

//--------------------------------------------------------------------------- 
//Classe Termo.

void Classe_de_termo::validar(char classe[]) throw (invalid_argument){
	if(classe != "PT\0" || classe != "NP\0") throw invalid_argument("Argumento inválido. As entradas válidas são PT (preferred term) ou NP (non preferred term).");
}

void Classe_de_termo::setClasse_de_termpo(char idioma[]) throw (invalid_argument){
	validar(idioma);
	for (int i = 0; i < 3; ++i){ //O valor 3 é o numero de caracteres que define o idioma
		this->idioma[i] = idioma[i];
	}
}

void Classe_de_termo::callClasse_de_termpo(Classe_de_termo objeto){
	//FAZER ESSE CÓDIGO
}

*/


int main(){
	Nome name;
	Telefone numero;
	Endereco ende;

	string number = "11222223333"; 
	string carlos = "CarlosMax";
	string alex = "alex";
	string local = "uni ceub";
	string unb = "UnB";

	numero.setTelefone(number);
	name.setNome(carlos);
	ende.setEndereco(local);

	number = numero.callTelefone();
	alex = name.callNome();
	unb = ende.callEndereco(); 
	printf("%s\n", number.c_str());
	printf("%s\n", alex.c_str());
	printf("%s\n", unb.c_str());

	return 0; 
}