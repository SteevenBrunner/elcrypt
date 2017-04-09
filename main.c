/*
** main.c for main in /home/brunne_s/rendu/elcrypt
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Sat Mar 14 11:05:44 2015 Steeven Brunner
** Last update Sat Mar 14 18:19:33 2015 Steeven Brunner
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "elcrypt.h"

int		main(int ac, char **av)
{
  t_args	*crypt;

  if ((crypt = malloc(sizeof(t_args *))) == NULL)
    return (0);
  init_struct(crypt);
  if (ac < 6)
    {
      printf("Usage : ./elcrypt\n\t-d for decryption\n\t-e for encryption\n");
      printf("\t-f file to specify the source file\n\t-o file to write the ");
      printf("output in a file\n\t-k key to specify the key\n");
      return (0);
    }
  parsing(ac, av, crypt);
  decrypt();
  return (0);
}
