---
title: Scanning 0x01
category: post
---

### Varredura de todas as portas abertas e as versões dos serviços que eventualmente estão rodando. 
Ex :

		nmap -sV -p- -Pn 10.10.1.10 -oN ./currentscan.log
		
---

### Varredura em rede local que identifica o endereço IP e MAC Address dos dispositivos conectados na rede. 
Ex:

		nmap -sn 10.10.1.1-254 -oN ./currentscan.log

---

### Varredura para verificar versão do sistema operacional e dos serviços ativos.
Ex :

		nmap -O -v 10.10.1.10 -oN ./currentscan.log

