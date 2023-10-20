global __atomic_add8
global __atomic_add16
global __atomic_add32
global __atomic_add64

global __atomic_sub8
global __atomic_sub16
global __atomic_sub32
global __atomic_sub64

global __atomic_cmpxchg8
global __atomic_cmpxchg16
global __atomic_cmpxchg32
global __atomic_cmpxchg64

global __atomic_inc8
global __atomic_inc16
global __atomic_inc32
global __atomic_inc64

global __atomic_dec8
global __atomic_dec16
global __atomic_dec32
global __atomic_dec64

section .text

__atomic_add8:
    lock add byte[rcx], dl
    mov  al, byte[rcx]
    ret

__atomic_add16:
    lock add word[rcx], dx
    mov  ax, word[rcx]
    ret

__atomic_add32:
    lock add dword[rcx], edx
    mov eax, dword[rcx]
    ret

__atomic_add64:
    lock add  qword[rcx], rdx
    mov  rax, qword[rcx]
    ret


__atomic_sub8:
    lock sub byte[rcx], dl
    mov  al, byte[rcx]
    ret

__atomic_sub16:
    lock sub word[rcx], dx
    mov  ax, word[rcx]
    ret

__atomic_sub32:
    lock sub dword[rcx], edx
    mov eax, dword[rcx]
    ret

__atomic_sub64:
    lock sub qword[rcx], rdx
    mov rax, qword[rcx]
    ret


__atomic_inc8:
    lock inc byte[rcx]
    mov  al, byte[rcx]
    ret

__atomic_inc16:
    lock inc word[rcx]
    mov  ax, word[rcx]
    ret

__atomic_inc32:
    lock inc dword[rcx]
    mov eax, dword[rcx]
    ret

__atomic_inc64:
    lock inc qword[rcx]
    mov rax, qword[rcx]
    ret


__atomic_dec8:
    lock dec byte[rcx]
    mov  al, byte[rcx]
    ret

__atomic_dec16:
    lock dec word[rcx]
    mov  ax, word[rcx]
    ret

__atomic_dec32:
    lock dec dword[rcx]
    mov eax, dword[rcx]
    ret

__atomic_dec64:
    lock dec qword[rcx]
    mov rax, qword[rcx]
    ret


__atomic_cmpxchg8:
    mov          al        , dl
    lock cmpxchg byte [rcx], r8b
    ret

__atomic_cmpxchg16:
    mov          ax        , dx
    lock cmpxchg word [rcx], r8w
    ret

__atomic_cmpxchg32:
    mov          eax       , edx
    lock cmpxchg dword[rcx], r8d
    ret

__atomic_cmpxchg64:
    mov          rax       , rdx
    lock cmpxchg qword[rcx], r8
    ret