---
title: Disabilitar ASLR 0x03
category: post
---


>O ASLR faz os endereços de memória mudarem a cada vez que o binário PE é carregado. Quando é desabilitada os endereços não ficam mais mudando a cada execução do programa.

>Para facilitar usaremos novamente o software :
``DIE ( Direct it easy versão 2.05 )``
link para download :
https://github.com/d0x75/maleta/raw/main/die_win32_portable_2.05.zip

---

#### Usando o DIE para desabilitar ASLR

- Abrir o Binário pelo DIE
- Clicar em : PE > NT Headers > Optional Header
- Ir na opção "..." DLLCharacteristics
- Desmarcar []Read only , Desmarcar []DYNAMIC_BASE

_O campo **DYNAMIC_BASE** do Optional Header, é o bit que define como ligado/desligado randomização dos endereços de memória do binário_.

```text
DYNAMIC_BASE = 0/desmarcado (desabilitado)
DYNAMIC_BASE = 1/marcado    (habilitado)
```
