
#include "Dominios.hpp"
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
		case JANEIRO:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Janeiro.");
			}
		break;

		case FEVEREIRO:		// Verificar ano bissexto.
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
		
		case MARCO:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Março.");
			}
		break;

		case ABRIL:
			if(dia < 1 || dia > 30) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 30 em Abril.");
			}
		break;
		
		case MAIO:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Maio.");
			}
		break;
		
		case JUNHO:
			if(dia < 1 || dia > 30) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 30 em Junho.");
			}
		break;
		
		case JULHO:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Julho.");
			}
		break;
		
		case AGOSTO:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Agosto.");
			}
		break;
		
		case SETEMBRO:
			if(dia < 1 || dia > 30) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 30 em Setembro.");
			}
		break;
		
		case OUTUBRO:
			if(dia < 1 || dia > 31) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 31 em Outubro.");
			}
		break;
		
		case NOVEMBRO:
			if(dia < 1 || dia > 30) {
				throw invalid_argument("Dia inválido. Dia deve ser um valor inteiro entre 1 e 30 em Novembro.");
			}
		break;
		
		case DEZEMBRO:
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

int Data::getDay(){
	return dia;
}

int Data::getMonth(){
	return mes;
}

int Data::getYear(){
	return ano;
}

//--------------------------------------------------------------------------- 
//Classe Email.

void Email::validar(string email) throw (invalid_argument){
	int arroba;
	const char* pt;
	bool dom_ndigit_ok = false;

	// Acha a separação do local e do domínio.
	pt = strchr(email.c_str(), '@');
	arroba = pt - email.c_str();

	// Chacagem do local.
		// Verifica se local começa ou termina com ponto final.
	if (email.at(0) == '.' || email.at(arroba - 1) == '.') {
		throw invalid_argument("Email inválido. O local do email não pode começar nem terminar com ponto final.");
	}
		// Verifica conteúdo do local.
	for (int i = 0; i < arroba; i++) {
		if (!isalnum(email.at(i))) {
			if (email.at(i) != '!' &&
				email.at(i) != '#' &&
				email.at(i) != '$' &&
				email.at(i) != '%' &&
				email.at(i) != '&' &&
				email.at(i) != '\'' &&
				email.at(i) != '*' &&
				email.at(i) != '+' &&
				email.at(i) != '-' &&
				email.at(i) != '/' &&
				email.at(i) != '=' &&
				email.at(i) != '?' &&
				email.at(i) != '^' &&
				email.at(i) != '_' &&
				email.at(i) != '`' &&
				email.at(i) != '{' &&
				email.at(i) != '|' &&
				email.at(i) != '}' &&
				email.at(i) != '~' &&
				email.at(i) != ';' &&
				email.at(i) != '.' ) {
				throw invalid_argument("Email inválido. Caracter inválido identificado no local do email.");
			}
		}
	}

	// Checagem do domínio.
		// Verifica se domínio começa ou termina com hifem.
	if (email.at(arroba + 1) == '-' || email.at(email.size() - 1) == '-') {
		throw invalid_argument("Email inválido. O domínio do email não pode começar nem terminar com hífem.");
	}
		// Verifica conteúdo do domínio.
	for (int i = arroba + 1; i < email.size(); i++) {
		if (!isdigit(email.at(i))) {
			dom_ndigit_ok = true;

			if (!isalpha(email.at(i))) {
				if (email.at(i) != '-') {
					throw invalid_argument("Email inválido. Caracter inválido identificado no domínio do email.");
				}
			}
		}
	}
		// Verifica se domínio consiste de apenas digitos.
	if(!dom_ndigit_ok) {
		throw invalid_argument("Email inválido. O domínio do email não pode consistir de apenas digitos numéricos.");
	}
}

void Email::setEmail(string email) throw (invalid_argument){
	validar(email);
	this->email = email;
}

string Email::getEmail(){
	return email;
}

//--------------------------------------------------------------------------- 
//Classe Senha.

void Senha::validar(string senha) throw (invalid_argument){
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

}

void Senha::setSenha(string senha) throw (invalid_argument){
	validar(senha);
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