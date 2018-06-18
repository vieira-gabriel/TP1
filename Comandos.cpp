
#include "Comandos.hpp"

//--------------------------------------------------------------------------- 
// Classe CmdSULeitor.

CmdSULeitor::CmdSULeitor(Nome a, Nome b, Email e, Senha d){
	nome = a;
	sobrenome = b;
	email = e;
	senha = d;
}

void CmdSULeitor::execute() throw (invalid_argument){
	Leitor leitor;

	for(itLer = userLer.begin(); itLer != userLer.end(); itLer++){
		if(itLer->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itDev = userDev.begin(); itDev != userDev.end(); itDev++){
		if(itDev->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itAdm = userAdm.begin(); itAdm != userAdm.end(); itAdm++){
		if(itAdm->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	
	leitor.setNome(nome);
	leitor.setSobrenome(sobrenome);
	leitor.setEmail(email);
	leitor.setSenha(senha);

	userLer.insert(userLer.end(), leitor);
}

//--------------------------------------------------------------------------- 
// Classe CmdSUDev.

CmdSUDev::CmdSUDev(Nome a, Nome b, Email e, Senha d, Data f){
	nome = a;
	sobrenome = b;
	email = e;
	senha = d;
	nascimento = f;
}

void CmdSUDev::execute() throw (invalid_argument){
	Desenvolvedor dev;

	for(itLer = userLer.begin(); itLer != userLer.end(); itLer++){
		if(itLer->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itDev = userDev.begin(); itDev != userDev.end(); itDev++){
		if(itDev->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itAdm = userAdm.begin(); itAdm != userAdm.end(); itAdm++){
		if(itAdm->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}

	dev.setNome(nome);
	dev.setSobrenome(sobrenome);
	dev.setEmail(email);
	dev.setSenha(senha);
	dev.setData(nascimento);

	userDev.insert(userDev.end(), dev);
}

//--------------------------------------------------------------------------- 
// Classe CmdSUAdmin.

CmdSUAdmin::CmdSUAdmin(Nome a, Nome b, Email e, Senha d, Data f, Telefone g, Endereco h){
	nome = a;
	sobrenome = b;
	email = e;
	senha = d;
	nascimento = f;
	telefone = g;
	endereco = h;
}

void CmdSUAdmin::execute() throw (invalid_argument){
	Administrador admin;

	for(itLer = userLer.begin(); itLer != userLer.end(); itLer++){
		if(itLer->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itDev = userDev.begin(); itDev != userDev.end(); itDev++){
		if(itDev->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}
	for(itAdm = userAdm.begin(); itAdm != userAdm.end(); itAdm++){
		if(itAdm->getEmail().getEmail() == email.getEmail()){
			throw invalid_argument("***Usuario com este email ja existe.");
		}
	}

	admin.setNome(nome);
	admin.setSobrenome(sobrenome);
	admin.setEmail(email);
	admin.setSenha(senha);
	admin.setData(nascimento);
	admin.setTelefone(telefone);
	admin.setEndereco(endereco);

	userAdm.insert(userAdm.end(), admin);
}

//--------------------------------------------------------------------------- 
// Classe CmdLogin.

CmdLogin::CmdLogin(Email a, Senha b){
	email = a;
	senha = b;
}

void CmdLogin::execute() throw (invalid_argument){
	for(itLer = userLer.begin(); itLer != userLer.end(); itLer++){
		if(itLer->getEmail().getEmail() == email.getEmail()){
			if (itLer->getSenha().getSenha() == senha.getSenha()){
				result = LG_LEITOR;
				return;
			} else {
				result = LG_ERROR;
				throw invalid_argument("***Senha Errada!");
			}
		}
	}

	for(itDev = userDev.begin(); itDev != userDev.end(); itDev++){
		if(itDev->getEmail().getEmail() == email.getEmail()){
			if (itDev->getSenha().getSenha() == senha.getSenha()){
				result = LG_DEV;
				return;
			} else {
				result = LG_ERROR;
				throw invalid_argument("***Senha Errada!");
			}
		}
	}

	for(itAdm = userAdm.begin(); itAdm != userAdm.end(); itAdm++){
		if(itAdm->getEmail().getEmail() == email.getEmail()){
			if (itAdm->getSenha().getSenha() == senha.getSenha()){
				result = LG_ADMIN;
				return;
			} else {
				result = LG_ERROR;
				throw invalid_argument("***Senha Errada!");
			}
		}
	}

	result = LG_ERROR;
	throw invalid_argument("***Usuario inexistente.");
}
