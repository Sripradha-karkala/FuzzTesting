#!/bin/bash

declare -a programnames;
var=("date" "df" "dir" "dmesg" "echo" "domainname" "ed abc.txt" "cat abc.txt" "chmod 0777 abc.txt" "egrep abc abc.txt" 
     "false" "findmnt" "grep abc abc.txt" "hostname" "less abc.txt" "lessecho abcdefg" "ln -l abc.txt file.txt" "loginctl" "ls" 
     "lsblk" "lsmod" "ps" "netstat" "mkdir test1" "mktemp" "more abc.txt" "mount" "mv abc.txt xyz.txt" "nisdomainname" 
     "ntfsck" "ping -c 3 8.8.8.8" "pwd" "red" "rm remove_file" "rmdir test1" "sleep 3" "ss" "stty" "sync" "touch abc.txt" 
     "true" "uname" "which gdb" )
for i in "${var[@]}" 
do
		echo "Executing program" "$i"
		LD_PRELOAD=/home/osboxes/OS_Project/my_lib.so  $i > file.out
done
#LD_PRELOAD=/home/osboxes/OS_Project/my_lib.so ls
