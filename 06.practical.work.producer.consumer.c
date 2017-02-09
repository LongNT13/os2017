#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void print(char a,int b,char c){
	printf("Produced : \n-type :");	
	if (a==0) printf(" fried chicken");
	else if(a==1) printf(" French fries");
	printf("\n-amount : %d\n-unit :",b);
	if (c==0) printf(" piece");
	else if(c==1) printf(" gram");
	printf("\n-last : %d, first : %d\n\n",last,first);
}
int main(){
	item disk1,disk2;
	disk1.type=0;
	disk1.amount=1;
	disk1.unit=1;
	disk2.type=1;
	disk2.amount=2;
	disk2.unit=0;
	produce(&disk1);
	print(disk1.type,disk1.amount,disk1.unit);
	produce(&disk2);
	print(disk2.type,disk2.amount,disk2.unit);
	consume();
	printf("Consumed:\n-last : %d, first : %d\n",last,first);
	return 0;
}
