all:
	gcc main.c Headers/ListaLINHAS.h Sources/ListaLINHAS.c Headers/PALAVRA.h Sources/PALAVRA.c Headers/ListaPALAVRAS.h Sources/ListaPALAVRAS.c Headers/Ordenacoes.h Sources/Ordenacoes.c Headers/Dicionario.h Sources/Dicionario.c Headers/Menu.h Sources/Menu.c

Linux:
	./a.out

Windows:
	./a.exe
