PROJ_NAME_COMP = Compacta
PROJ_NAME_DESCOMP = Descompacta
CC_FLAGS=-c -w -Wall

$(PROJ_NAME_COMP): obj/main_Comp.o  obj/main_Descomp.o obj/lista.o obj/arvore.o obj/tad_funcoes.o obj/bitmap.o
	gcc -o $(PROJ_NAME_DESCOMP) obj/main_Descomp.o obj/lista.o obj/arvore.o obj/tad_funcoes.o obj/bitmap.o
	gcc -o $(PROJ_NAME_COMP) obj/main_Comp.o obj/lista.o obj/arvore.o obj/tad_funcoes.o obj/bitmap.o

obj/main_Descomp.o: implementation/main_Descomp.c
	gcc -o obj/main_Descomp.o implementation/main_Descomp.c $(CC_FLAGS)

obj/main_Comp.o: implementation/main_Comp.c
	gcc -o obj/main_Comp.o implementation/main_Comp.c $(CC_FLAGS)

obj/lista.o: implementation/lista.c
	gcc -o obj/lista.o implementation/lista.c $(CC_FLAGS)

obj/arvore.o: implementation/arvore.c
	gcc -o obj/arvore.o implementation/arvore.c $(CC_FLAGS)

obj/tad_funcoes.o: implementation/tad_funcoes.c
	gcc -o obj/tad_funcoes.o implementation/tad_funcoes.c $(CC_FLAGS)

obj/bitmap.o: implementation/bitmap.c
	gcc -o obj/bitmap.o implementation/bitmap.c $(CC_FLAGS)




clean:
	rm -rf obj/*.o
	rm -rf $(PROJ_NAME_COMP)
	rm -rf $(PROJ_NAME_DESCOMP)

rmpromper: clean
	rm -rf $(PROJ_NAME)

run:
	valgrind ./$(PROJ_NAME)