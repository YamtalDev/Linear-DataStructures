/******************************************************************************

    writer: Tal Aharon

    reviewer: Ravit Yehud

    📅️ : 15.03.2023

******************************************************************************/
#include <stdio.h>     /* printf, puts    */
#include <sys/types.h> /* ssize_t, size_t */

#include "circular_buffer.h"

/*****************************************************************************/
int main(void)
{
	size_t bytes = 0;
	int num1 = 2024;
	int num2 = 0;
	int *src = &num1;
	int *dest = &num2;

	cbuff_t *cbuff = CircularBufferCreate(5);

	printf("\nBuffer capacity after creation : %lu\n",\
	CircularBufferBufsiz(cbuff));
	printf("\nBuffer free space after creation : %lu\n",\
	CircularBufferFreeSpace(cbuff));
	printf("\nBuffer is empty after creation : %d\n",\
	CircularBufferIsEmpty(cbuff));

	bytes = CircularBufferWrite(cbuff, src, 5);

	printf("\nWritten bytes to buffer : %lu\n", bytes);

	printf("\nBuffer free space after writing : %lu\n",\
	CircularBufferFreeSpace(cbuff));

	printf("\nBuffer is empty after writing : %d\n",\
	CircularBufferIsEmpty(cbuff));

	bytes = CircularBufferRead(cbuff, dest, 1);

	printf("\nWritten bytes to buffer : %lu\n", bytes);

	printf("\nBuffer free space after reading : %lu\n",\
	CircularBufferFreeSpace(cbuff));

	printf("\nAfter reading destination = %d\n", num2);

	printf("\nBuffer is empty after reading : %d\n",\
	CircularBufferIsEmpty(cbuff));

	CircularBufferDestroy(cbuff);
	return 0;
}
