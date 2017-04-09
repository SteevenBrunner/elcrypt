/*
** get_nbr_base.c for get_nbr_base in /home/brunne_s/rendu/elcrypt
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Sat Mar 14 23:08:24 2015 Steeven Brunner
** Last update Sun Mar 15 01:07:50 2015 Steeven Brunner
*/

#include <stdio.h>
#include <sys/types.h>

int64_t		my_strlen(char *str)
{
  int64_t	i = 0;

  while (str[i] != '\0')
    i++;
  return (i);
}

int64_t     init(char *base, int64_t *nbr, int64_t *j, int64_t *i)
{
  int64_t   len;

  len = my_strlen(base);
  *nbr = 0;
  *j = 0;
  *i = 1;
  return (len);
}

int64_t     check_neg(char *s)
{
  int64_t   i;
  int64_t   cpt;

  i = 0;
  cpt = 0;
  while (s[i] && (s[i] < '0' || s[i] > '9'))
    {
      if (s[i] == '-')
        {
          cpt = cpt + 1;
        }
      i = i + 1;
    }
  if (cpt % 2 == 0)
    return (1);
  return (-1);
}

int64_t     check_base(char *base, int64_t n)
{
  int64_t   i;

  n = 0;
  while (base[n])
    {
      i = 0;
      while (base[i])
        {
          if (i != n)
            {
              if (base[n] == base[i])
                {
                  return (-1);
                }
            }
          i = i + 1;
        }
      n = n + 1;
    }
  return (0);
}

int64_t     my_getnbr_base(char *str, char *base)
{
  int64_t   nbr;
  int64_t   len;
  int64_t   j;
  int64_t   k;
  int64_t   i;

  len = init(base, &nbr, &j, &i);
  i = check_neg(str);
  if (check_base(base, 0) == -1)
    {
      return (0);
    }
  while (str[j])
    {
      k = 0;
      while (k < len && base[k] != str[j])
        k = k + 1;
      if (base[k] == str[j])
        nbr = nbr * len + k;
      else
        if ((str[j] != '-' && str[j] != '+'))
          return (0);
      j = j + 1;
    }
  printf("%lld\n", nbr * i);
  return (nbr * i);
}

void	convert_to_binary(int64_t key)
{
  int	i = 64;
  int	bit;

  printf("\n");
  while (--i >= 0)
    {
      bit = (key >> i) & 1;
      printf("%d", bit);
      if (i % 8 == 0)
	printf(" ");
    }
  printf("\n\n");
}

int64_t		bit_mask(int64_t key)
{
  int64_t	t;

  t = 0;
  t = t | (key & 0x00000000000000FE) >> 1;
  t = t | (key & 0x000000000000FE00) >> 2;
  t = t | (key & 0x0000000000FE0000) >> 3;
  t = t | (key & 0x00000000FE000000) >> 4;
  t = t | (key & 0x000000FE00000000) >> 5;
  t = t | (key & 0x0000FE0000000000) >> 6;
  t = t | (key & 0x00FE000000000000) >> 7;
  t = t | (key & 0xFE00000000000000) >> 8;
  return (t);
}

int64_t		rotate_keys(int64_t key, int n)
{
  int64_t	t;
  int		i;

  t = 0;
  i = 0;
  //  key = key % 56;
  while (i < n) 
    {
      t = key << 4;
      i++;
    }
  return (t);
}

int	main()
{
  int64_t	toto;
  
  convert_to_binary(my_getnbr_base("0123456789ABCDEF", "0123456789ABCDEF"));
  toto = bit_mask(my_getnbr_base("0123456789ABCDEF", "0123456789ABCDEF"));
  convert_to_binary(toto);
  toto = rotate_keys(my_getnbr_base("0123456789ABCDEF", "0123456789ABCDEF"), 1);
  convert_to_binary(toto);

}
