#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int a[1000], n;	// ���������� ����� �� 1000, ��������� ������ ������� �� ����� ����� ����� ���� int
	
	FILE *file = fopen("input.txt", "r");	
	if (file == NULL) {	// ���� ������ - ������ ��������� �� ������
		printf("Can't open file input.txt\n");	
		getchar();

		return 0;	
	}

	n = 0;	// ���������� ����� 
	while (!feof(file)) {	//���������� ���� ���� �� ����������
		if (fscanf(f, "%d", &a[n]) == 1) {	// �������, ��� ����� �������
			n++;	
		}
	}
	fclose(file);	
	
	_asm {  // ������������ �������. ���������� �� ����������� - ����������� ����������
	lea esi,a	// ����� ������ �������
	mov ebx,n	// ���������� ���������� � ������ �����
	cmp ebx,1	// ���� ����� �� ������ 1, �� ���������� ����������
	jle skip	

// esi - ��������� �� ������ (������� ����� �������������)
// ebx - ���������� ��������� �������

sort:	xor edx, edx		// flag = 0
	mov edi, esi		// ������ �������
	lea ecx, [ebx-1]	// e�� = ebx-1(����� ��������� n-1 �����������)
s1:	mov eax, [edi]		// mas[n]
	cmp eax, [edi+4]	// mas[n] < mas[n+1]
	jng s2
	xchg eax, [edi+4]	// ���� ���
	mov [edi],eax		// �� ���������� mas[n] � mas[n+1]
	mov edx, 1		// flag=1, �� ��������� � 
s2:	add edi,4		// ��������� � ���������� �������� �������
	loop s1			// ���������� ��� �������� � ������ �������
	test edx, edx		//flag=0?
	jnz sort		// ���� ���, �� ���������� ����������
skip:
	}

	//�������� ���������� ����� � ����. 
	file = fopen("outut.txt", "w");	//������� ����
	for (int i = 0; i < n; i++) {
		fprintf(f, "%d\n", a[i]);	//������ � ����
		printf("%d\n", a[i]);		// � ����� �� �����
	}

	fclose(f);	//������� ����
	getchar();

	return 0;
}