#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
	char test1[10]="qwertyuio";
	char test2[156]="abcdefghijklmnopqrstuvwxvzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";

	char copyOfTest1[10];
	char copyOfTest2[156];
	strcpy(copyOfTest1,test1);
	strcpy(copyOfTest2,test2);

	int ex1=syscall(548,12,16);
	int ex2=syscall(549,test1);
	int ex3=syscall(549,test2);
	pid_t pid = getpid();

	printf("Annmarie DiGioia\nPID: %ld\n ", (long) pid);
	printf("my_syscall: 12+16 = %d \n ", ex1);
	printf("(when less than 128 bytes) my_syscall2 :\ninput: %s\noutput: %d\n", copyOfTest1, ex2);
	printf("(when more than 128 bytes) my_syscall2 :\ninput: %s\noutput: %d\n", copyOfTest2, ex3);
	return 0;
}
