#include "Comandos.h"
#include "Camada de Serviço/Banco de Dados/ConexaoBD.h"

void ComandoIAContaCriar::executar() {
    string inputUsuario;

    cout << "--- Criacao de Conta ---" << endl;
    cout << "Digite o CPF: ";
    cin >> cpfValue;
    cout << "Digite seu Nome: ";
    cin >> nomeValue;
    cout << "Digite sua senha: ";
    cin >> senhaValue;
    try {
        cpf.setValor(cpfValue);
        nome.setValor(nomeValue);
        senha.setValor(senhaValue);

        conta.setCpf(cpf);
        conta.setNome(nome);
        conta.setSenha(senha);

        CntrlSConta cntrlSConta;

        if (cntrlSConta.criar(conta)) {
            cout << "Sucesso na criacao da Conta." << endl;
        } else {
            cout << "Falha na criacao da conta." << endl;
        };
    } catch (const invalid_argument& e) {
        cout << "Erro na criacao da conta: " << e.what() << endl;

    } catch (const EErroPersistencia& e) {
        cout << "Erro de persistência: " << e.what() << endl;
    };
};

void ComandoIAContaAtualizar::executar() {
    cout << "--- Atualizacao de Conta ---" << endl;
    cout << "Digite o CPF: ";
    cin >> cpfValue;
    cout << "Digite o Nome que deseja Atualizar: ";
    cin >> nomeValue;
    cout << "Digite a senha que deseja Atualizar: ";
    cin >> senhaValue;

    try {
        cpf.setValor(cpfValue);
        nome.setValor(nomeValue);
        senha.setValor(senhaValue);

        conta.setCpf(cpf);
        conta.setNome(nome);
        conta.setSenha(senha);

        CntrlSConta cntrlSConta;

        if (cntrlSConta.atualizar(conta)) {
            cout << "Sucesso na atualizacao da Conta." << endl;
        } else {
            cout << "Falha na atualizacao da conta." << endl;
        }
    } catch (const invalid_argument& e) {
        cout << "Erro na atualizacao da conta: " << e.what() << endl;

    } catch (const EErroPersistencia& e) {
        cout << "Erro de persistência: " << e.what() << endl;
    };

};

void ComandoIAContaExcluir::executar() {
    cout << "--- Excluir Conta ---" << endl;
    cout << "Digite o CPF: ";
    cin >> cpfValue;
    cout << "Digite o Nome: ";
    cin >> nomeValue;
    cout << "Digite a senha: ";
    cin >> senhaValue;

    try {
        cpf.setValor(cpfValue);
        nome.setValor(nomeValue);
        senha.setValor(senhaValue);

        CntrlSConta cntrlSConta;

        if (cntrlSConta.excluir(cpf)) {
            cout << "Sucesso na atualizacao da Conta." << endl;
        } else {
            cout << "Falha na exclusão da conta." << endl;
        };

    } catch (const invalid_argument& e) {
        cout << "Erro na atualizacao da conta: " << e.what() << endl;
    } catch (const EErroPersistencia& e) {
        cout << "Erro de persistência: " << e.what() << endl;
    };
};

void ComandoIAContaListar::executar() {
    cout << "Digite o CPF: teste";
    cin >> cpfValue;

    try {
        cpf.setValor(cpfValue);
        conta->setCpf(cpf);
        CntrlSConta cntrlSConta;

        cout << "entra aqui?" << endl;

        if (cntrlSConta.recuperar(conta)) {
            cout << "--- Detalhes da Conta ---" << endl;
        } else {
            cout << "Falha na recuperação da conta." << endl;
        }
    } catch (const EErroPersistencia& e) {
        cout << "Erro ao listar contas: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Erro inesperado: " << e.what() << endl;
    }
}
