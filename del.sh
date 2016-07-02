#!/bin/bash
 function Diff()
 {
   case $2 in 
	   hours|hour):
		ans=$[$1*60*60];;
	   minutes|minute):
		ans=$[$1*60];;
	   seconds|second):
		ans=$1;;
	   weeks|week):
		ans=$[$1*604800];;
	   *):
		echo 0;;
   esac
   if [ $ans -lt $3 ] 
   then echo 0
   else echo 1
   fi
 }
while getopts ":t:" opt
do
        case $opt in
                t ) mine=$OPTARG;;
                ? ) echo "error args"
                    exit 1;;
        esac
done
#echo $mine
docker_ps=`docker ps -a | awk  '{print $4","$5","$6","$1}'`;
i=0
for data in ${docker_ps}
do  
    ((i++))
    if [ $i -eq 1 ] 
    then 
    continue 
    fi
    arr=(${data//,/ })    
    if [ ${arr[0]} = "About" ]
    then 
    result=$(Diff ${arr[1]} ${arr[2]} $mine)
    else
    result=$(Diff ${arr[0]} ${arr[1]} $mine)
    fi
    if [ 1 -eq $result ]
    then
    docker_rm=`docker rm -f ${arr[3]}`
    echo 'removing container ID:'+${arr[3]}
    else
    echo 'no available containers'
    fi 
done  

