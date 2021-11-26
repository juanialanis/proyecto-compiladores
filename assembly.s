  .file   "nombreArchivo.c"
  .text
  .globl	sum
  .type   sum, @function
sum:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $16,  %rsp
  movl  %rdi, -8(%rbp)
  movl  %rsi, -16(%rbp)
  movl  -8(%rbp),  %eax
  addl  -16(%rbp),  %eax
  movl  %eax,  -24(%rbp)
  movl  -24(%rbp),  %eax
  leave
  ret
  .size sum, .-sum
  .globl	main
  .type   main, @function
main:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $24,  %rsp
  movl  $1, -8(%rbp)
  movl  $1, -16(%rbp)
  movl  $1, -24(%rbp)
  movl  -8(%rbp),  %eax
  addl  -8(%rbp),  %eax
  movl  %eax,  -32(%rbp)
  movl  -32(%rbp),  %rdx
  movl  -16(%rbp),  %rcx
  call  sum
  movl  %eax, -8(%rbp)
  leave
  ret
  .size main, .-main
