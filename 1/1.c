#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	int a[1000], n;	// количество чисел до 1000, программа должна считать из файла целые числа типа int
	
	FILE *file = fopen("input.txt", "r");	
	if (file == NULL) {	// если ошибка - вывожу сообщение об ошибки
		printf("Can't open file input.txt\n");	
		getchar();

		return 0;	
	}

	n = 0;	// количество чисел 
	while (!feof(file)) {	//продолжаем пока файл не закончится
		if (fscanf(f, "%d", &a[n]) == 1) {	// условие, что число считано
			n++;	
		}
	}
	fclose(file);	
	
	_asm {  // ассемблерная вставка. Сортировка по возрастанию - пузырьковая сортировка
	lea esi,a	// адрес начала массива
	mov ebx,n	// количество считанноых в массив чисел
	cmp ebx,1	// если чисел не больше 1, то пропускаем сортировку
	jle skip	

// esi - указывает на массив (который нужно отсортировать)
// ebx - количество элементов массива

sort:	xor edx, edx		// flag = 0
	mov edi, esi		// начало массива
	lea ecx, [ebx-1]	// eсх = ebx-1(будем проводить n-1 сравниваний)
s1:	mov eax, [edi]		// mas[n]
	cmp eax, [edi+4]	// mas[n] < mas[n+1]
	jng s2
	xchg eax, [edi+4]	// если нет
	mov [edi],eax		// то обмениваем mas[n] и mas[n+1]
	mov edx, 1		// flag=1, то переходим к 
s2:	add edi,4		// переходим к следующему элементу массива
	loop s1			// сравниваем все элементы в данном проходе
	test edx, edx		//flag=0?
	jnz sort		// если нет, то продолжаем сортировку
skip:
	}

	//Записать полученный набор в файл. 
	file = fopen("outut.txt", "w");	//создать файл
	for (int i = 0; i < n; i++) {
		fprintf(f, "%d\n", a[i]);	//запись в файл
		printf("%d\n", a[i]);		// и вывод на экран
	}

	fclose(f);	//закрыть файл
	getchar();

	return 0;
}