
.code
?SysNtCreateFile@@YAJPEAPEAXKPEAU_OBJECT_ATTRIBUTES@@PEAU_IO_STATUS_BLOCK@@PEAT_LARGE_INTEGER@@KKKKPEAXK@Z proc
			mov r10, rcx
			mov eax, 55h	;win10 1809 17763.437
			syscall
			ret
?SysNtCreateFile@@YAJPEAPEAXKPEAU_OBJECT_ATTRIBUTES@@PEAU_IO_STATUS_BLOCK@@PEAT_LARGE_INTEGER@@KKKKPEAXK@Z endp
end