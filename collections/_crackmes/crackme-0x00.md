---
title: Crackme 0x00
---

Fala galera blza?, primeiramente .. Obrigado por compartilhar esse Crackme e fico muito feliz em poder analisar-lo.
Abaixo coloquei algumas informações que levantei durante a análise deste binário, e por fim vou mostrar como resolver o Crackme.

Informações Complementares
--------------------------
ID at crackmes.one : 60b92a0433c5d410b8842bd3

- Tipo de arquivo : PE EXE
- Compilador/Linguagem : MinGW(GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 pr)[C/C++]
- Protection/Packer : Nothing
- MD5 : BBA071C4D3C7FEF92170F1351609A558
- SHA256 : 22159F1BB8E727C69930BEABBE06094B9B9EC7A6A6E216D3B1C3754287251589
- Strings Interessantes : Nothing


---


Dicas para resolver/path
-------------------------

1. Função Principal pra analisar : CALL (em 0x401386 ) e Prólogo da mesma ( em 0x4015C0 )

2. Breakpoints matadores : Temos um JNE ( em 0x40163F ) , nesse ponto do programa é possível alterar o fluxo para fazer um path e resolver sem
descobrir a key.


---


Resolvendo o Crackme
=====================

Vamos direto para o endereço do início da rotina principal (em 0x4015C0 ) para começarmos a resolver o Crackme. Os trechos de código que vemos no
debugger a partir do endereço que seguimos, já nos mostra algumas CALLS que são feitas no console .. até que o programa solicite a 'Key'.

Após a função 'scanf' ler os bytes que digitamos no console, são movidos 2 valores para a Stack ( em 0x401612 e 0x40161A ) que posteriormente são
usados na função 'strcmp' para comparar com os dados digitados pelo usuário. Conforme trecho de código abaixo, copiado do debugger :

```
00401612 | C74424 1C 30372F31       | mov dword ptr ss:[esp+1C],312F3730 |
0040161A | C74424 20 302F3937       | mov dword ptr ss:[esp+20],37392F30 |
```

Se montarmos uma string com esses valores movidos para a Stack, temos a seguinte string : '30372F31302F3937'. Adivinha o que acontece se convertermos a string '30372F31302F3937' ? Voilà, we found the *Key ='07/10/97'*

- usei o python para fazer a conversão da string :



```python
>>> string = '30372F31302F3937'
>>> string.decode("hex")
'07/10/97'
>>>
```

- resolvendo o crackme com a key encontrada :


```
Hello My Name is Saptam

To Open this Program You have to Enter My Date of Birth

Enter DoB (00/00/00) : 07/10/97

Access Granted

Wellcome

Pressione qualquer tecla para continuar. . 
```


