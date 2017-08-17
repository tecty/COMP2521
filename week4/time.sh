i=1
test_count=10

# print the promt
printf "Input\tInitial\t Has\tNumber\tAvg Time\tAvg Time\tAvg Time\n"
printf "size\tOrder\t Dup.\tof runs\tof sortA\tof sortB\tfor sort\n"

# control the input_size
#5000 10000 15000 20000 25000 30000 35000 40000 45000 50000 55000 60000 65000 70000 75000 80000 85000 90000
for input_size in  95000 100000
do

    for (( mod = 0; mod < 3; mod++ )); do
        #every mod test 100 times

        i=1
        # sort for each mod and record
        while [ $i -le $test_count ]
        do
            # generate the data for each time of sort
            if [[ mod -eq 0 ]]; then
                #random + no duplicates
                ./gen $input_size R >source.tmp
            elif [[ mod -eq 1 ]]; then
                # sorted + no duplicates
                ./gen $input_size A >source.tmp
            elif [[ mod -eq 2 ]]; then
                # reverse + no duplicates
                ./gen $input_size D >source.tmp
            #elif [[ mod -eq 3 ]]; then
                # random + has duplicates
            #    seq $input_size | sort -R >source.tmp
            #elif [[ mod -eq 4 ]]; then
                # sorted + has duplicates
            #    seq $input_size | sort -n >source.tmp
            #elif [[ mod -eq 5 ]]; then
                # reverse + has duplicates
            #    seq $input_size | sort -nr >source.tmp
            fi

            # runing the sort
            (time sort -n) < source.tmp 2>sys.tmp > /dev/null
            grep real sys.tmp | cut -f2 >> sys_all.tmp 
            (time ./sortA) < source.tmp 2>sortA.tmp > /dev/null
            grep real sortA.tmp | cut -f2 >> sortA_all.tmp  
            (time ./sortB) < source.tmp 2>sortB.tmp > /dev/null
            grep real sortB.tmp | cut -f2 >> sortB_all.tmp 
            i=`expr $i + 1`
        done

        # calculate the avg time for each method and records
        sortA=`./avg_time.sh sortA_all.tmp` 
        sortB=`./avg_time.sh sortB_all.tmp` 
        sys=`./avg_time.sh sys_all.tmp` 

        # #  clean the record files
        # rm -rf sys_all.tmp user_all.tmp

        # print the result in the file

        # write the data into files
        if [[ mod -eq 0 ]]; then
            #random + no duplicates
            printf "%d\trandom \t no\t" $input_size
        elif [[ mod -eq 1 ]]; then
            # sorted + no duplicates
            printf "%d\tsorted \t no\t" $input_size
        elif [[ mod -eq 2 ]]; then
            # reverse + no duplicates
            printf "%d\treverse\t no\t" $input_size
        elif [[ mod -eq 3 ]]; then
            # random + has duplicates
            printf "%d\trandom \t yes\t" $input_size
        elif [[ mod -eq 4 ]]; then
            # sorted + has duplicates
            printf "%d\tsorted \t yes\t" $input_size
        elif [[ mod -eq 5 ]]; then
            # reverse + has duplicates
            printf "%d\treverse\t yes\t" $input_size
        fi

        printf "%d\t%lf\t%lf\t%lf\t\n" $test_count $sortA $sortB $sys 
        # delete the file
        rm -rf *.tmp

    done

done
