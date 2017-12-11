# include <stdio.h> // printf
# include <unistd.h> //fork()
# include <stdlib.h> //exit()

int main(void) {
	pid_t pid1 = fork();
	
	//if in child 1
	if (pid1 == 0) {
		sleep(2);
		printf("\n");
		exit(0);
	} else {
		pid_t pid2 = fork();

		//if in child 2
		if (pid2 == 0) {
			printf(" world");
			exit(0);
		} else {
			printf("hello");
			exit(0);
		}
	}
	return (0);
}