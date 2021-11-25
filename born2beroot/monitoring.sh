arch=$(uname -a)
p_cpu=$(lscpu | grep 'Socket(s)' | tail -c2)
v_cpu=$(lscpu | awk '$1 == "CPU(s):" {print $2}')
ram=$(free -m | awk '$1 == "Mem:" {printf "%s/%sMB (%.2f%%)\n", $3, $2, $3/$2*100}')
disk=$(df -m | grep 'root' | awk '{printf "%s/%sMB (%.2f%%)\n", $3, $2, $3/$2*100}')
cpu_usage=$(top -n1 | grep '%Cpu(s):' | awk '{printf "%.2f%%", 100-$8}')
last_boot=$(who -b | awk '{printf "%s %s\n", $3, $4}')
count_lvm=$(lsblk | grep 'lvm' | wc -l)
lvm=$(if [ $count_lvm = 0 ] ; then echo No ; else echo Yes ; fi)
tcp=$(cat /proc/net/sockstat | awk '$1 == "TCP:" {print $3}')
users=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link | awk '$1 == "link/ether" {print $2}')
sudo_cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	# Architecture : $arch
	# CPU physical : $p_cpu
	# vCPU : $v_cpu
	# Memory usage : $ram
	# Disk usage : $disk
	# CPU load : $cpu_usage
	# LVM use : $lvm
	# Connexions TCP : $tcp ESTABLISHED
	# User log : $users
	# Network : IP $ip ($mac)
	# Sudo : $sudo_cmds commands"
