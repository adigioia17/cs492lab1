#include  <linux/kernel.h>
#include <linux/sched.h>

asmlinkage int my_syscall(int num1, int num2) {
    pid_t pid = task_pid_nr(current);
    int numSum = num1+num2;
    printk("my_syscall\npid = %ld\n%d + %d = %d\n", (long) pid, num1, num2, numSum);
    return numSum;
}
