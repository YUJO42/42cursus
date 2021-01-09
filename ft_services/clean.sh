echo "metalLB manifest delete"
kubectl delete -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml

kubectl delete services --all
kubectl delete deploy --all
# kubectl delete persistentvolume --all
kubectl delete configmap --all
kubectl delete rs --all
kubectl delete po --all
