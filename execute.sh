#!/bin/bash

declare -a programnames;
var=("date" "df" "dir" "dmesg" "echo" "domainname" "ed abc.txt" "cat abc.txt" "chmod 0777 abc.txt" "egrep abc abc.txt" 
    "false" "findmnt" "grep abc abc.txt" "hostname" "less abc.txt" "lessecho abcdefg" "ln -l abc.txt file.txt" "loginctl" "ls" "lsblk"

     "lsmod" "ps" "netstat" "mkdir test1" "mktemp" "more abc.txt" "mount" "mv abc.txt xyz.txt" "nisdomainname" "ntfsck" 
     "ping -c 3 8.8.8.8" "pwd" "red" "rm remove_file" "rmdir test1" "sleep 3" "ss" "stty" "sync" "touch abc.txt" 
     "true" "uname" "which gdb" "gdb" "apt-get install update" "awk \"abc\" abc.txt" "basename" "bc abc.txt" "bitmap" "calendar" 
     "cal" "cancel" "catman" "cc.main.c" "checkbox-gui" "cheese" "cksum abc.txt" "clear" "ciptool show" "corelist -v" 
     "cpan" "cpp main.c" "lnstat -d" "curl https://github.com/Sripradha-karkala/FuzzTesting.git" "cut -b 3 abc.txt" "dc abc.txt" "dconf list /home/osboxes/" "ddate" "diff abc.txt xyz.txt" "dig"
     "dircolors" "dirname /usr/bin" "dirsplit test" "dm-tool --version" "du" "eog" "eqn" "evince mozilla.pdf" "factor 32" "fallocate -l 3 abc.txt" 
     "file abc.txt" "find" "firefox" "fmt xyz.txt" "fold xyz.txt" "free" "ftp" "gcc main.c" "gcore 13717" "git add ../FuzzTesting/main.c" 
     "gs main.out" "head xyz.txt" "hexdump xyz.txt" "host google.com" "hostid" "hostnamectl" "infocmp" "ionice" "ifconfig" "last" 
     "less xyz.txt" "man man" "mandb" "pstree" "printf \"great stuff\"" "printenv" "whoami" "wish" "who" "wget https://github.com/Sripradha-karkala/FuzzTesting.git" 
     "whereis gdb" "whatis gdb" "wc xyz.txt" "vmstat" "vi abc.txt" "vim abc.txt" "uptime" "gedit" "sort xyz.txt" "ssh-keygen" 
     "stat xyz.txt" "telnet 127.0.0.1" "nm" "traceroute google.com" "tracepath 127.0.0.1" "tty" "truncate --size 3 xyz.txt" "sudo"  )
for i in "${var[@]}" 
do
		echo "Executing program" "$i"
		LD_PRELOAD=/home/osboxes/OS_Project/my_lib.so  $i &> logs/output_"$i".out
done
#LD_PRELOAD=/home/osboxes/OS_Project/my_lib.so ls
