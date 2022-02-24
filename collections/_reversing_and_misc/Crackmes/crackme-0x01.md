---
title: Crackme 0x01
---

Fala galera blza?, primeiramente .. Obrigado por compartilhar esse Crackme e fico muito feliz em poder analisar-lo.
Abaixo coloquei algumas informações que levantei durante a análise deste binário, e por fim vou mostrar como resolver o Crackme.

#### Informações Complementares

```ID at crackmes.one : 6004daf233c5d42c3d016717```

- Tipo de arquivo : PE EXE
- MD5 : 258C36834824BCAD568572F703A1DBB4
- SHA56 : 7FA4CD1C6451F9FD94A65CED9939B75315E57A90D3E01BEDAEB7F11DBF40E39D
- Compilador/Linguagem : MinGW(gcc-3.4.5)[C lang]
- Protection/Packer : Nada
- Strings interessantes : Nada


---


#### Dicas para encontrar a solução

> Breakpoints at Adress :

- ```0x00401347``` = Endereço do CMP que é capaz de alterar o fluxo do programa, para fazer um Path por exemplo.

- ```0x004012D0``` = Inicio rotina principal que escreve no console, e que faz um IF para comparar o que digitamos com a string verdadeira.

> Calls importantes :


- ```0x004010B1``` = Endereço da CALL que entra na rotina pricipal.



---


### Resolvendo o Crackme


Na rotina principal no adress ```0x4012D0``` antes do programa chamar o último 'printf' em ```0x40132C```, vemos o valor  **```0x1232B14```** sendo movido para a Stack. 
Conforme trecho de código abaixo que vemos no debugger :

```assembly
0040131E | C745 FC 142B2301| mov dword ptr ss:[ebp-4],1232B14
```


Depois da 'scanf' que é função que lê os bytes que digitamos
no console, temos um if no adress ```0x401347``` que compara
os bytes digitados no console com o valor que movemos logo acima /\ para a Stack logo acima e depois salta para o último
'printf'. Conforme o código abaixo, copiado do debugger :


```assembly
00401347 | 3B45 FC                  | cmp eax,dword ptr ss:[ebp-4] |
0040134A | 75 0E                    | jne crackme.40135A           |
```

A partir daqui, nós conseguimos alterar o fluxo do programa naquele if do adress ```0x401347``` e já entendemos que a 'Chave' pra resolver o Crackme, é esse valor que foi movido para Stack ( *```0x1232B14```* ). Então vamos coverter esse
valor para Decimal e tentar resolver o Crackme :

- usei o python para fazer a conversão de hexa para decimal :

```python
>>> print 0x1232B14
19082004
>>>
```

- resolvendo o crackme com a key encontrada:

```DOS
********************************************
*            Crackme by @Danofred0         *
********************************************

Veuillez entrer le mot de passe pour acceder au contenu:   

19082004

True !!
Pressione qualquer tecla para continuar. . .
```


_Voilà_! Flw galera, espero que tenha ficado de boas para entender!

Qualquer dúvida só chamar =)
