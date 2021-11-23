  .file   'nombreArchivo.c'
  .text
  .globl	main
  .type   main, @function
main:
  pushq  %rbp
  movq  %rsp  %rbp
  movl  $1, -16(%rbp)
  movl  $2, -24(%rbp)
  movl  $2, -24(%rbp)
  movl  $2, -24(%rbp)
  movl  $2, -24(%rbp)
  .size main, .-main
