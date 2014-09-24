 ;
 ;      manual PE 
 ; 
	image_base	equ 0x400000 
	alignment	equ 0x4
	stack_reserve	equ 0x1000 
	stack_commit	equ 0x1000 
	heap_reserve	equ 0x1000 
	heap_commit	equ 0x1000 
 ; 
 ;      dos header 
 ;      pe header 
 ;      optional header 
 ;      directory entries 
 ;      import header 
 ;      code directory 
 ;      import directory 
 ;
 format binary as "exe"
	use32 
	 
	 dos_header:
	 
	       dw 'MZ'		       ; DOS signature
	       db 0x3A dup(0)	       ; unused
	       dd 0x40		       ; PE header address
	 
	pe_header: 
	 
		db 'PE',0,0		; PE signature 
		dw 0x014C		; cpu (386)
		dw 1			; number of sections
		dd 0			; timestamp
		dd 0			; symbol table address
		dd 0			; number of symbols
		dw sizeof.header	; size of optional header
		dw 0x010F		; characteristics

	optional_header:
		 
		dw 0x010B		; magic
		dw 0			; linker version
		dd 0			; size of code section
		dd 0			; size of initialised data
		dd 0			; size of uninitialise data
		dd code_directory	; entry point address
		dd 0			; base of code
		dd 0			; base of data
		dd image_base		; base of image 
		dd alignment		; section alignment 
		dd alignment		; file alignment 
		dw 0			; os version major
		dw 0			; os version minor
		dw 0			; image version major
		dw 0			; image version minor
		dw 4			; subsystem version major
		dw 0			; subsystem version minor
		dd 0			; win32 version (reserved)
		dd sizeof.image 	; image size 
		dd code_directory	; header size 
		dd 0			; checksum
		dw 0x0002		; subsystem (GUI)
		dw 0			; dll characteristics
		dd stack_reserve	; stack reserve size
		dd stack_commit 	; stack commit size
		dd heap_reserve 	; heap reserve size
		dd heap_commit		; heap commit size 
		dd 0			; loader flags (obsolete)
		dd 16			; number of directory entries

		 
	directory_entries: 
		 
		dq 0			; export
		dd import_directory	; import section rva 
		dd sizeof.import	; import section size 
		dq 14 dup(0)		; the rest
		 
	import_header: 
		 
		dq '.import'		; name 
		dd 0;sizeof.import        ; virtual size
		dd 0;code_directory       ; rva
		dd 0;sizeof.import        ; raw size
		dd 0;code_directory       ; raw pointer to data
	       ;dd 0                    ; pointer to relocations
	       ;dd 0                    ; pointer to line numbers
	       ;dw 0                    ; number of relocations
	       ;dw 0                    ; number of line numbers
	       ;dd 0x0E0000020          ; characteristics
	       ; align alignment
		 
	code_directory: 
		 
		push 0 
		push title+image_base 
		push message+image_base 
		push 0 
		call[MessageBox+image_base] 
		push 0 
		call[ExitProcess+image_base] 
		title: db 'Title',0
		message: db 'Hello world',0
		 
	import_directory: 
		 
		dd 0,0,0,kernel_name,kernel_table 
		dd 0,0,0,user_name,user_table 
		dd 0,0,0,0,0
		kernel_name db 'KERNEL32.DLL',0 
		user_name db 'USER32.DLL', 0 

		kernel_table:
		ExitProcess dd _ExitProcess 
		dd 0

		user_table:
		MessageBox dd _MessageBox
		dd 0 

		_MessageBox db 0, 0, 'MessageBoxA', 0
		_ExitProcess db 0,0,'ExitProcess',0 
		 
	file_end: 
		 
		sizeof.import = file_end-import_directory 
		sizeof.header = import_header-optional_header
		sizeof.image = file_end