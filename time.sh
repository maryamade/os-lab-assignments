echo "Enter The number: "
read n
if [ $n -lt 0 ]
then
echo "ERROR!!"
elif [ $n -eq 0 ]
then
echo "00:00:00"
elif [ $n -gt 3600 ]
then
h=$(expr $n / 3600)
n1=$(expr $h \* 3600)
n2=$(expr $n - $n1)
m=$(expr $n2 / 60)
n4=$(expr $m \* 60)
n3=$(expr $n2 - $n4)
s=$(expr $n3 / 60)
echo "$h : $m : $s"
elif [ $n -eq 3600 ]
then
echo "01:00:00"
elif [ $n -lt 3600 ]
then
m=$(expr $n / 60)
n2=$(expr $m \* 60)
n1=$(expr $n - $n2)
s=$(expr $n1 / 60)
echo "00 : $m : $s"
else
echo "ERROR!!"
fi                                                                                                                                                                                     
