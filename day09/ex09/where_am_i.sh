# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    where_am_i.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/02 03:48:40 by emamenko          #+#    #+#              #
#    Updated: 2018/11/02 04:12:34 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifconfig | grep "inet " | wc -l | bc | while read COUNT; do
	if [ $COUNT -eq 0 ]; then
		echo "I am lost!"
	elif [ $COUNT -gt 0 ]; then
		ifconfig | grep "inet " | sed "s/.*inet //g" | cut -d " " -f 1
	fi
done;
