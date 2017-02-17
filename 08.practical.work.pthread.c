#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#define BUFFER_SIZE 10

typedef struct {
	char type; // 0=fried chicken, 1=French fries
	int amount; // pieces or weight
	char unit; // 0=piece, 1=gram
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

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

void print(item* a){
	printf("Produced : \n-type :");	
	if (a->type==0) printf(" fried chicken");
	else if(a->type==1) printf(" French fries");
	printf("\n-amount : %d\n-unit :",a->amount);
	if (a->unit==0) printf(" piece");
	else if(a->unit==1) printf(" gram");
	printf("\n-last : %d, first : %d\n\n",last,first);
}

void *thread_produce(){
	item disk1,disk2,disk3;
	disk1.type=0;
	disk1.amount=1;
	disk1.unit=1;
	disk2.type=1;
	disk2.amount=2;
	disk2.unit=0;
	disk3.type=1;
	disk3.amount=3;
	disk3.unit=0;
	produce(&disk1);print(&disk1);
	produce(&disk2);print(&disk2);
	produce(&disk3);print(&disk3);
};

void *thread_consume(){
	consume();printf("\nConsumed : -last : %d, first : %d\n\n",last,first);
	consume();printf("\nConsumed : -last : %d, first : %d\n\n",last,first);	
};

int main(){
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,thread_produce,NULL );
	pthread_create(&tid2,NULL,thread_consume,NULL);	
	pthread_join(tid2, NULL);
	return 0;
}
