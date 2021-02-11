#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/string.h>

asmlinkage int my_syscall2(char* str) {
	int i=0;
	int replacements=0;
	int stringSize = strlen(&str[0]);
	pid_t pid = task_pid_nr(current);
	char* newStr = str;
	printk("pid = %ld\ninput: %s\n", (long) pid, str);
	if(stringSize>128) {
		return -1;
	}
	for(i=0; i<stringSize; i++) {
		if(newStr[i]=='o') {
			replacements++;
			newStr[i]='0';
		}
	}
	printk("output: %s\n", newStr);
	return replacements;
}
