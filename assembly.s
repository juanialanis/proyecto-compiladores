  .file   'nombreArchivo.c'
  .text
  .globl	main
  .type   main, @function
main:
  pushq  %rbp
  movq  %rsp  %rbp
  movl  $1, -16(%rbp)
  movl  $2, -24(%rbp)
  movl  -16(%rbp),  %eax
  cmpl  -24(%rbp),  %eax
  setg  %al
  movzbl  %al,  %eax
  movl  %eax,  -32(%rbp)
  cmpl  $0,  -32(%rbp)
  je  .L2
  movl  $1, -8(%rbp)
  jmp  .L3
.L2
  movl  $0, -8(%rbp)
.L3
  .size main, .-main
