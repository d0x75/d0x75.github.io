---
title: Windows- Criar Sessão de Código em Binários PE.
category: post
---

>Para facilitar a criação da Sessão de Código usaremos :
*DIE ( Direct it easy versão 2.05 )*
>link para download :
https://github.com/d0x75/maleta/raw/main/die_win32_portable_2.05.zip


---


#### Procedimento de criação de uma nova sessão de código executável em binários PE, usando DIE.


- Abrir o DIE e carregar o binário PE alvo.

- Ir até as sessões do binário

- Desmarcar a flag na tela principal das sessões  _[] Read only_
Feito isso vai habilitar abaixo os botões : 

		"Add new section" e "Delete last section".

- Clicar no botão *Add new section*, pra criar a nova sessão.

- Selecionar o arquivo com os bytes que usaremos na sessão. 
(um shellcode por exemplo)

PS : Podemos também colocar um arquivo em branco, apenas para criar a sessão.. e depois sim podemos colocar os bytes ref. aos código na sessão criada.

- Assim que a sessão nova aparecer na tela principal, onde ficam as outras
sessões, já saberemos que deu certo criar a sessão.

- Agora para nomear essa sessão, clicamos com o botão direito na sessão criada e fazemos o seguinte :

		Edit header > Desmarcar "[] Read only" > Name: Dar um nome para a sessão.

- Agora para atribuir as permissões/flags padrões de uma sessão de código, clicamos com o botão direito na sessão criada e fazemos o seguinte : 

		Edit header > Entrar em "..." DLLCharacteristics > Desmarcar "[] Read only"

- E marcar as seguintes flags :

```c++
[X] CNT_CODE 
[X] MEM_EXECUTE
[X] MEX_READ
```

> Feito isso temos o campo da Characteristics da sessão a seguinte 
Flag :  **60000020** 
( então sabemos que quando a sessão tiver a flag **60000020** no campo Characteristics, é provavel que seja uma
sessão de código executável ).

---

_Voilá! Sessão criada =). Agora é só assemblar do zero nela ou assemblar ajustando os bytes do shellcode importado para sessão_.