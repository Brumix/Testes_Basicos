#include <stdio.h>
#include <stdlib.h>

typedef struct person{
  char *name;
  int age;

}Person;

/** 
 * valgrind
 * (detector de memoria)
 * começar a usar sempre que usar malloc ou calloc,etc, 
 * optimo para deterção de más alocações de memoria bem com falhas na libertação dessas mesmas memorias)
 **/

void print_array_alocado(void);
int duplica(int a);
void print_lista_nomes(void);

void main(int argc, char**argv)
{


  print_array_alocado();
  print_lista_nomes();
  Person *a= malloc(sizeof(Person)) ;
  
  a->name=malloc(sizeof(char)*10);
  a->name="Elena";
  a->age=20;
  printf("%s  %d\n",a->name,a->age);
  free(a);


}


void print_array_alocado(void)
{
  signed int *i = malloc(sizeof(int) * 10);
  signed int x = 0;

  while (x < 10)
  {
    i[x] = x;
    printf("%i  ", i[x]);
    x++;
  }
  printf("\nterminei\n");
  printf("master\n");
  free(i);
}

int duplica(int a)
{
  return 2 * a;
}

void print_lista_nomes(void)
{
  signed int x = 0, y = 0;
  signed char t[3][6] = {"teste", "ana", "jose"};
  while (1)
  {
    printf("%c", t[y][x]);
    x++;
    if (t[y][x] == '\0')
    {
      printf("\n");
      y++;
      x = 0;
      if (t[y][x] == '\0')
      {
        break;
      }
    }
  }
}
