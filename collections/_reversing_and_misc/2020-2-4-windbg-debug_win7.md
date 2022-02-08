---
title: Windbg - Debugging Windows 7 Kernel Mode
category: post
date: 2020-2-4
---


Setup VM-1 ( Debugger )
-------------------------

- Iniciar o Windows 7
- Instalar o SDK que vem com o Windbg
- Instalar Symbols
- Setar variável de ambiente para download dos Symbols, da seguinte forma:

0. Criar diretório Symbols em 'C:\'.

1. Meu Computador > Propriedades > Configurações avançadas do sistema
  
2. Variaveis de Ambiente > Novo

3. Criar nova variavel de ambiente, com o seguinte nome : '_NT_SYMBOL_'PATH'(tudo junto)

4. Setar o seguinte valor para a variavel de ambiente criada :

        SRV*C:\Symbols*https://msdl.microsoft.com/download/symbols

- Após terminar o setup e desligar a máquina
- Ir até os menu do virtual box, clicar em 'Configurações' 
- Clicar na opção Portas Seriais > Porta 1 e fazer o seguinte setup:


        Flag : [X] Habilitar porta serial

        Número da porta : COM1

        IRQ = 4

        Endereço de I/O = 0x3F8

        Modo da Porta : Pipe no Hospedeiro

        Flag : [] Conectar a pipe/socket existente

        Caminho/Endereço : \\.\pipe\wke_pipe


Setup VM-2 ( Debugged )
------------------------- 

- Iniciar o Windows 7
- Fazer o setup do 'bcdedit', para habilitar a opção de debugger; para conseguirmos debuggar o SO.
- Via cmd fazemos o seguinte:

        bcdedit /copy {current} /d "Debug me"
        bcdedit /debug {Flag retornada no comando anterior} on
        bcdedit /dbgsettings
  
- Copiar os dados que o último comando retornou, pois são eles que iremos usar no Windbg para comunicar com a VM debugada.

- Após terminar o setup e desligar a máquina
- Ir até os menu do virtual box, clicar em 'Configurações' 
- Clicar na opção Portas Seriais > Porta 1 e fazer o seguinte setup: 

        Flag : [X] Habilitar porta serial
        Número da porta : COM1
        IRQ = 4
        Endereço de I/O = 0x3F8
        Modo da Porta : Pipe no Hospedeiro
        Flag : [X] Conectar a pipe/socket existente
        Caminho/Endereço : \\.\pipe\wke_pipe



Iniciando o debugger do SO
---------------------------

Após todos os setups acima ter sido realizados nas VMs, faremos o seguinte:

- Ligar o Debugger (VM-1)
- Abrir Windbg > File > Kernel Debug > aba COM
- Setar os dados coletados no último comando 'bcdedit'. Ex:
  
        Baud Rate : 115200
        Port : com1
        []Pipe
        []Reconnect
        Resets : 0

- Ligar a máquina que será debuggada (VM-2)
- Na hora do boot, selecionamos a opção : Debug-me [depurador habilitado]