#include "Dominios.hpp"

#define E_DOMINIO 1
#define NAO_E_DOMINIO 0
//Essas variáveis serão usadas para saber que parte do email é o dominio ou a parte local

void Nome::validar(string nome) throw (invalid_argument){
	// Lança exceção se a primeira letra não for maiúscula (segunto tabela ASCII).

	if (nome[0] < 'A' || nome[0 > 'Z']) throw invalid_argument("Argumento invalido. Primeira letra deve ser maiúscula");

	// Lança exceção se o nome possuir menos que 20 caracteres.
	//nome.length() retorna o tamanho da string nome

	if (nome.length() > 20 || nome.length() < 1) throw invalid_argument("Argumento invalido. Nome precisa ter entre 1 e 20 caracteres");
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
		if (telefone[i] <= '9' && '0' <= telefone[i]){		// Se for numero adiciona contador.
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
	validar(telefone);		// Valida telefone fornecido.
	int valor[14];
	valor[2] = ' ';
	valor[8] = '-';
	valor[13] = '\0';

	//Esse loop for é para guardar o valor no formato AA NNNNN-NNNN
	for (int posicao1 = 0, int posicao2; posicao1 < 11; ++posicao1, ++posicao2){
		if (posicao1 == 2 || posicao1 == 8) ++posicao1;
		valor[posicao1] = telefone[posicao2];
	}
	
	this->telefone_char = valor;
	this->telefone_int = atoi(telefone);	// Armazena em formato inteiro o telefone.
}
void Telefone::callTelefone(){
	//FAZER ESSE CÓDIGO
}

void Endereco::validar(string endereco) throw (invalid_argument){
	int tamanho = endereco.length();
	if (tamanho > 20 || tamanho < 1) throw invalid_argument("Argumento invalido. Endereço precisa ter entre 1 e 20 caracteres");

	//Se o primeiro ou o ultimo caractere for " ", retornara um argumento inválido
	if (endereco[0] == ' ' || endereco[tamanho-1]) throw invalid_argument("Argumento invalido. Primeiro ou ultimo caractere não pode ser espaço em branco");
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
	if(ano < 1900 || ano > 2099) throw invalid_argument("Argumento invalido. Ano deve ser um valor inteiro entre 1900 e 2099");

	//Validação quanto ao mês
	if(mes < 1 || mes > 12) throw invalid_argument("Argumento invalido. Mes deve ser um valor inteiro ente 1 e 12");

	//Validação do dia (considerando que todos os meses possuem 31 dias)
	if(mes < 1 || mes > 12) throw invalid_argument("Argumento invalido. Dia deve ser um valor inteiro ente 1 e 31");
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
			if(!((email[i] >= 'A' && email <= 'Z') || (email[i] >= 'a' && email <= 'z') || (email[i] >= '0' && email <= '9'))) throw invalid_argument("Argumento invalido. Dominio com caracteres inválidos");
			if (email[i] >= '0' && email <= '9') ++quantidade_numeros_dominio;

			//Nessa parte, verifica-se se o dominio é composto somente por números
			if (quantidade_numeros_dominio == email.length() - inicio_dominio) throw invalid_argument("Argumento invalido. Dominio não pode possuir somente números");
		}
	}
	if(email[0] == '.' || email[fim_local] == '.') throw invalid_argument("Argumento invalido. Primeiro e ultimo caractere da parte local não pode ser '.'");
	if(email[inicio_dominio] == '-' || email[email.length() - 1] == '-') throw invalid_argument("Argumento invalido. Primeiro e ultimo caractere do domínio não pode ser '-'");
}

void Email::setEmail(string email) throw (invalid_argument){
	validar(email);
	this->email = email
}

void Email::callEmail(Email objeto){
	//FAZER ESSE CÓDIGO
}

void Senha::validar(string senha, Nome usuário) throw (invalid_argument){
	
}

void Senha::setSenha() throw (invalid_argument){
	validar();
}

void Senha::callSenha(Senha objeto){
	//FAZER ESSE CÓDIGO
}

void XX::validar() throw (invalid_argument){

}

void XX::setXX() throw (invalid_argument){
	validar();
}

void XX::callXX(XX objeto){
	//FAZER ESSE CÓDIGO
}

void XX::validar() throw (invalid_argument){

}

void XX::setXX() throw (invalid_argument){
	validar();
}

void XX::callXX(XX objeto){
	//FAZER ESSE CÓDIGO
}