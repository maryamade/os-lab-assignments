echo "Enter two number: "
read n1 
read n2
if [ $n1 -gt 0 ] || [ $n2 -gt 0 ]
then
sum=$(expr $n1 + $n2)
avg=$(expr $sum / 2)
echo $avg
else
echo "error"
fi
