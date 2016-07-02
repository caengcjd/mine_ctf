while getopts ":t:" opt
do
        case $opt in
                t ) mine=$OPTARG;;
                ? ) echo "error args"
                    exit 1;;
        esac
done
#echo $mine
docker_ps=`docker inspect --format='{{.State.StartedAt}},{{.Id}}' \`docker ps -a -q\` | awk  '{print  $1,$2}'`;
echo ${docker_ps}
for data in ${docker_ps}
do  
    arr=(${data//,/ })   
    #echo $data
    echo $arr
    #start_time="${arr:0:10} ${arr:11:8}"
    start_time=$arr
    #$echo 'start_time:'$start_time
    start_time=`date -d "$start_time" +%s`
    echo "start_time:$start_time"
    echo 'time_stamp:'$((`date +%s`-$start_time))
    if [ $((`date +%s`-$start_time)) -ge $mine ]
    then
    docker_rm=`docker rm -f ${arr[1]}`
    echo 'removing container ID:'+${arr[1]}
    else
    echo 'no available containers'
    fi 
done  

