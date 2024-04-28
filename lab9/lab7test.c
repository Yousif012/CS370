int y,Z[100];


int main(void)
{
   write  "hello\n";
   write  "world\n";
   write 123;
   write "\n";
   write "enter a number ";
   read y;
   write "you entered: ";
   write y;
   write "\n";

   if(y == 3){
      write "y is 3\n";
   }

   if(y != 3){
      write "y is not 3\n";
   }

   if(y < 3){
      write "y is less than 3\n";
   }

   if(y <= 3){
      write "y is less than or equal to 3\n";
   }

   if(y > 3){
      write "y is bigger than 3\n";
   }

   if(y >= 3){
      write "y is bigger than or equal to 3\n";
   }


}
