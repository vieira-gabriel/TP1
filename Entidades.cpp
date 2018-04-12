#include "Entidades.hpp"

void Leitor::validarSenha(Senha senha, Nome nome) throw (invalid_argument){
	string senha_usuario = senha.getSenha();
	string nome_usario = nome.getNome();
// Verifica se nome do usuário está contido na senha. Sem muita persistência.
	if (strstr(senha_usuario.c_str(), nome_usario.c_str()) != NULL) {
		throw invalid_argument("Senha inválida. Senha não pode conter o nome do usuário.");
	}
	nome_usario.at(0) = nome_usario.at(0) + 32;	// Transforma primeira letra em mińúscula e compara novamente.
	if (strstr(senha_usuario.c_str(), nome_usario.c_str()) != NULL) {
		throw invalid_argument("Senha inválida. Senha não pode conter o nome do usuário.");
	}
}

void Leitor::setSenha(const Senha &senha, const Nome &nome) throw (invalid_argument){
	validarSenha(senha, nome);
	this->senha = senha;
}