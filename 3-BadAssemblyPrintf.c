int main() {
  asm volatile("mov $1, %%rax\n\t"
               "mov $1, %%rdi\n\t"
               "mov %0, %%rsi\n\t"
               "mov $14, %%rdx\n\t"
               "syscall\n\t"
               :
               : "r"("Hello world!\n")
               : "%rax", "%rdi", "%rsi", "%rdx");
  return 0;
}
