#include "ControladorasServico.h"
#include "Banco de Dados/ConexaoBD.h"

// Implementação do método criar na classe CntrlSConta.
bool CntrlSConta::criar(Conta conta) {
    try {
        ComandoCriarConta comandoCriarConta(conta);
        comandoCriarConta.executar();
        return true;
    } catch (const invalid_argument& e) {
        cout << "Erro na criacao da conta: " << e.what() << endl;
        return false;
    } catch (const EErroPersistencia& e) {
        cout << "Erro de persistência: " << e.what() << endl;
        return false;
    };
};

// Implementação dos outros métodos para evitar o erro de classe abstrata
bool CntrlSConta::recuperar(Conta* conta) {
    try {
        ComandoListarConta comandoListarConta(*conta);
        comandoListarConta.executar();

        // Atualizar os dados da conta a partir do comando
        string valor = comandoListarConta.getResultado();
        if (!valor.empty()) {
            conta->getCpf().setValor(valor);  // Atualizar outros campos conforme necessário
            return true;
        }
        return false;
    } catch (const std::invalid_argument& e) {
        std::cout << "Erro na recuperação da conta: " << e.what() << std::endl;
        return false;
    } catch (const EErroPersistencia& e) {
        std::cout << "Erro de persistência: " << e.what() << std::endl;
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
        cout << "Erro de persistência: " << e.what() << endl;
        return false;
    };
};

bool CntrlSConta::excluir(Conta conta) {
    try {
        ComandoExcluirConta ComandoExcluirConta(conta);
        ComandoExcluirConta.executar();
        return true;
    } catch (const invalid_argument& e) {
        cout << "Erro na atualizacao da conta: " << e.what() << endl;
        return false;
    } catch (const EErroPersistencia& e) {
        cout << "Erro de persistência: " << e.what() << endl;
        return false;
    };
};
