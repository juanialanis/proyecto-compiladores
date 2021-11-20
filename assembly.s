  .file   'nombreArchivo.c'
  .text
  .globl	main
  .type   main, @function
main:
  pushq  %rbp
  movq  %rsp  %rbp
  movl  $0, -8(%rbp)
  movl  $1  -24(%rbp)
  addl  $5  -24(%rbp)
  movl  -24(%rbp), -8(%rbp)
  .size main, .-main
