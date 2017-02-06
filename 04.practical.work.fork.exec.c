#include<stdio.h>
#include<unistd.h>
int main(){
	printf("Main before fork() \n");
	int pid = fork();

	if (pid == 0){
		printf("This is child 1, launching ps -ef\n");
		char *args[]={"/bin/ps","-ef",NULL};
		execvp("/bin/ps",args);
		printf("Exiting ps -ef\n");	
	}else printf("This is parent, child is %d\n",pid);
	int pid1 = fork();
	
	if (pid1 == 0){
		printf("This is child 2, launching free -h\n");
		char *args[]={"free","-h",NULL};
		execvp("free",args);
		printf("Exiting\n");	
	}else printf("This is parent, The child is %d \n",pid1);
	return 0;
}
