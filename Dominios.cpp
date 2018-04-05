#include "Dominios.hpp"

#define E_DOMINIO 1
#define NAO_E_DOMINIO 0
//Essas variáveis serão usadas para saber que parte do email é o dominio ou a parte local

bool eh_maiusculo(char caractere){
	if(caractere >= 'A' && caractere <= 'Z') return TRUE;
	return FALSE;
}

bool eh_minusculo(char caractere){
	if(caractere >= 'a' && caractere <= 'z') return TRUE;
	return FALSE;
}

bool eh_numero(char caractere){
	if(caractere >= '0' && caractere <= '9') return TRUE;
	return FALSE;
}

// As três funções acima são para verificar se determinado caractere de uma string é maiúsculo, minúsculo ou numero, respectivamente
// Essas funções usam a tabela ASCII como referência.

void Nome::validar(string nome) throw (invalid_argument){
	// Lança exceção se a primeira letra não for maiúscula (segunto tabela ASCII).

	if (!eh_maiusculo(nome[0])) throw invalid_argument("Argumento inválido. Primeira letra deve ser maiúscula");

	// Lança exceção se o nome possuir menos que 20 caracteres.
	//nome.length() retorna o tamanho da string nome

	if (nome.length() > 20 || nome.length() < 1) throw invalid_argument("Argumento inválido. Nome precisa ter entre 1 e 20 caracteres");
}

void Nome::setNome(string nome) throw (invalid_argument){
	validar(nome);
	this->nome = nome;
}

void Nome::callNome(){
	//FAZER ESSE CÓDIGO
}

void Telefone::validar(char telefone[]) throw (invalid_argument){
	int i = 0, end = 0, num = 0;

	while (!end){
		if (eh_numero(telefone[i])){		// Se for numero adiciona contador.
			num++;
		}
		else if (telefone[i] == '\0'){		// Se for fim de string.
			if (num == 11){						// Confirma tamanho de telefone.
				end = 1;
			}
			else{
				throw invalid_argument("Argumento invalido. O telefone deve ter 11 digitos.");
			}
		}
		else{		// Digito invalido.
			throw invalid_argument("Argumento invalido. O telefone deve possuir apenas digitos de 0-9.");
		}

		i++;
		if (i > 11) throw invalid_argument("Argumento invalido. O telefone deve ter 11 digitos.");		// Tamanho invalido.
	}
}

void Telefone::setTelefone(char telefone[]) throw (invalid_argument){ 
	validar(telefone);    // Valida telefone fornecido. 
	int valor[14]; 
	valor[2] = ' '; 
	valor[8] = '-'; 
	valor[13] = '\0'; 

	//Esse loop for é para guardar o valor no formato AA NNNNN-NNNN
	for (int posicao1 = 0, int posicao2; posicao1 < 11; ++posicao1, ++posicao2){
		if (posicao1 == 2 || posicao1 == 8) ++posicao1;
		valor[posicao1] = telefone[posicao2];
	}
	//Essa função é para guardar o valor no formato AA NNNNN-NNNN
	this->telefone_char = valor; 
	this->telefone_int = atoi(telefone);  // Armazena em formato inteiro o telefone.
}
void Telefone::callTelefone(){
	//FAZER ESSE CÓDIGO
}

void Endereco::validar(string endereco) throw (invalid_argument){
	int tamanho = endereco.length();
	if (tamanho > 20 || tamanho < 1) throw invalid_argument("Argumento inválido. Endereço precisa ter entre 1 e 20 caracteres");

	//Se o primeiro ou o ultimo caractere for " ", retornara um argumento inválido
	if (endereco[0] == ' ' || endereco[tamanho-1]) throw invalid_argument("Argumento inválido. Primeiro ou ultimo caractere não pode ser espaço em branco");
	//(tamanho-1) é a posição no ventor do ultimo caractere


}

void Endereco::setEndereco(string endereco) throw (invalid_argument){
	validar(endereco);
	this->endereco = endereco;
}

void Endereco::callEndereco(Endereco objeto){
	//FAZER ESSE CÓDIGO
}

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
			if(!(eh_maiusculo(email[i]) || eh_minusculo(email[i]) || eh_numero(email[i]))) throw invalid_argument("Argumento inválido. Dominio com caracteres inválidos");
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

void Senha::validar(string senha) throw (invalid_argument){
	int quant_letras_maiusculas = 0;	//Quantidades de letras maiúsculas na senha. É necessário ter pelo menos uma
	int quant_letras_minusculas = 0;	//Quantidades de letras minusculas na senha. É necessário ter pelo menos uma
	int quant_digitos = 0;				//Quantidades de digitos na senha. É necessário ter pelo menos um

	for (int i = 0; i < senha.length(); ++i){
		if (eh_maiusculo(senha[i])) ++quant_letras_maiusculas;
		else if (eh_minusculo(senha[i])) ++quant_letras_minusculas;
		else if (eh_numero(senha[i])) ++quant_digitos;
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

void Idioma::setIdioma(char idioma[]) throw (invalid_argument){
	validar(idioma);
	for (int i = 0; i < 3; ++i){ //O valor 3 é o numero de caracteres que define o idioma
		this->idioma[i] = idioma[i];
	}
}

void Idioma::callIdioma(Idioma objeto){
	//FAZER ESSE CÓDIGO
}

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