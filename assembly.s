  .file   "nombreArchivo.c"
  .text
  .globl	potencia
  .type   potencia, @function
potencia:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $32,  %rsp
  movl  %edi, -8(%rbp)
  movl  %esi, -16(%rbp)
  movl  $1, -24(%rbp)
  movl  -8(%rbp), %eax
  movl  %eax, -32(%rbp)
.L2:
  movl  -24(%rbp),   %eax
  cmpl  -16(%rbp),   %eax
  jl  .L8
  movl  $0,  -40(%rbp)
  jmp  .L9
.L8:
  movl  $1,  -40(%rbp)
.L9:
  cmpl  $0,  -40(%rbp)
  je  .L3
  movl  -32(%rbp),  %eax
  imull  -8(%rbp),  %eax
  movl  %eax,  -48(%rbp)
  movl  -48(%rbp), %eax
  movl  %eax, -32(%rbp)
  movl  -24(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -56(%rbp)
  movl  -56(%rbp), %eax
  movl  %eax, -24(%rbp)
  jmp  .L2
.L3:
  movl  -32(%rbp),  %eax
  leave
  ret
  .size potencia, .-potencia
  .globl	factorial
  .type   factorial, @function
factorial:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $32,  %rsp
  movl  %edi, -8(%rbp)
  movl  $15, -16(%rbp)
  movl  -8(%rbp),   %eax
  cmpl  -16(%rbp),   %eax
  jg  .L10
  movl  $0,  -40(%rbp)
  jmp  .L11
.L10:
  movl  $1,  -40(%rbp)
.L11:
  cmpl  $0,  -40(%rbp)
  je  .L4
  movl  -48(%rbp),  %eax
  jmp  .L5
.L4:
  movl  $0, -24(%rbp)
  movl  $1, -32(%rbp)
.L6:
  movl  -24(%rbp),   %eax
  cmpl  -8(%rbp),   %eax
  jl  .L12
  movl  $0,  -56(%rbp)
  jmp  .L13
.L12:
  movl  $1,  -56(%rbp)
.L13:
  cmpl  $0,  -56(%rbp)
  je  .L7
  movl  -24(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -64(%rbp)
  movl  -64(%rbp), %eax
  movl  %eax, -24(%rbp)
  movl  -32(%rbp),  %eax
  imull  -24(%rbp),  %eax
  movl  %eax,  -72(%rbp)
  movl  -72(%rbp), %eax
  movl  %eax, -32(%rbp)
  jmp  .L6
.L7:
  movl  -32(%rbp),  %eax
.L5:
  leave
  ret
  .size factorial, .-factorial
  .globl	main
  .type   main, @function
main:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $24,  %rsp
  movl  $2, -8(%rbp)
  movl  $3, -16(%rbp)
  movl  -16(%rbp),  %edi
  call  factorial
  movl  %eax, -16(%rbp)
  movl  -16(%rbp),  %edi
  call  print_int
  movl  -8(%rbp),  %edi
  movl  -16(%rbp),  %esi
  call  potencia
  movl  %eax, -24(%rbp)
  movl  -24(%rbp),  %edi
  call  print_int
  movl  -24(%rbp),  %eax
  leave
  ret
  .size main, .-main
