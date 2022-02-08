---
title: Reversing 0x03
category: post
---


## Desabiltando o ASLR.

O ASLR faz os endereços de memória mudarem a cada vez que o binário PE é carregado. Quando é desabilitada os endereços não ficam mais mudando a cada execução do programa.


---


### Usando o DIE para desabilitar ASLR  (direct it easy) :

``testado na versão 2.05 do DIE``

- Abrir o Binário pelo DIE
- Clicar em : PE > NT Headers > Optional Header
- Ir na opção "..." DLLCharacteristics
- Desmarcar []Read only , Desmarcar []DYNAMIC_BASE


O campo **DYNAMIC_BASE** do Optional Header, é o bit que define como ligado/desligado randomização dos endereços de memória do binário_.



