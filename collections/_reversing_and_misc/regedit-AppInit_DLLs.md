---
title: Windows - APPInit_Dll Carregamento paralelo de DLL
category: post
---


*Testado apenas em Windows XP com sucesso*.

>AppInit_DLLs é uma chave de registro do Windows que é possível programar para uma DLL/EXE ser carregado em pararelo a qualquer aplicativo que é executado

---


#### Procedimento que deve ser feito no regedit:


- Seguir o seguinte caminho até a seguinte chave de registro :


```text
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows
```

- Ao chegar na chave de registro acima, clicamos com o botão direito nela, para modificar seu valor. Deve ficar com os seguintes valores:


```text
name = AppInit_DLLs
value = "C:\Windows\System32\notepad.exe" 
(CAMINHO ONDE A DLL ou EXE QUE VAI SER CARREGADO SE ENCONTRA)
```

---

#### Nota:

Para descrever por exemplo o procedimento do carregamento paralelo de uma DLL maliciosa, podemos seguir essa linha de raciocínio :

1. Um Binário/Exectável (.exe) é executado pelo usuário.

2. O aplicativo executado e as APIs utilizadas são carregadas na memória.

3. A DLL indicada pelo registro AppInit_DLLs também é carregada, caso exista.

4. Todas as DLLs executam sua função principal.

5. A função principal da DLL externa desvia/altera as instruções do executável na memória, pois tem acesso livre à região de memória alocada pelo Windows.

6. O executável passa a executar um código diferente do original, que foi desviado diretamente na memória pela DLL.
