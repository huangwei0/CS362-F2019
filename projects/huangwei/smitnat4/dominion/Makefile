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
alltestresults.out: randomtestcard1.c  randomtestcard2.c randomtestcard3.c unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c dominion.o
	echo "randomtestcard1.c:" >> alltestresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	randomtestcard1 >> alltestresults.out
	gcov dominion.c -b >> alltestresults.out

	echo "randomtestcard2.c" >> alltestresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	randomtestcard2 >> alltestresults.out
	gcov dominion.c -b >> alltestresults.out

	echo "randomtestcard3.c:" >> alltestresults.out
	gcc -o randomtestcard3 dominion.c rngs.c randomtestcard3.c $(CFLAGS)
	randomtestcard3 >> alltestresults.out
	gcov dominion.c -b >> testresults.out

	echo "unittest1.c:" >> alltestresults.out
	gcc -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)
	unittest1 >> alltestresults.out
	gcov dominion.c -b >> alltestresults.out

	echo "unittest2.c:" >> alltestresults.out
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	unittest2 >> alltestresults.out
	gcov dominion.c -b >> alltestresults.out

	echo "unittest3.c:" >> alltestresults.out
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	unittest3 >> alltestresults.out
	gcov dominion.c -b >> alltestresults.out

	echo "unittest4.c:" >> alltestresults.out
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	unittest4 >> alltestresults.out
	gcov dominion.c -b >> alltestresults.out

	echo "unittest5.c:" >> alltestresults.out
	gcc -o unittest5 dominion.c rngs.c unittest5.c $(CFLAGS)
	unittest5 >> alltestresults.out
	gcov dominion.c -b >> alltestresults.out

unittest1: unittest1.c dominion.o
	gcc -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)

unittest2: unittest2.c dominion.o
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)

unittest3: unittest3.c dominion.o
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)

unittest4: unittest4.c dominion.o
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)

unittest5: unittest5.c dominion.o
	gcc -o unittest5 dominion.c rngs.c unittest5.c $(CFLAGS)

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
