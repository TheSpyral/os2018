#define BUFFER_SIZE 10
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

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
void *threadFunction(void *param) {
// do something in the background
}
void productThread(void *param){
	int count = 0;
	item *i;
	while (count < 3){
		i = malloc(sizeof(item));
		produce(i);
		count = count+1;
	}
}

void consumeThread(void *param){
	int count = 0;
	while (count < 2){
		consume();
		count = count + 1;
	}
}

int main(){
	pthread_t tid;
	pthread_create(
	&tid, // get thread id
	NULL, // skip the attributes
	threadFunction, // thread function name
	productThread,
	NULL);
	printf("First: %d\nLast: %d\n", first, last);
	pthread_join(tid, NULL);
	pthread_create(
	&tid,
	NULL,
	threadFunction,
	consumeThread,
	NULL);
	printf("First: %d\nLast: %d\n", first, last);
	pthread_join(tid, NULL);
}
