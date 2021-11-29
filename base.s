	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	$1, -8(%rbp)
	jmp	.L4
.L5:
	movl	-8(%rbp), %eax
	movl	%eax, %edi
	call	print@PLT
	movl	-8(%rbp), %eax
	movl	%eax, %edi
	call	print@PLT
.L4:
	cmpl	$0, -8(%rbp)
	je	.L5
	movl	$2, -4(%rbp)
	cmpl	$0, -8(%rbp)
	jne	.L7
	movl	-8(%rbp), %eax
	movl	%eax, %edi
	call	print@PLT
.L7:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
