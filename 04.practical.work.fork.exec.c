#include <stdio.h>
#include <unistd.h>
int main(){
	printf("main before fork(): \n");
	int pid = fork();
	if (pid ==0){
		printf("child after fork()\n");
		char * args[]= {"/bin/ps", "-ef", NULL};
		execvp("/bin/ps", args);
	}
	else {
	pid = fork();
	if (pid ==0){
		char * args[]={"/bin/free", "-h", NULL};
		execvp("/bin/ps", args);
	}}
	return 0;
}

