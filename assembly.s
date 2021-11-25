  .file   "nombreArchivo.c"
  .text
  .globl	sum
  .type   sum, @function
sum:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $24,  %rsp
  movl  -8(%rbp),  %eax
  addl  -16(%rbp),  %eax
  movl  %eax,  -32(%rbp)
  movl  -32(%rbp),  %eax
  addl  -24(%rbp),  %eax
  movl  %eax,  -40(%rbp)
  movl  -40(%rbp),  %eax
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
  movl  %eax, -8(%rbp)
  movl  $5, -8(%rbp)
  leave
  ret
  .size main, .-main
