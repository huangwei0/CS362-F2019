CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomtestresults.out: randomtestcard1.c dominion.o
	echo "randomtestcard1.c:" >> randomtestresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	randomtestcard1 >> randomtestresults.out
	gcov dominion.c -b >> randomtestresults.out

	echo "randomtestcard2.c" >> randomtestresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	randomtestcard2 >> randomtestresults.out
	gcov dominion.c -b >> randomtestresults.out

	echo "randomtestcard3.c:" >> randomtestresults.out
	gcc -o randomtestcard3 dominion.c rngs.c randomtestcard3.c $(CFLAGS)
	randomtestcard3 >> randomtestresults.out
	gcov dominion.c -b >> randomtestresults.out

randomtestcard1: randomtestcard1.c dominion.o
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)

randomtestcard3: randomtestcard3.c dominion.o
	gcc -o randomtestcard3 dominion.c rngs.c randomtestcard3.c $(CFLAGS)


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
