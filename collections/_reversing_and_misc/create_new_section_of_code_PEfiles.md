---
title: Reversing 0x00
category: post
---

### Procedimento de criação de uma nova sessão de código executável em binários PE.

Criando Sessão de Código em um binário Usando o ``DIE ( Direct it easy versão 2.05 )``

1. Abrir o DIE e carregar o binário PE alvo. 

2. Ir até as sessões do binário

3. Desmarcar a flag na tela principal das sessões  "[] Read only"
Feito isso vai habilitar abaixo os botões "Add new section" e "Delete last section".

4. Clicar no botão "Add new section", pra criar a nova sessão > Selecionar o arquivo com os bytes que usaremos na sessão. (um shellcode por exemplo)
Podemos também colocar um arquivo em branco, apenas para criar a sessão.. e depois sim podemos colocar os bytes ref. aos código na sessão criada.
Assim que a sessão nova aparecer na tela principal das sessões, já saberemos que deu certo criar a sessão.

5. Clicar com o botão direito na sessão criada > Edit header > Desmarcar "[] Read only" > Dar um nome para a sessão. ( ESSE PASSO É OPCIONAL )

6. Clicar com o botão direito na sessão criada > Edit header > Ir até a flag Characteristics > Desmarcar "[] Read only" > Marcar as seguintes flags :

		[X] CNT_CODE 
		[X] MEM_EXECUTE
		[X] MEX_READ


Feito isso temos o campo da Characteristics da sessão a seguinte Flag :  **60000020** 
( então provavelmente quando uma sessão tiver a flag '60000020' no campo Characteristics, é provavel que seja uma
sessão de código executável ).

---

Voilá! Sessão criada =). Agora é só assemblar do zero nela ou assemblar ajustando os bytes do shellcode importado para sessão.