echo "Enter The number:"
read n
for (( i=2; i<$(expr $n / 2); i++ ))
do
r=$(expr $n / $i)
rr=$(expr $n - $r \* $i)
if [ $rr -eq 0 ]
then
echo "$n is not a prime number."
exit 0
fi
done
echo "$n is a prime number"
