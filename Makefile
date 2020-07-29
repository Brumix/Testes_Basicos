#This is a Make File

CC = gcc
CFLAGS = -o
Cexec= ./


all:
	gcc main.c qwe.c -o output
	gcc doubleLinkedList.c -o doubleLinkedList.out
	gcc linkedList.c -o linkedList.out 
	$(CC) stack.c $(CFLAGS) stack.out
	$(CC) queue.c $(CFLAGS) queue.out
	$(CC) testesbasicos.c $(CFLAGS) testesbasicos.out

execall:
	./output
	./doubleLinkedList.out
	./linkedList.out
	$(Cexec)stack.out
	$(Cexec)queue.out
	$(Cexec)testesbasicos.out


CdoubleLinkedList:
	$(CC) doubleLinkedList.c $(CFLAGS) doubleLinkedList.out

doubleLinkedList:
	$(Cexec)doubleLinkedList.out


ClinkedList:
	$(CC) linkedList.c $(CFLAGS) linkedList.out

linkedList:
	$(Cexec)linkedList.out
	$(Cexec)linkedList.out


Cstack:
	$(CC) stack.c $(CFLAGS) stack.out

stack:
	$(Cexec)stack.out



Cqueue:
	$(CC) queue.c $(CFLAGS) queue.out

queue:
	$(Cexec)queue.out



Ctestesbasicos:
	$(CC) testesbasicos.c $(CFLAGS) testesbasicos.out

testesbasicos:
	$(Cexec)testesbasicos.out


clean:
	rm -rf *.out
	rm -rf *.o
	rm -rf output
