#include<iostream>
using namespace std;
int main()
{
	int v[3] = { 1,2,3 };
	int n = 3;
	_asm {
		lea eax, v
		xor ecx, ecx
		mov esi, n
		_loop :
		cmp ecx, esi
			jge_endloop
			mov ebx, ecx
			inc ebx
			mov[eax + 4 * ecx], ebx
			jmp_loop
			_endloop :
	}

	_asm
	{ 
		 lea eax,a
		 mov esi, 0
		  mov edi, 0
	_loop1:
		     cmp esi,n
				 je endloop
		    _loop2:
			 cmp edi, m
				 je endloop1;
			     mov ecx, esi
				add ecx, edi
			    mov eax, m
			    mul esi
			    add eax, edi
				shl eax,2
				mov [edx+ecx],eax
				add edi,1
				jmp_loop2
				end loop2:
				add esi,1
				jmp_loop1
				endloop1

    

	}
}
