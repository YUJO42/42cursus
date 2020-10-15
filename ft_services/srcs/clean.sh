# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    clean.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 13:14:47 by yujo              #+#    #+#              #
#    Updated: 2020/09/26 17:48:31 by yujo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo "metalLB manifest delete"
kubectl delete -f https://raw.githubsercontent.com/metallb/v0.9.3/manifest/namespace.yaml