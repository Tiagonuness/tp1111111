#include "ControladorasServico.h"
#include "Banco de Dados/ConexaoBD.h"

// Implementa��o do m�todo criar na classe CntrlSConta.
bool CntrlSConta::criar(Conta conta) {
    try {
        ComandoCriarConta comandoCriarConta(conta);
        comandoCriarConta.executar();
        return true;
    } catch (const invalid_argument& e) {
        cout << "Erro na criacao da conta: " << e.what() << endl;
        return false;
    } catch (const EErroPersistencia& e) {
        cout << "Erro de persist�ncia: " << e.what() << endl;
        return false;
    };
};

// Implementa��o dos outros m�todos para evitar o erro de classe abstrata
bool CntrlSConta::recuperar(Conta* conta) {
    try {
        ComandoListarConta comandoListarConta(conta);
        comandoListarConta.executar();
        return true;
    } catch (const std::invalid_argument& e) {
        std::cout << "Erro na recupera��o da conta: " << e.what() << std::endl;
        return false;
    } catch (const EErroPersistencia& e) {
        std::cout << "Erro de persist�ncia: " << e.what() << std::endl;
        return false;
    }
}

bool CntrlSConta::atualizar(Conta conta) {
    try {
        ComandoAtualizarConta comandoAtualizarConta(conta);
        comandoAtualizarConta.executar();
        return true;
    } catch (const invalid_argument& e) {
        cout << "Erro na atualizacao da conta: " << e.what() << endl;
        return false;
    } catch (const EErroPersistencia& e) {
        cout << "Erro de persist�ncia: " << e.what() << endl;
        return false;
    };
};

bool CntrlSConta::excluir(Cpf cpf) {
    // Implementa��o do m�todo excluir (a ser desenvolvida)
    return false;
};
