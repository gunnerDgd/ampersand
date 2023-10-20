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
    lock add byte[rdi], sil
    mov  al, byte[rdi]
    ret

__atomic_add16:
    lock add word[rdi], si
    mov  ax, word[rdi]
    ret

__atomic_add32:
    lock add dword[rdi], esi
    mov eax, dword[rdi]
    ret

__atomic_add64:
    lock add  qword[rdi], rsi
    mov  rax, qword[rdi]
    ret


__atomic_sub8:
    lock sub byte[rdi], sil
    mov  al, byte[rdi]
    ret

__atomic_sub16:
    lock sub word[rdi], si
    mov  ax, word[rdi]
    ret

__atomic_sub32:
    lock sub dword[rdi], esi
    mov eax, dword[rdi]
    ret

__atomic_sub64:
    lock sub qword[rdi], rsi
    mov rax, qword[rdi]
    ret


__atomic_inc8:
    lock inc byte[rdi]
    mov  al, byte[rdi]
    ret

__atomic_inc16:
    lock inc word[rdi]
    mov  ax, word[rdi]
    ret

__atomic_inc32:
    lock inc dword[rdi]
    mov eax, dword[rdi]
    ret

__atomic_inc64:
    lock inc qword[rdi]
    mov rax, qword[rdi]
    ret


__atomic_dec8:
    lock dec byte[rdi]
    mov  al, byte[rdi]
    ret

__atomic_dec16:
    lock dec word[rdi]
    mov  ax, word[rdi]
    ret

__atomic_dec32:
    lock dec dword[rdi]
    mov eax, dword[rdi]
    ret

__atomic_dec64:
    lock dec qword[rdi]
    mov rax, qword[rdi]
    ret


__atomic_cmpxchg8:
    mov          al        , sil
    lock cmpxchg byte [rdi], dl
    ret

__atomic_cmpxchg16:
    mov          ax        , si
    lock cmpxchg word [rdi], dx
    ret

__atomic_cmpxchg32:
    mov          eax       , esi
    lock cmpxchg dword[rdi], edx
    ret

__atomic_cmpxchg64:
    mov          rax       , rsi
    lock cmpxchg qword[rdi], rdx
    ret