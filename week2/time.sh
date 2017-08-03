i=1
test_count=233

# print the promt
printf "Input\tInitial\t Has\tNumber\tAvg Time\tAvg Time\n"
printf "size\tOrder\t Dup.\tof runs\tfor usel\tfor sort\n"

# control the input_size
for input_size in 5000 10000 25000 50000 100000
do

    for (( mod = 0; mod < 6; mod++ )); do
        #every mod test 100 times

        i=1
        # sort for each mod and record
        while [ $i -le $test_count ]
        do
            # generate the data for each time of sort
            if [[ mod -eq 0 ]]; then
                #random + no duplicates
                seq $input_size | sort -R >source.tmp
            elif [[ mod -eq 1 ]]; then
                # sorted + no duplicates
                seq $input_size | sort -n >source.tmp
            elif [[ mod -eq 2 ]]; then
                # reverse + no duplicates
                seq $input_size | sort -nr >source.tmp
            elif [[ mod -eq 3 ]]; then
                # random + has duplicates
                seq $input_size | sort -R >source.tmp
            elif [[ mod -eq 4 ]]; then
                # sorted + has duplicates
                seq $input_size | sort -n >source.tmp
            elif [[ mod -eq 5 ]]; then
                # reverse + has duplicates
                seq $input_size | sort -nr >source.tmp
            fi

            # runing the sort
            (time sort -n) < source.tmp 2>sys.tmp > /dev/null
            grep real sys.tmp | cut -f2 >> sys_all.tmp
            (time ./usel) < source.tmp 2>user.tmp > /dev/null
            grep real user.tmp | cut -f2 >> user_all.tmp
            i=`expr $i + 1`
        done

        # calculate the avg time for each method and records
        user=`./avg_time.sh user_all.tmp`
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

        printf "%d\t%lf\t%lf\t\n" $test_count $user $sys
        # delete the file
        rm -rf *.tmp

    done

done
