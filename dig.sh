echo "Enter the number: "
read num
while [ $num -gt 0 ]
do
n=$(expr $num / 10)
mod= $(expr $num - $n \* 10)
num= $(expr $num / 10)
sum= $(expr $mod + $num)
echo "$sum"
done

