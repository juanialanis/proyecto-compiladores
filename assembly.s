  .globl	fibonacci
  .type   fibonacci, @function
fibonacci:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $128,  %rsp
  movl  %edi, -8(%rbp)
  movl  $0, -24(%rbp)
  movl  $1, -32(%rbp)
  movl  $1, -16(%rbp)
.L2:
  movl  -16(%rbp),   %eax
  cmpl  -8(%rbp),   %eax
  jl  .L30
  movl  $0,  -48(%rbp)
  jmp  .L31
.L30:
  movl  $1,  -48(%rbp)
.L31:
  cmpl  $0,  -48(%rbp)
  je  .L3
  movl  -24(%rbp),  %eax
  addl  -32(%rbp),  %eax
  movl  %eax,  -56(%rbp)
  movl  -56(%rbp), %eax
  movl  %eax, -40(%rbp)
  movl  -32(%rbp), %eax
  movl  %eax, -24(%rbp)
  movl  -40(%rbp), %eax
  movl  %eax, -32(%rbp)
  movl  -16(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -64(%rbp)
  movl  -64(%rbp), %eax
  movl  %eax, -16(%rbp)
  jmp  .L2
.L3:
  movl  -32(%rbp),  %eax
  jmp .LR1
.LR1:
  leave
  ret
  .size fibonacci, .-fibonacci
  .globl	potencia
  .type   potencia, @function
potencia:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $64,  %rsp
  movl  %edi, -8(%rbp)
  movl  %esi, -16(%rbp)
  movl  $1, -24(%rbp)
  movl  -8(%rbp), %eax
  movl  %eax, -32(%rbp)
.L4:
  movl  -24(%rbp),   %eax
  cmpl  -16(%rbp),   %eax
  jl  .L32
  movl  $0,  -40(%rbp)
  jmp  .L33
.L32:
  movl  $1,  -40(%rbp)
.L33:
  cmpl  $0,  -40(%rbp)
  je  .L5
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
  jmp  .L4
.L5:
  movl  -32(%rbp),  %eax
  jmp .LR2
.LR2:
  leave
  ret
  .size potencia, .-potencia
  .globl	factorial
  .type   factorial, @function
factorial:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $128,  %rsp
  movl  %edi, -8(%rbp)
  movl  $15, -16(%rbp)
  movl  -8(%rbp),   %eax
  cmpl  -16(%rbp),   %eax
  jg  .L34
  movl  $0,  -40(%rbp)
  jmp  .L35
.L34:
  movl  $1,  -40(%rbp)
.L35:
  cmpl  $0,  -40(%rbp)
  je  .L6
  movl  -48(%rbp),  %eax
  jmp .LR3
  jmp  .L7
.L6:
  movl  $0, -24(%rbp)
  movl  $1, -32(%rbp)
.L8:
  movl  -24(%rbp),   %eax
  cmpl  -8(%rbp),   %eax
  jl  .L36
  movl  $0,  -56(%rbp)
  jmp  .L37
.L36:
  movl  $1,  -56(%rbp)
.L37:
  cmpl  $0,  -56(%rbp)
  je  .L9
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
  jmp  .L8
.L9:
  movl  -32(%rbp),  %eax
  jmp .LR3
.L7:
.LR3:
  leave
  ret
  .size factorial, .-factorial
  .globl	nthprime
  .type   nthprime, @function
nthprime:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $128,  %rsp
  movl  %edi, -8(%rbp)
  movl  $0, -16(%rbp)
  movl  $2, -24(%rbp)
  movl  -8(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -40(%rbp)
  movl  -40(%rbp), %eax
  movl  %eax, -8(%rbp)
.L10:
  movl  -8(%rbp),   %eax
  cmpl  $0,   %eax
  jg  .L38
  movl  $0,  -48(%rbp)
  jmp  .L39
.L38:
  movl  $1,  -48(%rbp)
.L39:
  cmpl  $0,  -48(%rbp)
  je  .L11
  movl  $0, -32(%rbp)
  movl  -16(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -56(%rbp)
  movl  -56(%rbp), %eax
  movl  %eax, -16(%rbp)
.L12:
  movl -32(%rbp), %eax
  cmp  $0,  %eax
  je  .L40
  movl $0,  %eax
  jmp  .L41
.L40:
  movl $1,  %eax
.L41:
  movl %eax,  -64(%rbp)
  movl  -24(%rbp),   %eax
  cmpl  -16(%rbp),   %eax
  jl  .L42
  movl  $0,  -72(%rbp)
  jmp  .L43
.L42:
  movl  $1,  -72(%rbp)
.L43:
  cmpl  $0,  -64(%rbp)
  je  .L44
  cmpl  $0,  -72(%rbp)
  je  .L44
  movl  $1,  -80(%rbp)
  jmp  .L45
.L44:
  movl  $0,  -80(%rbp)
.L45:
  cmpl  $0,  -80(%rbp)
  je  .L13
  movl  $0,  %edx
  movl  -16(%rbp),   %eax
  movl  -24(%rbp),   %ecx
  div  %ecx
  movl  %edx,  -88(%rbp)
  movl  -88(%rbp),   %eax
  cmpl  $0,   %eax
  je  .L46
  movl  $0,  -96(%rbp)
  jmp  .L47
.L46:
  movl  $1,  -96(%rbp)
.L47:
  cmpl  $0,  -96(%rbp)
  je  .L14
  movl  $1, -32(%rbp)
  jmp  .L15
.L14:
  movl  -24(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -104(%rbp)
  movl  -104(%rbp), %eax
  movl  %eax, -24(%rbp)
.L15:
  jmp  .L12
.L13:
  movl  $2, -24(%rbp)
  movl -32(%rbp), %eax
  cmp  $0,  %eax
  je  .L48
  movl $0,  %eax
  jmp  .L49
.L48:
  movl $1,  %eax
.L49:
  movl %eax,  -112(%rbp)
  cmpl  $0,  -112(%rbp)
  je  .L16
  movl  -8(%rbp),  %eax
  subl  $1,  %eax
  movl  %eax,  -120(%rbp)
  movl  -120(%rbp), %eax
  movl  %eax, -8(%rbp)
.L16:
  jmp  .L10
.L11:
  movl  -16(%rbp),  %eax
  jmp .LR4
.LR4:
  leave
  ret
  .size nthprime, .-nthprime
  .globl	gcd
  .type   gcd, @function
gcd:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $128,  %rsp
  movl  %edi, -8(%rbp)
  movl  %esi, -16(%rbp)
  movl  $1, -24(%rbp)
  movl  -24(%rbp), %eax
  movl  %eax, -32(%rbp)
.L17:
  movl  -8(%rbp),  %eax
  addl  -16(%rbp),  %eax
  movl  %eax,  -40(%rbp)
  movl  -24(%rbp),   %eax
  cmpl  -40(%rbp),   %eax
  jl  .L50
  movl  $0,  -48(%rbp)
  jmp  .L51
.L50:
  movl  $1,  -48(%rbp)
.L51:
  cmpl  $0,  -48(%rbp)
  je  .L18
  movl  $0,  %edx
  movl  -8(%rbp),   %eax
  movl  -24(%rbp),   %ecx
  div  %ecx
  movl  %edx,  -56(%rbp)
  movl  -56(%rbp),   %eax
  cmpl  $0,   %eax
  je  .L52
  movl  $0,  -64(%rbp)
  jmp  .L53
.L52:
  movl  $1,  -64(%rbp)
.L53:
  movl  $0,  %edx
  movl  -16(%rbp),   %eax
  movl  -24(%rbp),   %ecx
  div  %ecx
  movl  %edx,  -72(%rbp)
  movl  -72(%rbp),   %eax
  cmpl  $0,   %eax
  je  .L54
  movl  $0,  -80(%rbp)
  jmp  .L55
.L54:
  movl  $1,  -80(%rbp)
.L55:
  cmpl  $0,  -64(%rbp)
  je  .L56
  cmpl  $0,  -80(%rbp)
  je  .L56
  movl  $1,  -88(%rbp)
  jmp  .L57
.L56:
  movl  $0,  -88(%rbp)
.L57:
  cmpl  $0,  -88(%rbp)
  je  .L19
  movl  $0,  %edx
  movl  -16(%rbp),   %eax
  movl  -24(%rbp),   %ecx
  div  %ecx
  movl  %edx,  -96(%rbp)
  movl  -96(%rbp),   %eax
  cmpl  $0,   %eax
  je  .L58
  movl  $0,  -104(%rbp)
  jmp  .L59
.L58:
  movl  $1,  -104(%rbp)
.L59:
  movl  -24(%rbp), %eax
  movl  %eax, -32(%rbp)
.L19:
  movl  -24(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -112(%rbp)
  movl  -112(%rbp), %eax
  movl  %eax, -24(%rbp)
  jmp  .L17
.L18:
  movl  -32(%rbp),  %eax
  jmp .LR5
.LR5:
  leave
  ret
  .size gcd, .-gcd
  .globl	test
  .type   test, @function
test:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $64,  %rsp
  movl  %edi, -8(%rbp)
  movl  $3,  %edi
  call  factorial
  movl  %eax, -32(%rbp)
  movl  %eax, -16(%rbp)
  movl  $4,  %edi
  call  factorial
  movl  %eax, -40(%rbp)
  movl  %eax, -24(%rbp)
  movl  -16(%rbp),  %edi
  movl  -24(%rbp),  %esi
  call  gcd
  movl  %eax, -48(%rbp)
  movl  %eax, -24(%rbp)
  movl  -24(%rbp),  %edi
  call  print
  movl  %eax, -56(%rbp)
  movl  -24(%rbp),  %edi
  call  nthprime
  movl  %eax, -64(%rbp)
  movl  %eax, -16(%rbp)
  movl  -16(%rbp),  %edi
  call  print
  movl  %eax, -72(%rbp)
  movl  $3,  %edi
  movl  -24(%rbp),  %esi
  call  potencia
  movl  %eax, -80(%rbp)
  movl  %eax, -16(%rbp)
  movl  -16(%rbp),  %edi
  call  print
  movl  %eax, -88(%rbp)
.LR6:
  leave
  ret
  .size test, .-test
  .globl	test1
  .type   test1, @function
test1:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $64,  %rsp
  movl  %edi, -8(%rbp)
  movl  $2, -16(%rbp)
  movl  $1,  %edi
  call  test
  movl  %eax, -24(%rbp)
  movl  -16(%rbp),  %edi
  call  print
  movl  %eax, -32(%rbp)
.LR7:
  leave
  ret
  .size test1, .-test1
  .globl	main
  .type   main, @function
main:
  pushq  %rbp
  movq  %rsp,  %rbp
  subq $192,  %rsp
  movl  -16(%rbp),  %edi
  call  print_separador
  movl  %eax, -40(%rbp)
  movl  $5, -8(%rbp)
  movl  $0, -16(%rbp)
  movl  $1, -24(%rbp)
.L20:
  movl  -16(%rbp),   %eax
  cmpl  -8(%rbp),   %eax
  jl  .L60
  movl  $0,  -48(%rbp)
  jmp  .L61
.L60:
  movl  $1,  -48(%rbp)
.L61:
  cmpl  $0,  -48(%rbp)
  je  .L21
  movl  -24(%rbp),  %edi
  call  fibonacci
  movl  %eax, -56(%rbp)
  movl  %eax, -32(%rbp)
  movl  -24(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -64(%rbp)
  movl  -64(%rbp), %eax
  movl  %eax, -24(%rbp)
  movl  -32(%rbp),  %edi
  call  print
  movl  %eax, -72(%rbp)
  movl  -16(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -80(%rbp)
  movl  -80(%rbp), %eax
  movl  %eax, -16(%rbp)
  jmp  .L20
.L21:
  movl  -16(%rbp),  %edi
  call  print_separador
  movl  %eax, -88(%rbp)
  movl  $4, -8(%rbp)
  movl  $0, -16(%rbp)
  movl  $3, -24(%rbp)
.L22:
  movl  -16(%rbp),   %eax
  cmpl  -8(%rbp),   %eax
  jl  .L62
  movl  $0,  -96(%rbp)
  jmp  .L63
.L62:
  movl  $1,  -96(%rbp)
.L63:
  cmpl  $0,  -96(%rbp)
  je  .L23
  movl  -24(%rbp),  %edi
  call  factorial
  movl  %eax, -104(%rbp)
  movl  %eax, -32(%rbp)
  movl  -24(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -112(%rbp)
  movl  -112(%rbp), %eax
  movl  %eax, -24(%rbp)
  movl  -32(%rbp),  %edi
  call  print
  movl  %eax, -120(%rbp)
  movl  -16(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -128(%rbp)
  movl  -128(%rbp), %eax
  movl  %eax, -16(%rbp)
  jmp  .L22
.L23:
  movl  -16(%rbp),  %edi
  call  print_separador
  movl  %eax, -136(%rbp)
  movl  $3, -8(%rbp)
  movl  $0, -16(%rbp)
  movl  $4, -24(%rbp)
.L24:
  movl  -16(%rbp),   %eax
  cmpl  -8(%rbp),   %eax
  jl  .L64
  movl  $0,  -144(%rbp)
  jmp  .L65
.L64:
  movl  $1,  -144(%rbp)
.L65:
  cmpl  $0,  -144(%rbp)
  je  .L25
  movl  -24(%rbp),  %edi
  call  nthprime
  movl  %eax, -152(%rbp)
  movl  %eax, -32(%rbp)
  movl  -24(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -160(%rbp)
  movl  -160(%rbp), %eax
  movl  %eax, -24(%rbp)
  movl  -32(%rbp),  %edi
  call  print
  movl  %eax, -168(%rbp)
  movl  -16(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -176(%rbp)
  movl  -176(%rbp), %eax
  movl  %eax, -16(%rbp)
  jmp  .L24
.L25:
  movl  -16(%rbp),  %edi
  call  print_separador
  movl  %eax, -184(%rbp)
  movl  $3, -8(%rbp)
  movl  $0, -16(%rbp)
.L26:
  movl  -16(%rbp),   %eax
  cmpl  -8(%rbp),   %eax
  jl  .L66
  movl  $0,  -192(%rbp)
  jmp  .L67
.L66:
  movl  $1,  -192(%rbp)
.L67:
  cmpl  $0,  -192(%rbp)
  je  .L27
  movl  -16(%rbp),  %eax
  addl  $8,  %eax
  movl  %eax,  -200(%rbp)
  movl  -200(%rbp),  %edi
  movl  -16(%rbp),  %eax
  addl  $2,  %eax
  movl  %eax,  -208(%rbp)
  movl  -208(%rbp),  %esi
  call  gcd
  movl  %eax, -216(%rbp)
  movl  %eax, -32(%rbp)
  movl  -32(%rbp),  %edi
  call  print
  movl  %eax, -224(%rbp)
  movl  -16(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -232(%rbp)
  movl  -232(%rbp), %eax
  movl  %eax, -16(%rbp)
  jmp  .L26
.L27:
  movl  -16(%rbp),  %edi
  call  print_separador
  movl  %eax, -240(%rbp)
  movl  $3, -8(%rbp)
  movl  $0, -16(%rbp)
.L28:
  movl  -16(%rbp),   %eax
  cmpl  -8(%rbp),   %eax
  jl  .L68
  movl  $0,  -248(%rbp)
  jmp  .L69
.L68:
  movl  $1,  -248(%rbp)
.L69:
  cmpl  $0,  -248(%rbp)
  je  .L29
  movl  -16(%rbp),  %eax
  addl  $2,  %eax
  movl  %eax,  -256(%rbp)
  movl  -256(%rbp),  %edi
  movl  -16(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -264(%rbp)
  movl  -264(%rbp),  %esi
  call  potencia
  movl  %eax, -272(%rbp)
  movl  %eax, -32(%rbp)
  movl  -32(%rbp),  %edi
  call  print
  movl  %eax, -280(%rbp)
  movl  -16(%rbp),  %eax
  addl  $1,  %eax
  movl  %eax,  -288(%rbp)
  movl  -288(%rbp), %eax
  movl  %eax, -16(%rbp)
  jmp  .L28
.L29:
  movl  -16(%rbp),  %edi
  call  print_separador
  movl  %eax, -296(%rbp)
  movl  $1,  %edi
  call  test
  movl  %eax, -304(%rbp)
  movl  -16(%rbp),  %edi
  call  print_separador
  movl  %eax, -312(%rbp)
  movl  $1,  %edi
  call  test1
  movl  %eax, -320(%rbp)
  movl  $1,  %eax
  jmp .LR8
.LR8:
  leave
  ret
  .size main, .-main
