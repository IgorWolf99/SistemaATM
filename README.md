# Sistema Bancário em C++

## Introdução  

O principal objetivo desse projeto é explorar e aplicar recursos da linguagem **C++** no desenvolvimento de um sistema bancário simples, destacando escolhas de **modularização**, **organização** e **boas práticas** de programação.  

Além de implementar funcionalidades básicas como depósitos, saques, verificação de saldo e transferências, este projeto foi essencial para compreender de forma mais profunda o funcionamento da linguagem C++, desde conceitos de **orientação a objetos** até detalhes de **compilação e execução** em diferentes ambientes.  

O sistema funciona atualmente no terminal, mas no futuro poderá ser expandido para um sistema desktop completo utilizando **Windows Forms** ou outras tecnologias.  

---

## Funcionalidades Implementadas  

- **Autenticação de Usuário**: validação com número de conta e hash da senha.  
- **Menu Interativo**: interface em console (`ConsoleInterface`).  
- **Operações Bancárias**: depósito, saque, transferência e consulta de saldo.  
- **Validações**: verificação de login e checagem de saldo antes de operações.  
- **Tratamento de Erros**: mensagens claras e exceções na leitura de arquivos.  

---

## Uso de Classes e Modularidade  

- **ConsoleInterface**: exibe menus e mensagens para o usuário.  
- **Account**: gerencia saldo e movimentações.  
- **Login**: garante acesso seguro aplicando hash nas senhas.  
- **User**: armazena dados pessoais e estado de login do usuário.  
- **Utils**: centraliza funções de entrada de dados e formatação de valores.  

---

## Uso de Referências  

Durante o desenvolvimento, aprendi a importância de trabalhar com **referências** em C++ (`User &user`) para evitar cópias desnecessárias e manter consistência no estado do sistema.  

O uso de referências mostrou como manter sincronizado o estado de login entre diferentes classes, garantindo integridade dos dados em operações bancárias.  

Esse recurso reforçou a compreensão sobre como o C++ trabalha internamente e como o desenvolvedor pode controlar a consistência do sistema.  

---

## Boas Práticas de Design  

O sistema foi pensado de forma **modular** e **expansível**.  
Cada classe possui uma **responsabilidade única**, o que facilita manutenção, testes e evolução futura do projeto.  

Esse projeto também foi importante para exercitar práticas como:  

- **Organização de código em headers (.h) e implementações (.cpp)**.  
- **Encapsulamento adequado** de atributos e métodos.  
- **Separação de responsabilidades**, deixando claro onde ficam regras de negócio, interface e persistência.  

Esses aprendizados não só ajudaram no desenvolvimento desse sistema, mas também contribuíram para um entendimento mais sólido sobre como estruturar projetos maiores em C++.  

---

## Herança e Polimorfismo  

### Herança  

O conceito de herança foi aplicado através da classe base **Account**, da qual derivam as classes:  

- **Savings** (Conta Poupança)  
- **Checking** (Conta Corrente)  

A herança permite que ambas compartilhem métodos comuns, como:  

- `deposit()`  
- `withdraw()`  
- `transferBalance()`  
- `currentBalance()`  

Isso reduz redundâncias e centraliza regras básicas em uma única classe.  

### Polimorfismo  

O polimorfismo foi aplicado para que as classes filhas pudessem alterar o comportamento de métodos herdados conforme a necessidade.  

- Na classe **Savings**, o método `withdraw()` foi sobrescrito para incluir a cobrança de taxa sobre o saque (`feePercentage`):  

```cpp
bool Savings::withdraw(double amount) {
    if (!getUser().getIsLogged()) {
        ci.ErrorMessage("Usuário não está logado!");
        return false;
    }

    double value = amount + (amount * feePercentage);

    if (value > getBalance()) {
        ci.ErrorMessage("Fundos Insuficientes!");
        return false;
    }

    setBalance(getBalance() - value);
    ci.SuccessMessage("Saque de " + formatCurrency(value) + " realizado (incluindo taxa)!");
    return true;
}
```

### Já a classe Checking  

Já a classe **Checking** redefine `currentBalance()` para exibir o tipo da conta de forma personalizada.  

Essa abordagem permite tratar objetos de forma genérica (como `Account`), mas obter comportamentos diferentes conforme o tipo de conta.  

---

## Segurança – Hash SHA-256  

Para autenticação segura, utilizei **SHA-256** para aplicar hash nas senhas.  
Optei por uma implementação pronta do algoritmo, já que o foco do projeto era explorar conceitos de **POO** e **modularização**.  

- As senhas **não ficam em texto puro**: apenas os hashes são armazenados e comparados no login.  
- Atualmente, o armazenamento é feito em um arquivo texto por simplicidade.  
- No futuro, a ideia é integrar o sistema a um **banco de dados** para maior segurança e escalabilidade.  

---

## Controle de Acesso  

Para garantir que apenas usuários autenticados possam acessar operações da conta, o sistema mantém um **estado de login**.  

Antes de executar qualquer operação sensível (como saque, depósito ou transferência), é verificado se o usuário está autenticado.  

Exemplo no `Login`:  

```cpp
bool Login::authenticate(int numberAccount, int pinAccount) {
    ...
    string hashPin = SimpleSHA256::sha256(to_string(pinAccount)); // Criar Hash da senha

    if (numberAccount == acc && hashPin == pin) {
        user.setIsLogged(true);
        cout << "Login realizado!" << endl;
        return true;
    }
    return false;
}
```

---

## Funções Utilitárias  

O sistema possui funções auxiliares para entrada e formatação de dados, como:  

- **inputInt** e **inputDouble**: tratam a entrada do usuário, com validação contra valores inválidos.  
- **formatCurrency**: padroniza a exibição de valores monetários no formato brasileiro.  

Essas funções evitam duplicação de código e garantem consistência nas operações.  

---

## Uso de Arquivos Header (.h)  

As classes e métodos foram declarados em **arquivos .h** (headers) e implementados em arquivos `.cpp`.  

### Vantagens  

- **Organização**: facilita localizar e entender cada parte do sistema.  
- **Reutilização**: headers podem ser incluídos em diferentes módulos sem duplicação de código.  
- **Manutenção**: mudanças na implementação não exigem alterações na interface.  
- **Escalabilidade**: facilita adicionar novas classes e métodos sem comprometer a estrutura existente.  

---

## Melhorias Futuras  

- Substituir o arquivo `.txt` por um banco de dados seguro.  
- Implementar **logs de transações** para auditoria.  
- Criar **interface gráfica (GUI)** para maior usabilidade.  
- Implementar **testes unitários** para validar regras de negócio.  

---

## Conclusão  

Esse projeto foi muito importante para **aprofundar meus conhecimentos em C++**, não apenas em conceitos de **orientação a objetos**, mas também em detalhes sobre **compilação, modularização e boas práticas de desenvolvimento**.
  
Com ele, pude praticar desde a estruturação de classes e uso de referências até a organização do código em headers e a aplicação de técnicas de segurança como **hash de senhas**.

Esse aprendizado contribuiu para uma compreensão mais clara de como a linguagem funciona "por baixo dos panos" e por que ela continua sendo tão utilizada em sistemas de alto desempenho.  

---


## Imagens do sistema  

<img width="455" height="630" alt="image" src="https://github.com/user-attachments/assets/8eca993a-6143-49d1-8c1a-5db55c5fab53" />

<img width="431" height="724" alt="image" src="https://github.com/user-attachments/assets/e01950f5-b42b-43f3-8b21-8626da1a5e7e" />


