#define BUFFER_SIZE 10
#include <stdio.h>
#include <unistd.h>

typedef struct {
	char type; 
	int amount; 
	char unit; 
} item;
item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;


void produce(item *i) {
	while ((first + 1) % BUFFER_SIZE == last) {
	// do nothing -- no free buffer item
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}


item *consume() {
	item *i = malloc(sizeof(item));
		while (first == last) {
		// do nothing -- nothing to consume
		}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

int main (){
	item *i;
	i = malloc(sizeof(item));
	printf("Produce 1st item:\n");
	produce(i);
	printf("First: %d\nLast: %d\n", first, last);
	printf("Produce 2nd item:\n");
	produce(i);
	printf("First: %d\nLast: %d\n", first, last);
	printf("Consume item:");
	consume();
	printf("First: %d\nLast: %d\n", first, last);
}
