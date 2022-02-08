---
title: Scanning - Banner Grabing
category: post
---



Técnica utilizada para pegar o banner de algum serviço que esteja rodando no target alvo.

---

### With netcat - Usando o netcat no host '10.10.1.10 ' e na porta '21', exemplo :

		nc -v 10.10.1.10 21

### With telnet - Usando telnet no host '10.10.1.10' e na porta '3306', exemplo :

		telnet 10.10.1.10 3306

### With curl - Agora o curl, que pega o banner apenas para a porta 80 por padrão. Então passamos apenas o target do host '10.10.1.10' , exemplo :

		curl -v 10.10.1.10