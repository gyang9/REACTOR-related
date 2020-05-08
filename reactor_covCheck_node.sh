#! /usr/bin/env bash

:<<"END"
echo ${PROCESS}
RUNNUMBER=${PROCESS}
echo $RUNNUMBER


USERDIR="/pnfs/dune/persistent/users/wbae/CAF2"
CP="ifdh cp"

source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh

setup genie v2_12_10c -q e15:prof
setup genie_xsec v2_12_10 -q DefaultPlusValenciaMEC
setup genie_phyopt v2_12_10 -q dkcharmtau
setup dk2nu v01_05_01b -q e15:prof
setup ifdhc

${CP} ${USERDIR}/app2.tar.gz app2.tar.gz

tar -xzf app2.tar.gz
mv app2/* .

chmod +x app_noloop_1free_log
END

RUNNUMBER=0
for((j=1; j<=5; j++))
do
	for((i=1; i<=5; i++))
	do

	
		dm=`echo $((  ${i}*10  ))` #변수 정의 할 때 = 사이에 띄어 쓰기 있으면 안 됨
		ds=`echo $((  ${j}*10  ))`

		#RUNNUMBER=`echo $((RUNNUMBER+1))`
	
		echo $(( ${dm} )) ", " $(( ${ds} ))
 		./app_noloop_5free_log_sys5 `echo $(( ${dm} ))` `echo $(( ${ds} ))` NEOSPROSPECT

		mv outputFigs3.root outputFigs3_${dm}_${ds}.root	
	done
done




