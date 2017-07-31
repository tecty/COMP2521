i=1


for (( mod = 0; mod < 1; mod++ )); do
    #every mod test 100 times


    # sort for each mod and record
    while [ $i -le 100 ]
    do
        # generate the data for each time of sort
        if [[ $mod==0 ]]; then
            #random + no duplicates
            seq 1000 | sort -R >source.tmp
        elif [[ $mod==1 ]]; then
            # sorted + no duplicates
            seq 1000 | sort -n >source.tmp
        elif [[ $mod==2 ]]; then
            # reverse + no duplicates
            seq 1000 | sort -nr >source.tmp
        elif [[ $mod==3 ]]; then
            # random + has duplicates
            seq 1000 | sort -nr >source.tmp
        elif [[ $mod==4 ]]; then
            # sorted + has duplicates
            seq 1000 | sort -nr >source.tmp
        elif [[ $mod==5 ]]; then
            # reverse + has duplicates
            seq 1000 | sort -nr >source.tmp
        fi

        # runing the sort
        (time sort -n) < source.tmp 2>sys.tmp > /dev/null
        grep real sys.tmp | cut -f2 >> sys_all.tmp
        (time ./usel) < source.tmp 2>user.tmp > /dev/null
        grep real user.tmp | cut -f2 >> user_all.tmp
        i=`expr $i + 1`
    done



    # # write the data into files
    # if [[ mod==0 ]]; then
    #     #random + no duplicates
    # elif [[ mod==1 ]]; then
    #     # sorted + no duplicates
    # elif [[ mod== 2 ]]; then
    #     # reverse + no duplicates
    # elif [[ mod==3 ]]; then
    #     # random + has duplicates
    # elif [[ mod==4 ]]; then
    #     # sorted + has duplicates
    # elif [[ mod==5 ]]; then
    #     # reverse + has duplicates
    # fi

    # delete the file
    # rm -rf *.tmp

done
