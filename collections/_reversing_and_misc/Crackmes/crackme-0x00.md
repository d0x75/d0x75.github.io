---
title: Crackme 0x00
---

Fala galera blza?, primeiramente .. Obrigado por compartilhar esse Crackme e fico muito feliz em poder analisar-lo.
Abaixo coloquei algumas informações que levantei durante a análise deste binário, e por fim vou mostrar como resolver o Crackme.

#### Informações Complementares

```ID at crackmes.one : 60b92a0433c5d410b8842bd3```

- Tipo de arquivo : PE EXE
- MD5 : BBA071C4D3C7FEF92170F1351609A558
- SHA256:22159F1BB8E727C69930BEABBE06094B9B9EC7A6A6E216D3B1C3754287251589
- Compilador/Linguagem : MinGW(GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 pr)[C/C++]
- Protection/Packer : Nada
- Strings Interessantes : Nada


---

#### Dicas para encontrar a solução

>> Calls importantes :

- Função Principal pra analisar : Uma CALL no address ```0x401386``` e o Prólogo da mesma no address  ```0x4015C0```.


> Breakpoints at Adress :

- ```0x40163F``` Temos um JNE nesse adress, e é nesse ponto do
programa é possível alterar o fluxo para fazer um path e resolver
sem descobrir a key.


---


### Resolvendo o Crackme


Vamos seguir o adress ```0x4015C0```, que é aonde começa a rotina principal do programa, para começarmos a resolver o Crackme.
Os trechos de código que vemos no debugger a partir do endereço que seguimos, já nos mostra algumas *CALLS* que são feitas no console .. até que o programa solicite a _Key_.

Após a função 'scanf' ler os bytes que digitamos no console, são movidos 2 valores para a Stack nos adress ``0x401612`` e ``0x40161A`` e que posteriormente são usados na função 'strcmp' para comparar com os dados digitados pelo usuário.

> Conforme trecho de código abaixo, copiado do debugger :

```assembly
00401612 | C74424 1C 30372F31       | mov dword ptr ss:[esp+1C],312F3730 |
0040161A | C74424 20 302F3937       | mov dword ptr ss:[esp+20],37392F30 |
```

Se montarmos uma string com esses valores movidos para a Stack, temos a seguinte string : ```**30372F31302F3937**```

> Adivinha o que acontece se convertermos a string acima para ASCII ??

_Voilà, we found the **Key ='07/10/97'**_

- usei o python para fazer a conversão da string :

```python
>>> string = '30372F31302F3937'
>>> string.decode("hex")
'07/10/97'
>>>
```

- resolvendo o crackme com a Key encontrada :


```DOS
Hello My Name is Saptam

To Open this Program You have to Enter My Date of Birth

Enter DoB (00/00/00) : 07/10/97

Access Granted

Wellcome

Pressione qualquer tecla para continuar. . 
```


