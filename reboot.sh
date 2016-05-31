#!/usr/bin/expect
#log_user 0
spawn ssh 20.1.1.51
#send "BF\n"
#expect "password :"
#send "BF\n"
#expect "rkscli:"
send "rkscli\n"
sleep 1
send "fw set proto tftp\n"
sleep 1
expect "rkscli:"
send "fw set control ap-11n-scorpion-wsg/rcks_fw.bl7\n"
sleep 1
expect "rkscli:"
send "fw set host 172.19.150.22\n"
sleep 1
expect "rkscli:"
send "fw update\n"
sleep 340
expect "rkscli:"
send "reboot\n"
sleep 1
expect "OK"
