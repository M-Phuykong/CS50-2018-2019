	.text
	.file	"functions1.c"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movabsq	$.L.str, %rdi
	movb	$0, %al
	callq	get_int
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %edi
	callq	cubed
	movabsq	$.L.str.1, %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	printf
	xorl	%esi, %esi
	movl	%eax, -8(%rbp)          # 4-byte Spill
	movl	%esi, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.globl	cubed
	.align	16, 0x90
	.type	cubed,@function
cubed:                                  # @cubed
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp5:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	imull	-4(%rbp), %edi
	imull	-4(%rbp), %edi
	movl	%edi, %eax
	popq	%rbp
	retq
.Lfunc_end1:
	.size	cubed, .Lfunc_end1-cubed
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Enter an int: "
	.size	.L.str, 15

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Cube: %d\n "
	.size	.L.str.1, 11


	.ident	"clang version 3.8.0-2ubuntu3~trusty5 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
