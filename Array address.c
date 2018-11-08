#include <stdio.h>
#include <stdlib.h>

void forward_forward1(int *a, int rows, int cols)
{
	int row = 0;
	/* Prints value at starting array addres*/
	for(row; row < rows; row++)
	{
		int col = 0;
		for(col; col < cols; col++)
		{
			/* Prints value at array address its pointing to and increments address by one */
			printf("%4d", *a);
			a++;
		}
		printf("\n");
	}
	printf("\n");
	
}

void forward_forward2(int (*a)[15], int rows, int cols)
{
	int row;
	for(row = 0; row < rows; row++)
	{
		int col = 0;
		for(col; col < cols; col++)
		{
			/* Prints value at array address position incrementing by row and column*/
			printf("%4d", *(*(a + row)+col));
		}
		printf("\n");
	}
	printf("\n");
}

void forward_backward1(int *a, int rows, int cols)
{
	int row = 0;
	for(row = 0; row < rows; row++)
	{
		/* Initialize column to end value to print right to left*/
		int col = cols - 1;
		/* Initialize a pointer value by adding row its on and adding total columns to start at far right column*/
		int* ptr = a + (row*cols) + col;
		for(col; col >= 0 ; col--)
		{
			printf("%4d", *ptr);
			ptr--;
		}
		printf("\n");
	}
	printf("\n");
}

void forward_backward2(int (*a)[15], int rows, int cols)
{
	int row = 0;
	for(row = 0; row < rows; row++)
	{
		/* Set column equal to total columns to start at farthest righ column*/
		int col = cols - 1;
		for(col; col >= 0; col--)
		{
			/* Prints last column while decreasing column value to print right to left*/
			printf("%4d", *(*(a + row)+ col));
		}
		printf("\n");
	}
	printf("\n");
}

void backward_forward1(int *a, int rows, int cols)
{
	/* Initialize row value to last row*/
	int row = rows - 1;
	for(row; row >= 0; row--)
	{
		int col = 0;
		/* Make a pointer equal to first value of last row to increment by one column*/
		int* ptr = a + (row*cols);
		for(col; col < cols; col++)
		{
			/* Prints rows bottow to top, left to right*/
			printf("%4d", *ptr);
			ptr++;
		}
		printf("\n");
	}
	printf("\n");
}
 
void backward_forward2(int (*a)[15], int rows, int cols)
{
	/* Row to equal last row*/
	int row = rows - 1;
	int col;
	for(row; row >= 0; row--)
	{
		col = 0;
		for(col; col < cols; col++)
		{
			/* Prints from last row position left to right while decreasing row value*/
			printf("%4d", *(*(a + row)+col));
		}
		printf("\n");
	}
	printf("\n");
}

void backward_backward1(int *a, int rows, int cols)
{
	/* Initialize to last row*/
	int row = rows - 1;
	for(row; row >= 0; row--)
	{
		/* Initialize to last column*/
		int col = cols - 1;
		/* Set pointer to last value of array while decreasing address by one*/
		int* ptr = a + (row*cols) + col;
		for(col; col >= 0; col--)
		{
			printf("%4d", *ptr);
			ptr--;
		}
		printf("\n");
	}
	printf("\n");
}

void backward_backward2(int (*a)[15], int rows, int cols)
{
	/* Initialize to last row*/
	int row = rows - 1;
	for(row; row >= 0; row--)
	{
		/* Initialize to last column of array*/
		int col = cols - 1;
		for(col; col >= 0; col--)
		{
			/* Prints last value of array while decreasing by one address position*/
			printf("%4d", *(*(a+row) + col));
		}
		printf("\n");
	}
	printf("\n");
}

void backward_backward3(int *a, int rows, int cols)
{ 
	/* Initialize array to copy values of in address passed as argument  */
	int b[rows*cols];
	int row;
	int col;
	int row2 = (rows*cols) - 1;
	/* Set counter to know when end or column is reached for new line */
	int counter = 1;
	/* Loop through array and copy to new array*/
	for(row = 0; row < cols*rows; row++)
	{
		b[row] = *a;
		a++;
	}
	/*Loop through and print each value of array*/
	for(row2; row2 >= 0; row2--)
	{
		printf("%4d", b[row2]);
		/* When counter reaches value of number of columns, it creates a new line*/
		if(counter % 15 == 0)
		{
			printf("\n");
		}
		counter++;
	}
	printf("\n");  
}

int main(void)
{
  int row, col, a[15][15];
  int num_rows = 15;
  int num_cols = 15;
  
  srand(6);
  for (row = 0; row < num_rows; row++)
  {
    for (col = 0; col < num_cols; col++)
    {
      int neg;
      a[row][col] = rand() % 100;
      neg = rand() % 2;
      if (neg == 1)
        a[row][col] = -a[row][col];
    }
  }
  
  forward_forward1(&a[0][0], num_rows, num_cols);
  forward_forward2(a, num_rows, num_cols);
  forward_backward1(&a[0][0], num_rows, num_cols);
  forward_backward2(a, num_rows, num_cols); 
  backward_forward1(&a[0][0], num_rows, num_cols);
  backward_forward2(a, num_rows, num_cols); 
  backward_backward1(&a[0][0], num_rows, num_cols);  
  backward_backward2(a, num_rows, num_cols); 
  backward_backward3(&a[0][0], num_rows, num_cols);
  
}
