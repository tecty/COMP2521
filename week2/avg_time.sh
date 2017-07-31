#  calculat the average time of system method
#  minutes part
cut -d'm' -f1 "$1" > foo.tmp
#  calculate the sum of minutes
min_sum=0
count=0
while read line
do
    min_sum=$(echo "$sum+$line" | bc -l)
    count++
done < foo.tmp

# calculate the sum of sec
cut -d'm' -f2 "$1" | tr -d 's'> foo.tmp
sec_sum=0
while read line
do
    sec_sum=$(echo "$sum+$line" | bc -l)
done < foo.tmp


# calculate the total sum
echo min_sum
echo sec_sum
