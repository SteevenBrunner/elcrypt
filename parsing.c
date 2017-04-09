/*
** parsing.c for parsing in /home/brunne_s/rendu/elcrypt
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Sat Mar 14 18:04:20 2015 Steeven Brunner
** Last update Sun Mar 15 00:16:55 2015 Steeven Brunner
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "elcrypt.h"

void            error(char *a)
{
  printf("%s\n", a);
  exit(0);
}

int     parsing_three(int ac, char **av, t_args *crypt, int i)
{
  if (strcmp(av[i], "-k") == 0)
    {
      if (i + 1 < ac)
        {
          if (crypt->key == NULL)
            {
              if ((crypt->key = malloc(sizeof(char) * strlen(av[i + 1]))) == NULL)
                error("Malloc error");
              crypt->key = strcpy(crypt->key, av[i + 1]);
            }
          else
            error("the key is not 56 bit long or was already set");
          i++;
          return (i);
        }
      else
        error("The arguments are invalid or not enough");
    }
  else
    error("The arguments provided are false or not enough");
  return (i);
}

int     parsing_two(int ac, char **av, t_args *crypt, int i)
{
  if (strcmp(av[i], "-f") == 0)
    {
      if (i + 1 < ac)
        {
          if (crypt->fd_read != 1 ||
              (crypt->fd_read = open(av[i + 1], O_RDONLY)) == -1)
            error("Cannot open file, or argument was already given");
          return (i + 1);
        }
      error("The arguments are invalid or not enough");
    }
  else if (strcmp(av[i], "-o") == 0)
    {
      if (i + 1 < ac)
        {
          if (crypt->fd_write != 1 ||
              (crypt->fd_read = open(av[i + 1], O_RDWR | O_CREAT |
                                     O_APPEND, 00644)) == -1)
            error("Cannot open file, or argument was already given");
          return (i + 1);
        }
      error("The arguments are invalid or not enough");
    }
  i = parsing_3(ac, av, crypt, i);
  return (i);
}

void    parsing(int ac, char **av, t_args *crypt)
{
  int   i;

  i = 1;
  while (i != ac)
    {
      if (strcmp(av[i], "-d") == 0)
        {
          if (crypt->mode != '?')
            error("The encryption or decryption was already specified");
          crypt->mode = 'd';
        }
      else if (strcmp(av[i], "-e") == 0)
        {
          if (crypt->mode != '?')
            error("The encryption or decryption was already specified");
          crypt->mode = 'e';
        }
      else
        i = parsing_2(ac, av, crypt, i);
      i++;
    }
}

void    init_struct(t_args *crypt)
{
  crypt->mode = '?';
  crypt->fd_read = 1;
  crypt->fd_write = 1;
  crypt->key = NULL;
}
