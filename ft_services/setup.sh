# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 21:15:59 by yujo              #+#    #+#              #
#    Updated: 2021/01/06 21:16:00 by yujo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINIKUBE_IP=${minikube ip}
printf "MINIKUBE_IP: ${MINIKUBE_IP}\n"
sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/metallb/config_format.yaml > ./srcs/metallb/config.yaml
kubectl create -f ./srcs/metallb/config.yaml