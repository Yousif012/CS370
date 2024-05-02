// Simple program to test the compiler

int x[5];

int f(int x, int y)
{
   return x * y;
}

void main(void)
{
   int i;
   int A[20];
   int y[5];
   i = 2;

   write i;

   write "\n";

   i = f(i, 2);

   write i;

   write "\n";

   i = 0;
   while (i < 19)
   {
      A[i] = i + 1;
      i = i + 1;
   }
   A[19] = 0;

   write "The following should be 13\n";
   write A[A[A[10]]];
   write "\n";
   write "The following should be 3\n";
   write A[A[A[A[10 + 9]]]];
   write "\n";

   i = 0;
   while (i < 5)
   {
      write "enter Y ";
      read x[i];
      i = i + 1;
   }

   i = 0;

   while (i < 5)
   {
      write x[i] * x[i];
      write "\n";
      i = i + 1;
   }

   i = 0;
   while (i < 5)
   {
      write "enter X ";
      read y[i];
      i = i + 1;
   }

   i = 0;

   while (i < 5)
   {
      write y[i] * y[i];
      write "\n";
      i = i + 1;
   }
}
