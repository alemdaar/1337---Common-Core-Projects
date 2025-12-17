/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:58:08 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/01 22:50:03 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <stdlib.h>
# include <unistd.h>
# include "mandatory/header.h"

char		*get_next_line(int fd);
size_t		ft_strlen(char *str);
char		*ft_strdup_add(char *src, int add_bytes);
void		ft_strlcpy(char *dest, char *src, int add_bytes);
void		free_str(char **str);
int			ft_strchr(char *str, char c);
char		*rtn_line(char *buffer, int p);
void		push_f(t_stack **a, t_stack **b, char *inst);
void		swap_f(t_stack **a, t_stack **b, char *inst);
void		shift_f(t_stack **a, t_stack **b, char *inst);
void		action(t_stack **a, t_stack **b, char *inst);
void		free_stack(t_stack **a, t_stack **b);
int			valid_instruction(char *str);
int			operation(t_stack **a, t_stack **b);
void		pushh(char type, t_stack **a, t_stack **b);
void		swapp(char type, t_stack **a, t_stack **b);
void		shift_upp(t_stack **a, int times);
void		shift_downn(t_stack **head, int times);
t_extracter	*correct_nb_bonus(char **av, int ac);
int			calculate_nbs_bonus(int ac, char **av);
t_indexes	calculate_nbs2_bonus(t_indexes index, char **av);
int			spc_bonus(char c);
int			dgt_bonus(char c);
int			zaidnaqs_b(char c);
void		freestr_bonus(char **adata);
void		free_str2_b(char ***adata);
void		free_longlong_bonus(long long **adata);
void		free_result_b(t_extracter **adata);
void		free_node_bonus(t_stack **adata);
t_indexes	fill_str2_bonus(t_indexes index, t_extracter *result, char **av);
t_indexes	fill_str_loop_bonus(t_indexes index, char **av);
int			fill_str_bonus(t_extracter *result, int ac, char **av);
int			prepare_str_bonus(char **str, int count);
int			extract_nbs_bonus(t_extracter *result);
t_indexes	small_atoi_bonus(t_extracter *result, t_indexes index);
int			overflow_check_bonus(long long nb);
int			raqm_meawd_bonus(t_extracter *result);
t_stack		*make_stack_a_bonus(t_extracter *result);
t_stack		*ft_lstnew_bonus(int content);
t_stack		*ft_lstlast_bonus(t_stack *lst);
void		ft_lstadd_back_bonus(t_stack **lst, t_stack *new);
void		fill_index_bonus(t_stack *head, t_extracter *result);
void		swap_nbs_b(long long *a, long long *b);
void		store_index_bonus(t_extracter *result, t_stack *head);
t_indexes	handle_strflow_b(t_indexes index, t_extracter *result, char **av);

#endif
