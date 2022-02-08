---
title: Scanning - Banner Grabing
category: post
---

>Técnica utilizada para pegar o banner de algum serviço que esteja rodando no target alvo.


#### Banner grabbing na porta 21 Usando 'netcat' :


```bash
nc -v 10.10.1.10 21
```

#### Banner grabbing na porta 3306 Usando 'telnet':


```bash
telnet 10.10.1.10 3306
```

#### Banner grabbing usando o 'curl', que retorna o banner da porta 80:


```bash
curl -vX 10.10.1.10
```