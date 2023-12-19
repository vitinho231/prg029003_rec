# Avaliação de recuperação PRG029003

## Cenário

Um programador iniciou o desenvolvimento de uma aplicação para verificar quais contribuintes já haviam entregue suas declarações de Imposto de Renda. Esta aplicação instancia em memória os CPFs, nomes e emails dos contribuintes que realizaram a entrega. Portanto, CPFs que não estiverem nesta lista, ainda não realizaram a entrega da declaração.

Essa funcionalidade deve ser lançada em breve e há uma expectativa de haver alto fluxo de requisições em certo período do ano. Como meta, foi solicitado que a aplicação responda se encontrou um CPF entre 100 mil cadastros em até 0.00001s (10 microssegundos) em média.

Para atender esse requisito de tempo, o programador está apostando na implementação de uma tabela de dispersão. Ele iniciou o projeto, criou até um arquivo de testes que gera uma lista de CPFs aleatórios.

## Problema

O programador acabou não concluindo o projeto. Sabe-se que há problemas na implementação, a compilação não está funcionando, a performance não está atendendo os requisitos e após tudo estar corrigido é fundamental que se verifique se não há problemas de vazamento de memória que poderiam ser catastróficos nesta aplicação. Também faltou ser desenvolvida uma interface de cadastro e busca de CPFs.

## Detalhes de implementação

O projeto prevê que no arquivo CMakeLists hajam três compilações:
- Lib_HashTable: compilação que contém a implementação da hash e recursos de análise de desempenho do projeto
- Exec_HashTable: compilação que inclui o arquivo main.c para que seja o ponto de entrada da aplicação, devendo conter um menu que permite adicionar um cpf, nome e email, uma opção para buscar um cpf existente e a opção sair. 
- Test_HashTable: compilação que inclui o arquivo test_hash_pessoa onde testes funcionais e de performance devem ser implementados

## Missão

1. Corrigir as falhas da biblioteca tornando-a funcional (para instanciação e busca de estruturas tipo pessoa_t através do campo CPF
2. Realizar testes de performance com tomadas que mostram que o requisito de performance foi atendido para uma lista instanciada de 100 mil registros e implementar o menu conforme descrito.
3. Implementar o menu no arquivo main.c, disponibilizando uma interface de cadastro e busca de estruturas tipo pessoa_t.

Obs.: O projeto não deve ter falhas de vazamento de memória, para isso você pode utilizar o comando valgrind. Apenas a título de exemplo, o comando pode ser executado da seguinte forma: 

'''
valgrind --leak-check=yes ./cmake-build-debug/Exec_hasTable
'''