##EVEN ODD
# echo "Enter a number:"
# read n
# a=0
# rem=$(($n%2))
# if [ $rem -eq $a ];
# then
#     echo "Even"
# else
#     echo "ODD"
# fi        

# function entry()
# {
#     echo "Enter the username:"
#     read u
#     echo "Enter the password:"
#     read p
# }

# entry

# if [[ $u == "Arti" && $p == "aaaa" ]];
# then
#     echo "Valid"
# else
#     echo "Invalid"
# fi     

# echo enter two number:
# read a b
# echo Addition of two number: `expr $a + $b

# echo enter two number:
# read a b
# echo Addition of two number: $((a+b))  

# echo enter a number:
# read a
# case $a in 
# 1) echo "suraj" ;;
# *) echo "Invalid";;
# esac  

# echo enter two number:
# read a b
# if [ $a -gt $b ] 
# then echo $a is greater than $b 
# else echo $b is greater than $a
# fi

# echo enter a number:
# read a
# if [[ $a%2 -eq 0 && $a -gt 10 ]];
# then echo $a greater even
# else echo $a less 
# fi

# sum=0
# echo Enter the total numbers:
# read n
# echo Enter numbers:
# while [ $n -gt 0 ]
# do 
# read a
# ((sum+=a))
# ((n--)) 
# done
# echo Total: $sum

# sum=()
# echo Enter the total numbers:
# read n
# i=0
# echo Enter numbers:
# while [ $i -lt $n ]
# do 
# read sum[i]
# ((i++)) 
# done
# echo Arrays:${sum[*]}

# sum=()
# echo Enter numbers:
# read sum
# echo Arrays:${sum[*]}

# sum=()
# echo Enter the total numbers:
# read n
# echo Enter numbers:
# for((i=0;i<n;i++))
# do 
# read sum[i] 
# done
# echo Arrays:${sum[*]}

# read n
# for((i=2;i<=n;i++))
# do 
#    count=true
#    for((j=2;j<i;j++))
#     do
#         if [ $((i%j)) -eq 0 ];
#         then 
#            count=false
#            break
#         fi   
#     done
#     if [ $count == true ];
#     then   
#       echo $i
#     fi  
# done

check()
{
    username=$1
    pass=$2
    if [[ $username == "suraj" && $pass == "suraj"]]
    then
     echo Match
    else
    echo Not match
    fi
}
check "suraj" "suraj"
check "suraj" "ssura"    
