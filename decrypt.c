/*
** decrypt.c for decrypt in /home/brunne_s/rendu/elcrypt
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Sat Mar 14 18:19:07 2015 Steeven Brunner
** Last update Sat Mar 14 19:20:52 2015 Steeven Brunner
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "elcrypt.h"

void		getkey(t_args *crypt)
{
  int64_t	new_key;

  new_key = (key & 0xFE) >> 1;
}

