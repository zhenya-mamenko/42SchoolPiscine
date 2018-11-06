# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_nicolas_bauer.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 19:48:56 by emamenko          #+#    #+#              #
#    Updated: 2018/11/01 20:53:37 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cat $1 | grep "^nicolas\tbauer\t" -i | tr "\t" "|" | sed -e "s/|[0-9]\{5\}\([-][0-9]\{4\}\)*|/|/g" | cut -d "|" -f 4