/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:03:55 by emamenko          #+#    #+#             */
/*   Updated: 2018/11/09 15:20:44 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct		s_list
{
	struct s_list	*next;
	t_btree			*item;
	int				level;
	int				is_first;
}					t_list;

t_btree				*btree_create_node(void *item);

#endif
