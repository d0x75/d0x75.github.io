---
title: Windbg - Debugging Windows XP Kernel Mode
category: post
date: 2020-2-4
---


>Passo a passo de como realizar o debugger do SO Windows XP.


#### Preparando a VM para ser debuggada.


- Restaurar o snapshot limpo e desligar a máquina virtual.
- No virtual box, clicar na opção "Configurações" > "Portas Seriais"
- aba Porta 1 > marcar a flag []Habilitar Porta Serial > Preencher os campos da seguinte forma:

```C++		
Número da Porta = COM1
Modo da Porta = Pipe no Hospedeiro
flag [ ] = MARCADA
Caminho/Endereco(P): = \\.\pipe\com_1
IRQ = 4
Endereço I/O = 0x3F8
```

- Iniciar normalmente a máquina virtual.
- Procurar e editar o arquivo C:\boot.ini
- Incluir os seguintes dados última linha da chave [operating systems], ficaria assim:


```text
multi(0)disk(0)rdisk(0)partition(1)\WINDOWS="Debugando o XP" /noexecute=optin /fastdetect /debug /debugport=COM1 baudrate=115200
```

### Setup no Windbg para debuggar a VM


1. Configurar os symbols:


- Clicar em File > Symbol File Path > SRV*C:\Symbols*https://msdl.microsoft.com/download/symbols > OK
 
2. Iniciar a depuração

- Clicar em File > Kernel Debug  ou CTRL + K
- Na aba COM, os dados ficaram preenchidos da seguinte forma:

		Baud Rate = 115200
		Port = \\.\pipe\COM_1
		Pipe = [] MARCADA
		Reconnect = [] DESMARCADA
		Resets = 0



_voilà_ !