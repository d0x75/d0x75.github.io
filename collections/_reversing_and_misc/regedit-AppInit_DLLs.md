---
title: Windows- APPInit_Dll Carregamento paralelo de DLL
category: post
---


*Testado apenas em Windows XP com sucesso*.

>AppInit_DLLs é uma chave de registro do Windows que é possível programar para uma DLL/EXE ser carregado em pararelo a qualquer aplicativo que é executado

---


#### Procedimento que deve ser feito no regedit:


- Seguir o seguinte caminho até a chave de registro :


```text
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows
```

- Chegando na reg key acima, clicamos com o botão direito nela, para modificar seu valor. Ficaria mais ou menos assim:


```text
name 	 = AppInit_DLLs (NOME DA CHAVE QUE TEMOS QUE MODIFICAR)

value 	 = "C:\Windows\System32\notepad.exe" (CAMINHO ONDE A DLL ou EXE QUE VAI SER CARREGADO SE ENCONTRA)
```

---

##### Notas:

Podemos descrever o passo a passo de um carregamento externo/paralelo de DLL :

1. Arquivo .exe é executado.

2. O aplicativo executado e as APIs utilizadas são carregadas na memória.

3. A DLL indicada pelo registro AppInit_DLLs é carregada, caso exista.

4. Todas as DLLs executam sua função principal.

5. A função principal da DLL externa desvia/altera as instruções do executável na memória, pois tem acesso livre à região de memória alocada pelo Windows.

6. O executável passa a executar um código diferente do original, que foi desviado diretamente na memória pela DLL.
