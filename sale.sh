echo "Enter the salary:"
read s
if [ $s -lt 0 ]
then
echo "ERROR!!"
elif [ $s -ge 2000 ]
then
sal=$(expr $s - $s \* 15 / 100)
echo "The Sale: $sal"
elif [ $s -lt 2000 ]
then
if [ $s -ge 1500 ]
then
sal=$(expr $s - $s \* 10 / 100)
echo "The Sale: $sal"
else
echo "No Tax"
fi
else
echo "ERROR!!"
fi
