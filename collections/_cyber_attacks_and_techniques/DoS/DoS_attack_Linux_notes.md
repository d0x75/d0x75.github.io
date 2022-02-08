---
title: DoS Attack - Muito simpes testado no Linux.
category: post
---


# Simple DoS Attack

DoS é um ataque de negação de serviço que é feito para prejudicar o pilar da Disponibilidade dos dados.

Nesse caso se trata de um DoS bem simplório, que irá apenas ficar fazendo conexões repetidamente.. afim de sobrecarregar o Host e consequentemente derrubar-lo.


---


### Step 1

- Configurar uma VM Linux , de preferência com uma VPN para esconder o IP do atacante.

- Ter instalado ao menos o GCC na VM, para compilar o código que vai efetuar o DoS.


### Step 2


- Obter o código ``DoS-linux.c`` no dispositivo atacante.

- Compilar o código mencionado acima, usando o GCC de forma convencional :
		
		gcc DoS-linux.c -o DoSS


### Step 3


- Ligar a VPN ou outro mecanismo que esconda o IP do dispositivo atacante.
	
- Executar o programa compilado no Step 2, passando o IP e a Porta do Alvo para que as o programa faça as REQUESTS.

Exemplos :

*Direcionando o DoS para um servidor HTTP* :

		./DoS 65.75.137.94 80

*Direcionando o DoS para um servidor FTP* :

		./DoS 65.75.137.94 21

*Direcionando o DoS para um servidor Telnet* :

		./DoS 65.75.137.94 23