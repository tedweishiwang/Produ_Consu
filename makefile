program: main.o producer.o consumer.o
	gcc -o program main.o producer.o consumer.o
main.o: main.c main.h
	gcc -c main.c
producer.o: producer.c main.h
	gcc -c producer.c
consumer.o: consumer.c main.h
	gcc -c consumer.c
clean:
	rm *.o program
