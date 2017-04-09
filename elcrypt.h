/*
** elcrypt.h for elcrypt.h in /home/brunne_s/rendu/elcrypt
** 
** Made by Steeven Brunner
** Login   <brunne_s@epitech.net>
** 
** Started on  Sat Mar 14 11:07:48 2015 Steeven Brunner
** Last update Sat Mar 14 18:32:22 2015 Steeven Brunner
*/

#ifndef ELCRYPT_H_
# define ELCRYPT_H_

# define NB_ROUND 8

typedef struct	s_args
{
  char	*key;
  int	fd_read;
  int	fd_write;
  char	mode;
}		t_args;

void	parsing(int ac, char **av, t_args *crypt);
void	init_struct(t_args *crypt);

#endif /* !ELCRYPT_H_ */
