echo "enter the base"
read b
echo "enter the power"
read p
for (( i=1 , r=$b ; i<p ; i++ ))
do 
$r=$((expr $r \* $b))
done
echo $r 
