main_arvore:	arvore.o
	gcc	arvore.o	main_arvore.c	-o	main_arvore

arvore.o:	arvore.c	arvore.h
	gcc	-c	arvore.c	-o	arvore.o

clean:
	rm	-rf	*.o	main_arvore

main_hashlinear:	d_hash_linear.o
	gcc	d_hash_linear.o	main_hashlinear.c	-o	main_hashlinear

d_hash_linear.o:
	gcc	-c	d_hash_linear.c	-o	d_hash_linear.o

clean:
	rm	-rf	*.o	main_hashlinear

main_enderecamento:	enderecamento.o
	gcc	enderecamento.o	main_enderecamento.c	-o	main_enderecamento

enderecamento.o:	enderecamento.c	enderecamento.h
	gcc	-c	enderecamento.c	-o	enderecamento.o

clean:
	rm	-rf	*.o	main_enderecamento