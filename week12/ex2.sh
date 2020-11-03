gcc ex2.c -o my_tee

cat /proc/cpuinfo | ./my_tee ex2.txt
cat /proc/cpuinfo | ./my_tee -a ex2.txt

rm my_tee