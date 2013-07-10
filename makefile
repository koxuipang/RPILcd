DisplayDemo : DisplayDemo.o ITEADTFT.o SFont.o
	cc -o DisplayDemo DisplayDemo.o ITEADTFT.o SFont.o -lm -lwiringPi
DisplayDemo.o : DisplayDemo.c ITEADTFT.h SFont.h
	cc -c DisplayDemo.c 
ITEADTFT.o : ITEADTFT.c ITEADTFT.h 
	cc -c ITEADTFT.c -lm -lwiringPi  
SFont.o : SFont.c SFont.h
	cc -c SFont.c
clean :
	rm DisplayDemo DisplayDemo.o ITEADTFT.o SFont.o 
install:
	cc -shared -fpic -o libITEADTFT.so ITEADTFT.c SFont.c -lm -lwiringPi
	sudo cp libITEADTFT.so /usr/lib
