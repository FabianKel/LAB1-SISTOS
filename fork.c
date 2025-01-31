#include <stdio.h>
#include <unistd.h>

int main(){
	int f = fork();
	if (f == 0){
		execl("./helloExec", "helloexec", (char*)NULL);
	}else{
		printf("%d\n", (int)getpid());
		execl("./helloExec", "helloexec", (char*)NULL);
	}
	return (0);
}