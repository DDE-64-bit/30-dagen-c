#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Gebruik: %s <programma>\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execl(argv[1], argv[1], NULL);
    } else {
        int status;
        waitpid(pid, &status, 0);

        struct user_regs_struct regs;
        if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1) {
            perror("ptrace GETREGS");
            return 1;
        }

        printf("RIP: 0x%llx\n", regs.rip);
        printf("RSP: 0x%llx\n", regs.rsp);
        printf("RBP: 0x%llx\n", regs.rbp);
        printf("RAX: 0x%llx\n", regs.rax);
        printf("RBX: 0x%llx\n", regs.rbx);
        printf("RCX: 0x%llx\n", regs.rcx);
        printf("RDX: 0x%llx\n", regs.rdx);

        ptrace(PTRACE_CONT, pid, NULL, NULL);
        waitpid(pid, &status, 0);
    }

    return 0;
}
